from setuptools import setup, find_packages

package_name = 'robot_description'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/urdf', ['urdf/robot_gazebo.urdf']),
        ('share/' + package_name + '/sdf', ['sdf/robot_gazebo.sdf']),
        ('share/' + package_name + '/world', ['robot_description/world/sim.world']),
        ('share/' + package_name + '/config', ['config/ekf.yaml', 'config/bridge_config.yaml', 'config/gmapping.yaml']),
        ('share/' + package_name + '/launch', ['launch/gazebo.launch.py', 'launch/robot_model.launch.py', 'launch/sim.launch.py']),
        ('share/' + package_name + '/rviz', ['rviz/default.rviz']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mr-cheng',
    maintainer_email='1959711225@qq.com',
    description='Robot description package for simulation',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)
