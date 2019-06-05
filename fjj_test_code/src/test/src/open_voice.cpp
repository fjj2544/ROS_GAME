#include "ros/ros.h"
#include "iostream"
#include "std_msgs/String.h"
const double rate_fre=0.1;//交接频率

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "open_voice");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("/voiceWakeup", 1000);
    std_msgs::String str;
    str.data = "111";
    ros::Rate loop_rate(rate_fre);//这个可以接上,整个流程可以完整的控制

    while(ros::ok())
    {
        pub.publish(str);
        loop_rate.sleep();
        ros::spinOnce();
    }
    return 0;
}