#include "ros/ros.h"
#include "iostream"
#include "std_msgs/String.h"
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "open_voice");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("voiceWakeup", 1000);
    std_msgs::String str;
    str.data = "111";
    ros::Rate loop_rate(0.1);//对应接口准确
    while(ros::ok())
    {
        pub.publish(str);//避免噪音干扰还可以加上一个启停控制,比如已经在运动的时候不接收消息
        loop_rate.sleep();
        ros::spinOnce();
    }
    return 0;
}