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
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;//任何action都可以用这个控制。

MoveBaseClient mbc("move_base",true);//既然全局都要用不如直接全局响应就好了,没有必要局部传参,一般来说这个都是全局用的

//    调用共同的服务去send goal
//记录接口，也就是可以直接发送信息
const int my_goal_num=100;
int thetotalofgoal=2;
geometry_msgs::Pose goal[my_goal_num];
geometry_msgs::Pose door_goal,shelf_goal;

void set_pos(geometry_msgs::Pose & temp,int px,int py,int pz,int ox,int oy,int oz,int ow)//如何得到当前的信息？
{
    temp.position.x=px;
    temp.position.y=py;
    temp.position.z=pz;
    temp.orientation.x=ox;
    temp.orientation.y=oy;
    temp.orientation.z=oz;
    temp.orientation.w=ow;
}
void initial_pos()//也就是可以实现自主导航的目的
{
    set_pos(goal[1],1,1,1,1,1,1,1);
    set_pos(goal[2],1,1,1,1,1,1,1);

    //定义重要点,可以作为参数给出,其实角度没有啥关系。。
    set_pos(door_goal,1,1,1, 1,1,1,1);
    set_pos(shelf_goal,1,1,1, 1,1,1,1);
}
void go_to_goal(geometry_msgs::Pose goal_pos )//发送达到目标点的请求
{
    move_base_msgs::MoveBaseGoal navi_goal;

    navi_goal.target_pose.pose = goal_pos;//设置对应的目标点.
    navi_goal.target_pose.header.frame_id="map";
    navi_goal.target_pose.header.stamp=ros::Time::now();
    
    //通过调用服务实现设置目标点的操作.
    mbc.sendGoal(navi_goal);
    mbc.waitForResult(ros::Duration(40));//每一次可以等待的时间应该是以s为单位,等待时间，而且可以用这个进一步的进行PID控制啥的，这个就是控制底盘去设置底盘的目标点。
    
    if(mbc.getState()==actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        cout<<"I have gone to the place "<<endl;
    }
    else 
    {
        cout<<"Wait";
    }
}
void auto_navi()//实现自主导航
{
    initial_pos();//设置初始坐标点,或者叫随机循环点,如果有一次不行就开始换，保证最后随机的点都是有效点，利用自增长算法或者随机取样尝试法。

    for(int i=1;i<=thetotalofgoal;i++)
    {
        go_to_goal(goal[i]);
    }
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "auto_navi");
    ros::NodeHandle nh;
    

    while(ros::ok())
    {
       // auto_navi();//但是那些点是可行点？
        ros::spinOnce();
    }
    return 0;
}


