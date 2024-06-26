import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    #=============================1.定位到包的地址=============================================================
    car_nav2_dir = get_package_share_directory('car_nav2')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    
    
    #=============================2.声明参数，获取配置文件路径===================================================
    use_sim_time = LaunchConfiguration('use_sim_time', default='False')
    use_slam = LaunchConfiguration('use_slam', default='False')
    map_yaml_path = LaunchConfiguration('map',default=os.path.join(car_nav2_dir,'maps/Real_Map','real_map.yaml'))
    nav2_param_path = LaunchConfiguration('params_file',default=os.path.join(car_nav2_dir,'param','car_nav2.yaml'))

    #=============================3.声明启动launch文件，传入：地图路径、是否使用仿真时间以及nav2参数文件==============
    nav2_bringup_launch = IncludeLaunchDescription(
            PythonLaunchDescriptionSource([nav2_bringup_dir,'/launch','/bringup_launch.py']),
            launch_arguments={
                'map': map_yaml_path,
                'use_sim_time': use_sim_time,
                #'use_slam': use_slam,
                'params_file': nav2_param_path}.items(),
                
        )
    
    return LaunchDescription([nav2_bringup_launch])

