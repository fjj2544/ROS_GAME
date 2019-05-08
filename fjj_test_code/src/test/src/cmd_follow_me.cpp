//通过语音控制,语音为我所有控制信号的中心
#include "ros/ros.h"
#include"turtlebot_msgs/SetFollowState.h"
#include<string.h>
#include"strings.h"
#include"std_msgs/String.h"
#include<sound_play/SoundRequestActionGoal.h>
#include<algorithm>
using namespace std;
//规格化字符串消除。这个东西,关键是字符串解析
void clear_str(string & datastr)
{
    for(int i=0;i<datastr.length();i++)
    {
         if(datastr[i]>='a'&&datastr[i]<='z'||datastr[i]>='A'&&datastr[i]<='Z')
         continue;
         else 
         {
             datastr.erase(i,1);
         }
    }
}
bool is_equal(string a,string b)
{
    clear_str(a);
    clear_str(b);
    // cout<<a<<endl<<a.length()<<endl;
    // cout<<b<<endl<<b.length()<<endl;
    if(a.length()!=b.length())
    return false;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
        return false;
        
    }
    return true;
}
class solve
{
public:
    solve()
    {
        client = nh.serviceClient<turtlebot_msgs::SetFollowState>("/turtlebot_follower/change_state");
        cmd_follow = false;
        sub = nh.subscribe("voiceWords",1000,&solve::cb,this);
        pub_cmd =nh.advertise<std_msgs::String>("/control_command",1000);
        pub = nh.advertise<sound_play::SoundRequestActionGoal>("/sound_play/goal", 1000);
        pub_voice("11111");
        sleep(2);
    }
    void cb(const std_msgs::String::ConstPtr & msg);
    void pub_voice(std::string str);
    void call_srv();
private:
    ros::NodeHandle nh;
    ros::ServiceClient client;
    turtlebot_msgs::SetFollowState srv;
    ros::Subscriber sub;
    bool cmd_follow ;
    sound_play::SoundRequestActionGoal voice;
    ros::Publisher pub;
    ros::Publisher pub_cmd;
    std_msgs::String cmd;
    /* data */
};
void solve::pub_voice(std::string str)
{
    voice.goal.sound_request.arg = str.c_str();
    voice.goal.sound_request.arg2 = "voice_kal_diphone";
    voice.goal.sound_request.sound = -3;
    voice.goal.sound_request.volume = 1.0;
    voice.goal.sound_request.command = 1;
    pub.publish(voice);
}
void solve::cb(const std_msgs::String::ConstPtr & msg)
{
    string datastr = msg->data;//科大讯飞英文识别。。为什么了呢
    clear_str(datastr);

    if ( is_equal(datastr,"you can go back")||is_equal(datastr,"i am here")||is_equal(datastr,"stop follow me")||is_equal(datastr,"stop"))
    {

        cout<<"stop!"<<endl;
        ROS_INFO("the robot have to stopped!");
        cmd.data="stop follower";
        pub_cmd.publish(cmd);
        
    }
    else if(is_equal(datastr,"take me out")||is_equal(datastr,"follow me"))//反馈可以搞一下,这个应该是到门了,可以做一个状态编码
    {
        cout<<"start!"<<endl;
        ROS_INFO("the robot can follow you now!");
        cmd.data="restart follower";
        pub_cmd.publish(cmd);

    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "control_follower_client");//节点名称
    solve test;
    ros::spin();


    return 0;
}