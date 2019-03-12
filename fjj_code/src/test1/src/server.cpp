#include "ros/ros.h"
#include <test1/mysrv.h>
bool add(test1::mysrv::Request &req,test1::mysrv::Response &res)
{
    res.sum=req.a+req.b+req.c;
    ROS_INFO("You want to konw the sum of these three ints %d,%d,%d",req.a,req.b,req.c);
    ROS_INFO("Now I tell you the sum of them is %d",res.sum);
    return true;
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "add_server");
    ros::NodeHandle nh;
    //下面是创建窗口服务，创建server的名称
    ros::ServiceServer service = nh.advertiseService("add_three_ints",add);
    ROS_INFO("ready to add three ints!");
    ros::spin();
    return 0;
}
