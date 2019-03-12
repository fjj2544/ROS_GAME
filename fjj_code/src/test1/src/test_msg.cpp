#include "ros/ros.h"
#include "test1/num.h"
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;//获得节点控制权
    ros::Publisher pub = nh.advertise<test1::num>("trans_int", 1000);
    //上面这句话只是创建了一个专门发送num这个类数据的topic然后下面要把这个cpp文件中对应num类型的topic发送出去
    ros::Rate loop_rate(10);//10hz
    int count=1;
    while(ros::ok())
    {
        test1::num test;
        test.a=1;
        test.b=2;
        test.c=test.a+test.b;
        ROS_INFO("This is the %d times.I send %d && %d to you ,and their sum is %d",count,test.a,test.b,test.c);
        pub.publish(test);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}