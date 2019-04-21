#!/usr/bin/env python 
# -*- coding: utf-8 -*-
 
import roslib
import rospy  
import actionlib  
from actionlib_msgs.msg import *  
from geometry_msgs.msg import Pose, PoseWithCovarianceStamped, Point, Quaternion, Twist  
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal  
from random import sample  
from math import pow, sqrt  

class NavTest():
    ##初始化坐标点  
    def init_pos(self):
        self.locations = dict() ##设置字典
        self.locations['door'] = Pose(Point(0.09, 0.775, 0.000),   Quaternion(0.000, 0.000, 0.995, 0.094)) 
        self.locations['shelf'] = Pose(Point(Point(-1.93, 1.87, 0.000), Quaternion(0.000, 0.000, 0.000, 1.000)))
    #设置导航目标
    def set_goal(self,location):##什么引用传递赋值传递全部都不知道，而且到底怎么实现多函数交互也不清晰。
        self.goal = MoveBaseGoal()  
        self.goal.target_pose.pose = self.locations[location]  
        self.goal.target_pose.header.frame_id = 'map'  
        self.goal.target_pose.header.stamp = rospy.Time.now()
        # 向下一个位置进发  
        self.move_base.send_goal(self.goal)
    # 五分钟时间限制  
        finished_within_time = self.move_base.wait_for_result(rospy.Duration(300))   
        # 查看是否成功到达  
        if not finished_within_time:  
            self.move_base.cancel_goal()  
            rospy.loginfo("Timed out achieving goal")  
        else:  
            state = self.move_base.get_state()  
            if state == GoalStatus.SUCCEEDED:  
                rospy.loginfo("Goal succeeded!")  
                rospy.loginfo("State:" + str(state))  
            else:  
              rospy.loginfo("Goal failed with error code: " + str(self.goal_states[state]))  
        rospy.sleep(self.rest_time)  
    def shutdown(self):  
        rospy.loginfo("Stopping the robot...")  
        self.move_base.cancel_goal()  ##消除目标
        rospy.sleep(2)  
        self.cmd_vel_pub.publish(Twist())  ####停止追踪
        rospy.sleep(1)   
    def __init__(self): ###这个应该就是初始化函数。。
        rospy.init_node('get_navi_goal', anonymous=True)  
        rospy.on_shutdown(self.shutdown)  

        # 在每个目标位置暂停的时间 (单位：s)
        self.rest_time = rospy.get_param("~rest_time", 2)  

        # 是否仿真？  
        self.fake_test = rospy.get_param("~fake_test", True)  

        # 到达目标的状态  
        self.goal_states = ['PENDING', 'ACTIVE', 'PREEMPTED',   
                       'SUCCEEDED', 'ABORTED', 'REJECTED',  
                       'PREEMPTING', 'RECALLING', 'RECALLED',  
                       'LOST']  
        # 设置目标点的位置  
        # 在rviz中点击 2D Nav Goal 按键，然后单击地图中一点  
        # 在终端中就会看到该点的坐标信息  
        # 发布控制机器人的消息  ,准备发布终止消息
        self.cmd_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size=5)  
        # 订阅move_base服务器的消息,也就是那个订阅简化服务器
        self.move_base = actionlib.SimpleActionClient("move_base", MoveBaseAction)  
        ##连接服务器
        rospy.loginfo("Waiting for move_base action server...")  
        self.move_base.wait_for_server(rospy.Duration(1))  
        rospy.loginfo("Connected to move base server")  
        self.init_pos()
        self.set_goal('door')

if __name__ == '__main__':  
    try:  
        NavTest()  
        rospy.spin()  

    except rospy.ROSInterruptException:  
        rospy.loginfo("Exploring SLAM finished.")
