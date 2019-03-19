#include <ros/ros.h>
#include <test1/mysrv.h>
#include<cstdlib>
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "client");
    if(argc!=4)
    {
        ROS_INFO("usage: add_three_ints_clints x y z");
        return 1;
    }
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<test1::mysrv>("add_three_ints");//调用服务
    test1::mysrv srv;
    srv.request.a=atoll(argv[1]);
    srv.request.b=atoll(argv[2]);//0没有用
    srv.request.c=atoll(argv[3]);
    if(client.call(srv))//利用当前srv去请求服务
    {
        ROS_INFO("Thank you ! I got the answer is %d",srv.response.sum);
    }
    else
    {
        ROS_ERROR("fail to call the server!");
        return 1;
    }
    return 0;
}