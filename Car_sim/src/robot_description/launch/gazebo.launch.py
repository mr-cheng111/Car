import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
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
    # Using gazebo command directly (works with Gazebo Harmonic)
    start_gazebo_cmd = ExecuteProcess(
        cmd=['gazebo', gazebo_world_path],
        output='screen'
    )

    # Start teleop_twist_joy for gamepad control
    teleop_node_cmd = ExecuteProcess(
        cmd=['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', 'joy_vel:=/cmd_vel'],
        output='screen'
    )

    # Start RViz2 visualization
    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
    )

    # Start robot state publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        arguments=[urdf_model_path],
        output='screen'
    )

    # Start SLAM gmapping
    start_slam_node_cmd = ExecuteProcess(
        cmd=['ros2', 'launch', 'slam_gmapping', 'slam_gmapping.launch.py'],
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

    # Add all actions to launch description
    ld.add_action(start_gazebo_cmd)
    ld.add_action(robot_localization_node)
    ld.add_action(teleop_node_cmd)
    ld.add_action(robot_state_publisher_node)
    ld.add_action(start_slam_node_cmd)
    ld.add_action(rviz2_node)

    return ld
