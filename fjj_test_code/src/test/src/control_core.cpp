#include<ros/ros.h>
#include<std_msgs/String.h>
#include"turtlebot_msgs/SetFollowState.h"
#include<sound_play/SoundRequestActionGoal.h>
using namespace std;//pid反馈控制器

//可以控制gmapping的切换重启节点等等,控制节点的切换，组态转换,实现状态切换,模式转换,利用节点信息控制完成循环流程
void open_amcl()//结合多种信息控制，除了语音还要有其他的接口,实现状态接口控制
{
    system("gnome-terminal -x bash -c 'roslaunch fare_well command_amcl.launch' ");
}
void open_gmapping()
{
    system("gnome-terminal -x bash -c 'roslaunch fare_well command_gmapping.launch' ");
}
void close_gmapping()
{
    system("rosnode kill /slam_gmapping");
    system("rosnode kill /empty_node ");
}
void close_amcl()
{
    system("rosnode kill /amcl");
    system("rosnode kill /empty_node ");//所有的切换的时候都用这个节点控制上一个状态的清除
}
void open_follower()
{
    system("gnome-terminal -x bash -c 'roslaunch turtlebot_follower follower.launch' ");
}
void open_sound_node()
{
    system("gnome-terminal -x bash -c 'rosrun test open_voice' ");//这个就可以控制是否阻塞了
}
void close_sound_node()//其实暂时的阻塞就好了。。
{
    system("rosnode kill /wake_up ");
}
void save_map()
{
    system("gnome-terminal -x bash -c 'roslaunch fare_well map_saver.launch'");
}
void start_follow_and_gmapping()
{
      system("gnome-terminal -x bash -c 'roslaunch fare_well gmapping_follower.launch'");
}
class order
{
public:
    order();
    void call_srv();
    void subCallback(const std_msgs::StringConstPtr & msg);
    void pub_voice(std::string str);
private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::ServiceClient client;
    turtlebot_msgs::SetFollowState srv;
    bool cmd_follow;//增加异步通信
    ros::Publisher pub;
    sound_play::SoundRequestActionGoal voice;

};
order::order()
{
     sub = nh.subscribe("control_command", 1000,&order::subCallback,this);//集成终端
     client = nh.serviceClient<turtlebot_msgs::SetFollowState>("/turtlebot_follower/change_state");
     cmd_follow=true;
     pub = nh.advertise<sound_play::SoundRequestActionGoal>("/sound_play/goal", 1000);
     pub_voice("11111");
     sleep(2);
}
void order::pub_voice(std::string str)
{
    voice.goal.sound_request.arg = str.c_str();
    voice.goal.sound_request.arg2 = "voice_kal_diphone";
    voice.goal.sound_request.sound = -3;
    voice.goal.sound_request.volume = 1.0;
    voice.goal.sound_request.command = 1;
    pub.publish(voice);
}
void order::subCallback(const std_msgs::StringConstPtr & msg)//还需要什么信息可以直接加
{
    std::string my_command = msg->data;

    //第一阶段屋内自主导航
    if(my_command.compare("start amcl")==0)
    {
        close_gmapping();
        sleep(1);
        open_amcl();
        pub_voice("start amcl");
    }
    if(my_command.compare("close amcl")==0)
    {
        close_amcl();
        pub_voice("close amcl");
    }   
    if(my_command.compare("start gmapping")==0)
    {
        close_amcl();
        sleep(1);
        open_gmapping();
        pub_voice("start gmapping");
    }
    if(my_command.compare("close gmapping")==0)
    {
        close_gmapping();
        pub_voice("close gmapping");
    }
    if(my_command.compare("start follower")==0)
    {
        open_follower();
        pub_voice("start follower");
    }
    if(my_command.compare("restart follower")==0)//这个的前提是开了follow
    {
        cout<<"start!"<<endl;
        srv.request.state = srv.request.FOLLOW;
        cmd_follow = true;
        call_srv();
    }
    if(my_command.compare("stop follower")==0)//这个似乎无法完成。。必须依靠语音节点或者调用服务,或者杀死对应终端
    {
        cout<<"stop!"<<endl;
        srv.request.state = srv.request.STOPPED;
        cmd_follow = false;
        call_srv();
    }
    if(my_command.compare("stop listen")==0)
    {
        close_sound_node();
        pub_voice("stop listen");
    }
    if(my_command.compare("start listen")==0)//也就是follow甚至可以一直开着
    {
        open_sound_node();//主要通过指令访问的形式调用控制节点关闭与开启
        pub_voice("start listen");
    }
    if(my_command.compare("save map")==0)//可以顺序承接,节点关系链
    {
        save_map();
        pub_voice("map saved");
    }
    if(my_command.compare("follow and slam")==0)
    {
        close_amcl();//防止冲突
        sleep(1);
        start_follow_and_gmapping();
    }
}
void order::call_srv()
{
        if(client.call(srv))
    {
        if(cmd_follow==false)
        {
            ROS_INFO("the robot have to stopped!");
            pub_voice("the robot have to stopped!");
        }
        else if(cmd_follow==true)
        {
                ROS_INFO("the robot can follow you now!");
                pub_voice("the robot can follow you now!");
        }
       return ;
    }
    else
    {
        ROS_ERROR("Failed to call the service ");
    }
}
int main(int argc, char *argv[])
{
    /* code for main function */
    ros::init(argc, argv, "control_core");
    order test;
    ros::spin();
    //设置字符串状态机，比如控制节点启动和关闭的命令等等,完全可以操作
    return 0;
}