#include"ros/ros.h"
#include"test1/num.h"
//how to do with the message you got from the node is important 
void callback(const test1::num::ConstPtr & msg)//这是一个指针不是对象
{
    ROS_INFO("I have heard you ! & I got three num %d,%d,%d",msg->a,msg->b,msg->c);
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("trans_int", 1000, callback);
    ros::spin();
    return 0;
}