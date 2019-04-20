#include<ros/ros.h>
#include"opencv_apps/RotatedRectStamped.h"
#include "geometry_msgs/Twist.h"
ros::Subscriber sub;
ros::Publisher pub;
const double inf =0x7fffffff;
double last_x=inf;
const double lin_scale=0.01;
const double ang_scale=-0.1;//在我的右边我应该顺时针旋转
void callback(const opencv_apps::RotatedRectStampedConstPtr & pos)//定义差动放大器
{
    geometry_msgs::Twist vel_msg;
    double cur_x=pos->rect.center.x;
    vel_msg.linear.x=vel_msg.linear.y=vel_msg.linear.z=0;//暂时没有线速度
    vel_msg.angular.x=vel_msg.angular.y=0;
    if(last_x==inf)
    vel_msg.angular.z=0;
    else
    vel_msg.angular.z=ang_scale*(cur_x-last_x);
    last_x=cur_x;
    pub.publish(vel_msg);
    return ;
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "cmd_rb");
    ros::NodeHandle nh;
    pub = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop",1000);
    sub = nh.subscribe("/camshift/track_box",1000,callback);
    ros::spin();
    return 0;
}