from setuptools import find_packages
from setuptools import setup

setup(
    name='wireless_lidar',
    version='0.0.0',
    packages=find_packages(
        include=('wireless_lidar', 'wireless_lidar.*')),
)
