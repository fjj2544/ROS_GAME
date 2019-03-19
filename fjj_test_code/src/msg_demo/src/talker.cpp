#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
//基本上ros的流都是用sstream来进行的

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talk");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1);
    ros::Rate loop_rate(10);
    int count=0;
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "FJJ_MY_WORD!!!! hello ros~!" << count;
        msg.data = ss.str();
        ROS_INFO("%s",msg.data.c_str());
        chatter_pub.publish(msg);
        ros::spinOnce();//如果在循环里面用这个就是一次里面死循环了，不会重复进行，一般发布消息如果要循环必须用while spinonce的方法而不能用spin
        loop_rate.sleep();
        ++count;
    }
    return 0;
}