# Lidar

## 一、硬件环境

&emsp;&emsp;1、ESP32S3-N16R8

&emsp;&emsp;2、镭神N10激光雷达

&emsp;&emsp;3、小米路由器

## 二、使用方法

&emsp;&emsp;驱动依托于官网的ROS2驱动，利用ESP32S3进行数据采集，通过TCP/IP协议将数据上传至电脑。然后利用socat，将端口上的数据接收并转到虚拟串口，最后在官网的ROS2驱动下更改对应串口号为虚拟串口号即可。

## 三、详细步骤
    
&emsp;&emsp;1、连接ESP32S3到电脑，同时可以打开串口助手查看状态输出。

&emsp;&emsp;2、打开新的命令行页面,输入如下命令：

    socat -d -d tcp-listen:8080 pty,raw,echo=0

&emsp;&emsp;效果截图：

<center>

![socat命令行截图](./img/socat_pic.png "socat输入命令实际效果")

</center>

&emsp;&emsp;3、打开新的命令行页面，运行镭神N10的ROS2包

    ros2 launch lslidar_driver lsn10_launch.py

&emsp;&emsp;效果截图：

<center>

![N10 Driver运行截图](./img/run%20N10.png "N10 Driver运行截图")

</center>

&emsp;&emsp;4、查看话题、频率以及rviz2查看点云效果

    ros2 node list
    ros2 topic list
    ros2 topic hz /scan
    rviz2

&emsp;&emsp;效果截图：

<center>

![查看话题](./img/频率.png "查看话题")

</center>

&emsp;&emsp;其中，雷达的扫描频率被设置为6Hz。极限可以到12Hz，未测试。

<center>

![查看话题](./img/rviz2.png "查看话题")

</center>

## 四、后记

&emsp;&emsp;由于对ESP32S3不熟悉，浪费了些时间。对于其他需求的激光雷达可以更改ESP驱动里面的包长度和Rx回调时间。后续可能会增加cppTcp转Serial的驱动。