import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    package_name = 'robot_launch'
    
    ld = LaunchDescription()
    pkg_share = FindPackageShare(package=package_name).find(package_name) 

    # 启动 teleop_twist_joy控制节点，获取手柄数据并输出Vx,Vy,W的控制数据
    teleop_node_cmd = ExecuteProcess(
        cmd=['ros2', 'launch','teleop_twist_joy', 'teleop-launch.py'],
        output='screen')
    # 启动 joy_node作为手柄驱动，读取手柄原始数据并在/joy节点输出
    joy_node_cmd = Node(
        package='joy',
        executable='joy_node',
        output='screen'
    )
    #启动EKF融合
    robot_localization_node = Node(
       package='robot_localization',
       executable='ekf_node',
       name='ekf_filter_node',
       output='screen',
       remappings=[('/odometry/filtered', '/odom')],
       parameters=[os.path.join(pkg_share, 'config/ekf.yaml'),
        		   {'use_sim_time': False}])# 添加这行以设置使用仿真时间    
  	#启动SLAM_Gmapping进行建图
    start_slam_node_cmd =  ExecuteProcess(
        cmd=['ros2', 'launch','slam_gmapping', 'slam_gmapping.launch.py'],
        output='screen')
   	
  	#启动Robot_State_Publish进行输出坐标转换信息
    start_robot_tf_node_cmd =  ExecuteProcess(
        cmd=['ros2', 'launch','robot_description', 'robot_description.launch.py'],   
        output='screen')
        
    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        )

    ld.add_action(teleop_node_cmd)
    ld.add_action(joy_node_cmd)
    #ld.add_action(robot_localization_node)    
    ld.add_action(start_slam_node_cmd)
    ld.add_action(start_robot_tf_node_cmd)
    ld.add_action(rviz2_node)

    return ld

