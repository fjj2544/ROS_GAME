#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
ROS_INFO("I heard: [%s]", msg->data.c_str());
}//数据共享和数据汇总。
int main(int argc, char **argv)
{
ros::init(argc, argv, "listen");
ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("chatter", 1,chatterCallback);
//ros::spinOnce();//只会听一次，如果没有循环基本接受不到消息
ros::spin();
return 0;
}