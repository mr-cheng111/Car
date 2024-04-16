import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    robot_name_in_model = 'robot'
    package_name = 'robot_description'
    urdf_name = "robot_gazebo.urdf"

    ld = LaunchDescription()
    pkg_share = FindPackageShare(package=package_name).find(package_name) 
    urdf_model_path = os.path.join(pkg_share, f'urdf/{urdf_name}')

    # 开启SPWAN模拟器加载urdf模型
    spawn_entity_cmd = Node(
        package='gazebo_ros', 
        executable='spawn_entity.py',
        arguments=['-entity', robot_name_in_model, '-file', urdf_model_path ],
        output='screen')
        
    gazebo_world_path = os.path.join(pkg_share, 'world/sim.world')

    # 启动Gazebo仿真系统
    start_gazebo_cmd =  ExecuteProcess(
        cmd=['gazebo', '--verbose','-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so', gazebo_world_path],
        output='screen')
   
    #启动RVIZ可视化节点
    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
    )
    #启动TF2 publish节点，输出机器人的坐标变换
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        arguments=[urdf_model_path]
        )
        
    #启动机器人的数据融合节点，使用EKF进行数据融合
    robot_localization_node = Node(
       package='robot_localization',
       executable='ekf_node',
       name='ekf_filter_node',
       output='screen',
       remappings=[('/odometry/filtered', '/odom')],
       parameters=[os.path.join(pkg_share, 'config/ekf.yaml'),
        		   {'use_sim_time': True}])# 添加这行以设置使用仿真时间
    
    #启动机器人的SLAM算法，构建地图，使用Gmapping算法
    start_slam_node_cmd =  ExecuteProcess(
        cmd=['ros2', 'launch','slam_gmapping', 'slam_gmapping.launch.py'],
        output='screen')
    
    #启动机器人的导航控制节点
    start_car_nav2_node_cmd =  ExecuteProcess(
        cmd=['ros2', 'launch','car_nav2', 'car_nav2.launch.py'],
        output='screen')
    
    ld.add_action(start_gazebo_cmd)
    ld.add_action(spawn_entity_cmd)
    ld.add_action(start_car_nav2_node_cmd)
    ld.add_action(robot_localization_node)
    #ld.add_action(start_slam_node_cmd)
	
    ld.add_action(robot_state_publisher_node)
    ld.add_action(rviz2_node)

    return ld
