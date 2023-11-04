from setuptools import find_packages
from setuptools import setup

setup(
    name='car_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('car_interfaces', 'car_interfaces.*')),
)
