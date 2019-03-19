#include "ros/ros.h"
#include <msg_demo/srv_demo.h>
#include<cstdlib>
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "add_client");
    if(argc != 3)
    {
        ROS_INFO("usage: add_two_ints_clints X Y");
        return 1;
    }
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<msg_demo::srv_demo>("add_two_ints");
    msg_demo::srv_demo srv;
    srv.request.a=atoll(argv[1]);
    srv.request.b=atoll(argv[2]);
    if(client.call(srv))//发出请求
    {
        ROS_INFO("Sum:%ld",(long int )srv.response.sum);
    }
    else
    {
        ROS_ERROR("fail to call the server!");
        return 1;
    }
    return 0;
}

