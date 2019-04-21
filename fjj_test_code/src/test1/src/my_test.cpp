
//同时接受多个信息，然后最后汇总成一句话,这样就可以融合信息，也不用管多线程同步的问题。
#include "ros/ros.h"
#include"std_msgs/String.h"
#include<string.h>
#include<strings.h>
#include<sstream>
class my_class
{
    public:
    my_class();
    void pub_msg();
    private:
    ros::Subscriber sub1 ;
    ros::Subscriber sub2 ;
    ros::Subscriber sub3 ; 
    ros::Publisher pub ;
    std_msgs::String my_string;
    std::string record;
    ros::NodeHandle nh;
    void callback1(const std_msgs::String::ConstPtr & msg);//回调函数必须这么写。。这个。。
    void callback2(const std_msgs::String::ConstPtr & msg);
    void callback3(const std_msgs::String::ConstPtr & msg);
    
};
my_class::my_class()
{
    
        sub1 = nh.subscribe("string1",1000,& my_class::callback1,this);
        sub2 = nh.subscribe("string2",1000,& my_class::callback2,this);
        sub3 = nh.subscribe("string3",1000,& my_class::callback3,this);//必须有全局变量存着，然后在任意一个地方发送信息就好了，没有特定的地方
        pub =  nh.advertise<std_msgs::String>("get_the_string",1000);
    
}
void my_class::callback1(const std_msgs::String::ConstPtr & msg)
{
    record += msg->data.c_str();
}
void my_class::callback2(const std_msgs::String::ConstPtr & msg)
{
    record += msg->data.c_str();
}
void my_class::callback3(const std_msgs::String::ConstPtr & msg)
{
    record += msg->data.c_str();//发送到屏幕上
    
}
void my_class::pub_msg()
{
    my_string.data = record;
    ROS_INFO("%s",my_string.data.c_str());
    record.clear();
    pub.publish(my_string);//可能要加bubble，利用并行技术
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "test_sub");
    my_class temp;//通过类似全局变量的机制
    //ros::MultiThreadedSpinner spinner(4);//没有必要开多线程》
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        temp.pub_msg();
        loop_rate.sleep();
        ros::spinOnce();
    }
    return 0;
}