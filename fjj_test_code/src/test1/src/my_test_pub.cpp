
//同时接受多个信息，然后最后汇总成一句话
#include "ros/ros.h"
#include"std_msgs/String.h"
#include<string.h>
#include<strings.h>
#include<sstream>
// class my_pub
// {
//     public:
//     ros::Publisher pub1,pub2,pub3;
//     std_msgs::String my_string;
//     std::string record;
//     ros::NodeHandle nh;
//     my_pub()
//     {
       
//         pub1 =  nh.advertise<std_msgs::String>("string1",1000);
//         pub1 =  nh.advertise<std_msgs::String>("string2",1000);
//         pub1 =  nh.advertise<std_msgs::String>("string3",1000);
//         my_string.data = "i";
//         ROS_INFO("%s",my_string.data.c_str());
//        // pub1.publish(my_string);
//        // my_string.data="love";
//         //pub2.publish(my_string);
//        // my_string.data="you";
//         //pub3.publish(my_string);
//     }
// };
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "test_pub");
    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<std_msgs::String>("string1", 1000);
    ros::Publisher pub2 = nh.advertise<std_msgs::String>("string2", 1000);
    ros::Publisher pub3 = nh.advertise<std_msgs::String>("string3", 1000);
    std_msgs::String my_string;
    std::stringstream ss;
    
    ros::Rate loop_rate(10);
    while(ros::ok())
{
    
    
    my_string.data = "i";
    pub1.publish(my_string);
    

     
    my_string.data = "love";
    pub2.publish(my_string);
    

    
    my_string.data = "you";
    pub3.publish(my_string);
    
    loop_rate.sleep();

}    return 0;
}