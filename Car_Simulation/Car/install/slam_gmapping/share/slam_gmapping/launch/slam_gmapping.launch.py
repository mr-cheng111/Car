import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='slam_gmapping',
            executable='slam_gmapping',  # 这里应该是节点的可执行文件名
            output='screen',  # 这里可以设置节点输出方式，例如 'log'
            # 其他参数根据节点需要进行设置，例如 'name', 'namespace', 'parameters' 等
            # parameters=[{'use_sim_time': use_sim_time}],  # 如果需要传递参数，可以在这里设置
        ),
    ])

if __name__ == '__main__':
    generate_launch_description()
