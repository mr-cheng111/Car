#!/usr/bin/env python3
import sys
import termios
import tty
import select
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class KeyboardTeleop(Node):
    def __init__(self):
        super().__init__('keyboard_teleop')

        # 发布者
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # 速度参数
        self.declare_parameter('linear_speed', 0.5)  # m/s
        self.declare_parameter('angular_speed', 1.0)  # rad/s

        self.linear_speed = self.get_parameter('linear_speed').value
        self.angular_speed = self.get_parameter('angular_speed').value

        # 当前速度
        self.vx = 0.0
        self.vy = 0.0
        self.vw = 0.0

        self.get_logger().info(f'键盘遥控已启动')
        self.get_logger().info(f'线速度: {self.linear_speed} m/s')
        self.get_logger().info(f'角速度: {self.angular_speed} rad/s')
        self.print_help()

        # 创建定时器用于处理键盘输入
        self.create_timer(0.1, self.timer_callback)

    def print_help(self):
        help_text = """
================ 键盘控制说明 ================
  前进/后退:
    W - 前进
    S - 后退

  旋转:
    A - 左转
    D - 右转

  停止:
    空格 - 停止

  速度调整:
    1/2 - 减少线速度
    3/4 - 增加线速度
    5/6 - 减少角速度
    7/8 - 增加角速度

  退出:
    Q 或 Ctrl+C
============================================
"""
        self.get_logger().info(help_text)

    def get_key(self):
        """获取单个键盘输入"""
        settings = termios.tcgetattr(sys.stdin)
        try:
            tty.setraw(sys.stdin.fileno())
            # 使用 select 检查是否有可用的输入
            if select.select([sys.stdin], [], [], 0)[0]:
                ch = sys.stdin.read(1).lower()
            else:
                ch = None
            return ch
        finally:
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)

    def timer_callback(self):
        """定时器回调，处理键盘输入和发布速度"""
        key = self.get_key()

        if key:
            # 前进/后退
            if key == 'w':
                self.vx = self.linear_speed
                self.vw = 0.0
            elif key == 's':
                self.vx = -self.linear_speed
                self.vw = 0.0
            # 旋转
            elif key == 'a':
                self.vx = 0.0
                self.vw = self.angular_speed
            elif key == 'd':
                self.vx = 0.0
                self.vw = -self.angular_speed
            # 停止
            elif key == ' ':
                self.vx = 0.0
                self.vw = 0.0
            # 速度调整
            elif key == '1':
                self.linear_speed = max(0.1, self.linear_speed - 0.1)
                self.get_logger().info(f'线速度: {self.linear_speed:.1f} m/s')
            elif key == '2':
                self.linear_speed = min(2.0, self.linear_speed + 0.1)
                self.get_logger().info(f'线速度: {self.linear_speed:.1f} m/s')
            elif key == '3':
                self.angular_speed = max(0.1, self.angular_speed - 0.1)
                self.get_logger().info(f'角速度: {self.angular_speed:.1f} rad/s')
            elif key == '4':
                self.angular_speed = min(2.0, self.angular_speed + 0.1)
                self.get_logger().info(f'角速度: {self.angular_speed:.1f} rad/s')
            # 退出
            elif key == 'q':
                self.get_logger().info('退出键盘遥控')
                rclpy.shutdown()
                return

        # 发布速度命令
        twist = Twist()
        twist.linear.x = self.vx
        twist.linear.y = self.vy
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = self.vw
        self.pub.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    keyboard_teleop = KeyboardTeleop()
    try:
        rclpy.spin(keyboard_teleop)
    except KeyboardInterrupt:
        pass
    finally:
        # 停止机器人
        twist = Twist()
        keyboard_teleop.pub.publish(twist)
        keyboard_teleop.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
