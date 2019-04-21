
#include "ros/ros.h"
#include"iostream"
#include<std_msgs/String.h>
#include<string.h>
//设置目标点的信息
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
//move_base对应接口
#include "move_base_msgs/MoveBaseGoal.h"
#include "move_base_msgs/MoveBaseAction.h"
//action接口
#include<actionlib/client/simple_action_client.h>
#include<geometry_msgs/Twist.h>
#include<signal.h>

using namespace std;

//类就是为了共享参数,因为所有函数都可能需要你,但是你只能在某一个变量后面声明.

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;//任何action都可以用这个控制。
//这个地方不能是int类型的


void set_pos(geometry_msgs::Pose & temp,double px,double py,double pz,double ox,double oy,double oz,double ow)//如何得到当前的信息？
{
    temp.position.x=px;
    temp.position.y=py;
    temp.position.z=pz;
    temp.orientation.x=ox;
    temp.orientation.y=oy;
    temp.orientation.z=oz;
    temp.orientation.w=ow;
}
int main(int argc, char *argv[])
{



    ros::init(argc, argv, "set_goal",ros::init_options::NoSigintHandler);//通过接收信息发送出去goal的指令
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    

    move_base_msgs::MoveBaseGoal navi_goal;
    geometry_msgs::Pose door_pos,shelf_pos;
    //而且似乎与这个move_base还有点关系
    MoveBaseClient mbc("move_base",true);//第一个参数似乎是消息的名称,或者说服务器的名称..
    ROS_INFO("Waiting for the move_base action server");
    mbc.waitForServer(ros::Duration(60));
    ROS_INFO("Connected to move base server");
    set_pos(door_pos,3.58,1.24,-0.00143, 0.0,0.0,0.004,0.995);
    set_pos(shelf_pos,1,1,1, 0.005,0.005,0.005,0.005);
    navi_goal.target_pose.pose=door_pos;
    navi_goal.target_pose.header.frame_id="map";//设置目标坐标系
    navi_goal.target_pose.header.stamp=ros::Time::now();   
    //通过调用服务实现设置目标点的操作.
    ROS_INFO("Sending goal!");
    mbc.sendGoal(navi_goal);
    //简单的等待
    ROS_INFO("Waiting for result!");
    mbc.waitForResult();//每一次可以等待的时间应该是以s为单位,等待时间，而且可以用这个进一步的进行PID控制啥的，这个就是控制底盘去设置底盘的目标点。
    if(mbc.getState()==actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        ROS_INFO("You have reached the goal!");
    }
    else 
    {
        //取消目标点
       ROS_INFO("The base failed for some reason");
    }
    
    ///这个只能全局传参么..
    return 0;
}









// #include "ros/ros.h"
// #include"iostream"
// #include<std_msgs/String.h>
// #include<string.h>
// //设置目标点的信息
// #include "geometry_msgs/Pose.h"
// #include "geometry_msgs/Point.h"
// //move_base对应接口
// #include "move_base_msgs/MoveBaseGoal.h"
// #include "move_base_msgs/MoveBaseAction.h"
// //action接口
// #include<actionlib/client/simple_action_client.h>
// #include<geometry_msgs/Twist.h>
// #include<signal.h>

// using namespace std;

// //类就是为了共享参数,因为所有函数都可能需要你,但是你只能在某一个变量后面声明.

// typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;//任何action都可以用这个控制。
// //这个地方不能是int类型的


// void set_pos(geometry_msgs::Pose & temp,double px,double py,double pz,double ox,double oy,double oz,double ow)//如何得到当前的信息？
// {
//     temp.position.x=px;
//     temp.position.y=py;
//     temp.position.z=pz;
//     temp.orientation.x=ox;
//     temp.orientation.y=oy;
//     temp.orientation.z=oz;
//     temp.orientation.w=ow;
// }




// class get_pos
// {
// public:
//     get_pos():mbc(nh,"move_base",true)
//     {
        

//         set_pos(door_pos,3.58,1.24,-0.00143, 0.0,0.0,0.004,0.995);
//         set_pos(shelf_pos,1,1,1, 0.005,0.005,0.005,0.005);
//         pub =  nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
//         ROS_INFO("Waiting for the move_base action server");
//         mbc.waitForServer(ros::Duration(60));
//         ROS_INFO("Connected to move base server");
     
//         navi_goal.target_pose.pose=door_pos;
//         navi_goal.target_pose.header.frame_id="map";//设置目标坐标系
//         navi_goal.target_pose.header.stamp=ros::Time::now(); 
//         //通过调用服务实现设置目标点的操作.
//         ROS_INFO("Sending goal!");
//         mbc.sendGoal(navi_goal);
//         //简单的等待
//         ROS_INFO("Waiting for result!");
//         mbc.waitForResult();//每一次可以等待的时间应该是以s为单位,等待时间，而且可以用这个进一步的进行PID控制啥的，这个就是控制底盘去设置底盘的目标点。
//         if(mbc.getState()==actionlib::SimpleClientGoalState::SUCCEEDED)
//         {
//             ROS_INFO("You have reached the goal!");
//         }
//         else 
//         {
//             //取消目标点
//            ROS_INFO("The base failed for some reason");
//         }
        
//     }
  
// protected:
//     ros::Publisher pub;
//     ros::NodeHandle nh;
//     MoveBaseClient mbc;
//     geometry_msgs::Pose door_pos;
//     geometry_msgs::Pose  shelf_pos;
//     move_base_msgs::MoveBaseGoal navi_goal;
// };

// int main(int argc, char *argv[])
// {


    
//     ros::init(argc, argv, "set_goal",ros::init_options::NoSigintHandler);//通过接收信息发送出去goal的指令
    
//     get_pos test;
   
    
//     return 0;
// }

