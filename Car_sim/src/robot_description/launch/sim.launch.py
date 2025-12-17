from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, OpaqueFunction, RegisterEventHandler
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch.event_handlers import OnProcessStart


def generate_launch_description():

    # Get the package share directory
    robot_description_package = get_package_share_directory("robot_description")

    # Define the path to the sdf, urdf and world files
    sdf_file = os.path.join(robot_description_package, "sdf", "robot_gazebo.sdf")
    urdf_file = os.path.join(robot_description_package, "urdf", "robot_gazebo.urdf")
    world_file = os.path.join(robot_description_package, "world", "sim.world")

    # define the bridge and ekf parameters files
    bridge_params = os.path.join(
        robot_description_package,
        "config",
        "bridge_config.yaml",
    )

    ekf_config_file = os.path.join(
        robot_description_package,
        "config",
        "ekf.yaml",
    )

    gmapping_config_file = os.path.join(
        robot_description_package,
        "config",
        "gmapping.yaml",
    )

    # Read the URDF file
    with open(urdf_file, 'r') as f:
        robot_description_content = f.read()

    # Declare arguments
    use_sim_time_arg = DeclareLaunchArgument(
        "use_sim_time",
        default_value="true",
        description="Use simulation (Gazebo) clock if true",
    )

    # Start Gazebo server with the world file
    gazebo_server_cmd = ExecuteProcess(
        cmd=["gz", "sim", "-r", "-s", "-v", "4", world_file],
        output="screen",
        shell=False
    )

    # Start Gazebo client (GUI)
    gazebo_client_cmd = ExecuteProcess(
        cmd=["gz", "sim", "-g"],
        output="screen",
        shell=False
    )

    # Define the spawn_entity node to spawn the robot in Gazebo
    spawn_entity_node = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-file", sdf_file,
            "-name", "robot",
            "-z", "0.03",
        ],
        output="screen",
    )

    # Start the ROS-Gazebo bridge with direct topic mappings
    ros_gz_bridge_node = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        parameters=[{
            "config_file": bridge_params
        }],
        output="screen",
    )

    # Robot state publisher - publish robot_description and static sensor TF only
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="screen",
        parameters=[{
            "robot_description": robot_description_content,
            "use_sim_time": LaunchConfiguration("use_sim_time"),
            "publish_frequency": 0.0,  # Disable continuous TF publishing (Gazebo provides odom->base_link)
        }],
    )

    # EKF localization node for sensor fusion (odom + imu)
    ekf_node = Node(
        package="robot_localization",
        executable="ekf_node",
        name="ekf_filter_node",
        output="screen",
        parameters=[
            ekf_config_file,
            {
                "use_sim_time": LaunchConfiguration("use_sim_time"),
                "transform_timeout": 0.5,
                "two_d_mode": True,
            },
        ],
    )

    # gmapping node for SLAM
    gmapping_node = Node(
        package="slam_gmapping",
        executable="slam_gmapping",
        name="slam_gmapping",
        output="screen",
        parameters=[
            gmapping_config_file,
            {
                "use_sim_time": LaunchConfiguration("use_sim_time")
            }
        ],
        remappings=[
            ("/odom", "/odom"),
            ("/scan", "/scan"),
        ],
    )

    # Event handler to start EKF after bridge is ready
    # DISABLED: EKF is causing issues with odometry sync
    ekf_start = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=ros_gz_bridge_node,
            on_start=[ekf_node]
        )
    )

    # RViz2 for visualization
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", os.path.join(robot_description_package, "rviz", "default.rviz")],
    )

    # Event handler to start gmapping after bridge is ready
    gmapping_start = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=ros_gz_bridge_node,
            on_start=[gmapping_node]
        )
    )

    return LaunchDescription(
        [
            use_sim_time_arg,
            gazebo_server_cmd,
            gazebo_client_cmd,
            spawn_entity_node,
            ros_gz_bridge_node,
            robot_state_publisher_node,
            rviz_node,
            ekf_start,
            gmapping_start,
        ]
    )