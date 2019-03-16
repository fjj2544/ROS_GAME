#include "ros/ros.h"
#include"turtlebot_msgs/SetFollowState.h"
#include<string.h>
#include"strings.h"
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "control_follower_client");//节点名称
    if (argc != 2)
    {
        ROS_INFO("usage control_follower order (on or off)");
        /* code for True */
        return 1;
    }
    ros::NodeHandle nh;
    ros::ServiceClient client= nh.serviceClient<turtlebot_msgs::SetFollowState>("/turtlebot_follower/change_state");//请求服务名称类似topic
    turtlebot_msgs::SetFollowState srv;
    std::string order=argv[1];
    //int judge=atoll(argv[1]);
    if(order=="on")//我们要召唤服务
    srv.request.state=srv.request.FOLLOW;
    else
    srv.request.state=srv.request.STOPPED;
    if (client.call(srv))
    {
        if(order=="on")//我们要召唤服务
         ROS_INFO("the robot can follow you now!");
        else
         ROS_INFO("the robot have to stopped! ");
        /* code for True */
    }
    else
    {
        ROS_ERROR("Failed to call the service ");
    }
    
    return 0;
}