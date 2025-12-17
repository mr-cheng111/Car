import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    package_name = 'robot_description'
    urdf_name = "robot_gazebo.urdf"

    ld = LaunchDescription()
    pkg_share = FindPackageShare(package=package_name).find(package_name)
    urdf_model_path = os.path.join(pkg_share, f'urdf/{urdf_name}')

    # Get world path
    gazebo_world_path = os.path.join(pkg_share, 'world/sim.world')

    # Start Gazebo with world file
    start_gazebo_cmd = ExecuteProcess(
        cmd=['gazebo', gazebo_world_path],
        output='screen'
    )

    # Start robot state publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        arguments=[urdf_model_path],
        output='screen'
    )

    # Start robot localization (EKF)
    robot_localization_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        remappings=[('/odometry/filtered', '/odom')],
        parameters=[os.path.join(pkg_share, 'config/ekf.yaml'),
                    {'use_sim_time': True}]
    )

    # Start RViz2 visualization
    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
    )

    # Include Nav2 launch
    nav2_launch_path = os.path.join(
        get_package_share_directory('car_nav2'),
        'launch',
        'car_nav2.launch.py'
    )

    nav2_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(nav2_launch_path)
    )

    # Add all actions to launch description
    ld.add_action(start_gazebo_cmd)
    ld.add_action(robot_localization_node)
    ld.add_action(robot_state_publisher_node)
    ld.add_action(nav2_launch_cmd)
    ld.add_action(rviz2_node)

    return ld
