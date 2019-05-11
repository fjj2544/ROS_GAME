//定位的准确度。
//小物体，不会壁障。为什么不会壁障
#include "ros/ros.h"
#include"iostream"
#include<std_msgs/String.h>
#include<string.h>
//设置目标点的信息
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
//move_base对应接口
#include "move_base_msgs/MoveBaseGoal.h"
#include "move_base_msgs/MoveBaseAction.h"//可以写反馈函数了
//action接口
#include<actionlib/client/simple_action_client.h>
#include<geometry_msgs/Twist.h>
#include"tf2_msgs/TFMessage.h"
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include<sound_play/SoundRequestActionGoal.h>
#include<sstream>
#include<math.h>
#include<algorithm>

using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;//任何action都可以用这个控制。

double  get_distance(geometry_msgs::Pose A,geometry_msgs::Pose B)
{
   double x1= A.position.x,
        y1= A.position.y,
        z1= A.position.z,
        x2= B.position.x,
        y2= B.position.y,
        z2= B.position.z;
    double temp1,temp2,temp3;
    temp1=x1-x2;
    temp2=y1-y2;
    temp3=z1-z2;
    double sum=0;
    sum = temp1*temp1+temp2*temp2+temp3*temp3;
    sum = sqrt(sum);
    return sum;
}

//格式化字符串
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

//得到当前点的坐标
void get_present_pos(geometry_msgs::Pose & pre_pos )
{
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);
    int flag=0;
    while(ros::ok()&&flag==0)//真好拿到就跑..
    {
    geometry_msgs::TransformStamped transformStamped;//这个就是当前点的坐标..
     try{
        transformStamped = tfBuffer.lookupTransform("map", "base_link",
                               ros::Time(0));
        pre_pos.position.x = transformStamped.transform.translation.x;
        pre_pos.position.y = transformStamped.transform.translation.y;
        pre_pos.position.z = transformStamped.transform.translation.z;
        pre_pos.orientation.x = transformStamped.transform.rotation.x;
        pre_pos.orientation.y = transformStamped.transform.rotation.y;
        pre_pos.orientation.z = transformStamped.transform.rotation.z;
        pre_pos.orientation.w = transformStamped.transform.rotation.w;
        flag=1;
        }
    catch (tf2::TransformException &ex) {
      ROS_WARN("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }//必须try..
    }

}

//设置地图上的坐标点
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

//goal_sub_ = goal_sub_nh.subscribe<geometry_msgs::PoseStamped>("goal", 1, boost::bind(&NavGoalManager::goalSimple, this, _1));新的sub形式
class fare_well
{
public:
    fare_well();
    void cb(const std_msgs::String::ConstPtr & msg );
    void go_to_place(geometry_msgs::Pose temp);//整体应该优化的就是到达这个目标点的函数,可能不同的可以单独设置反馈函数,用一个通用反馈和特定化反馈.
    void go_to_the_door();
    void go_to_the_shelf();
    void go_back_to_the_first_place();
    void tell_the_task(std::string temp);
    //反馈函数
    void feedbackcb(const move_base_msgs::MoveBaseFeedbackConstPtr & fb);//这个const 能恶心死我,我突然忘了。。我可以用指针。。想用的时候new一个出来。。。em
    //完成之后的函数
    void doneCallback(const actionlib::SimpleClientGoalState &state,
                        const move_base_msgs::MoveBaseResultConstPtr &result);
    void activecb();
    void fetch(geometry_msgs::Pose goal_pose);
    void order_command(std::string ss);
protected: 
    bool pass=true;
    bool robot_go_to_shelf;//进入fetch状态
    bool robot_go_out_the_door;//出门状态
    bool robot_go_back;//回归状态
    ros::Subscriber sub_voice;//回馈声音
    ros::Publisher pub;
    ros::Publisher pub_pose;
    ros::Publisher sound_pub;
    ros::Publisher pub_command;
    ros::NodeHandle nh;
    MoveBaseClient mbc;
    geometry_msgs::Pose door_pos;
    geometry_msgs::Pose shelf_pos;//柜子位置
    geometry_msgs::Pose last_pos;//去柜子之前的位置
    geometry_msgs::Pose wait_pos;//等待的位置
    geometry_msgs::Pose driver_pos;//司机的位置,便于做反馈,如果我到达了司机的地方我就应该走了
    move_base_msgs::MoveBaseGoal navi_goal;//当前导航目标点
    std::string start_call;
    std_msgs::String cmd;
    sound_play::SoundRequestActionGoal procedure_voice;
    bool work_done;

    int timer=1;//测试语音序列
};


//在这里修改对应的节点信息
fare_well::fare_well():mbc(nh,"move_base",true)//记住应该旋转,不能不动..不动就容易搞不到位置.
    {

        // ROS_INFO("Waiting for the move_base action server");
        // mbc.waitForServer(ros::Duration(60));
        // ROS_INFO("Connected to move base server");

        //设置对应的关键坐标点信息
        set_pos(door_pos,-3.8004,-1.6299,0.0102, 0.0,0.0,-0.74421,0.66794);//设置门的位置
        set_pos(shelf_pos,-5.1271,1.865,0.0102,0.0,0.0,0.82319,0.5677);//设置储物柜位置,这个就是fetch的操作
        set_pos(wait_pos,4.9855,2.6991,0.0102 , 0.0,0.0,0.92789,-0.37285);
        set_pos(last_pos,0,0,0 , 0.006,0.006,0.005,0.993);
        //发送消息板块
        pub_command = nh.advertise<std_msgs::String>("/control_command",1000);
        sound_pub = nh.advertise<sound_play::SoundRequestActionGoal>("/sound_play/goal", 1000);
        pub =  nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);//发送停止信息
        pub_pose = nh.advertise<geometry_msgs::Pose>("cur_pose",1000);
        //接受消息板块
        sub_voice = nh.subscribe("voiceWords",1000,&fare_well::cb,this);//没有办法控制区段循环
        //表示工作完成
        work_done=false;
        //是否可以出门
        robot_go_out_the_door=false;
        //是否去衣柜
        robot_go_to_shelf=false;
        //是否已经完成可以返回
        robot_go_back=false;
        //主要是提前打开服务节点
        start_call="";
        tell_the_task(" ");//连接服务器。
        sleep(1);

        tell_the_task("now i will go to the waiting place to wait your command!");
        ROS_INFO("now i will go to the waiting place to wait your command!");
        go_back_to_the_first_place();//一直在这个地方等着消息
    }
//这个节点实现异步控制运动状态，连接控制中枢 等下我会给出对应的节点分布图和节点功能图
void fare_well::order_command(std::string ss)
{
    cmd.data=ss;//关键
    pub_command.publish(cmd);
    sleep(1);
}
//过程反馈函数
void fare_well::feedbackcb(const move_base_msgs::MoveBaseFeedbackConstPtr & fb)//反馈控制函数,每次甚至可以不同导入不同的函数指针。。每次的反馈都不同
{
    geometry_msgs::Pose cur_pose = fb->base_position.pose;
    geometry_msgs::Pose goal_pose = navi_goal.target_pose.pose;//通过计算空间距离来判断完成情况
    double cur_dis=get_distance(goal_pose,cur_pose);
    double eps=1.0;//单位为m,利用比较小的
    if(cur_dis<=eps)
    {
        this->mbc.cancelAllGoals();//已经到了
        ROS_INFO("I have arrived the goal!");
    }
    pub_pose.publish(cur_pose);//发布当前的位姿信息
    //这个可以用所谓rqt_consel得到对应的信息,完全控制。
}
//激活反馈函数
void fare_well::activecb()
{
    tell_the_task("Actived!");//甚至可以控制音量
}
//完成反馈函数
void fare_well::doneCallback(const actionlib::SimpleClientGoalState &state,
const move_base_msgs::MoveBaseResultConstPtr &result)
{   
}
void fare_well::fetch(geometry_msgs::Pose goal_pose)
{
    geometry_msgs::Pose cur_pose;
    get_present_pos(cur_pose);
    tell_the_task("GOT MSG I WILL GO TO THE GOAL");
    ROS_INFO("GOT MSG I WILL GO TO THE GOAL");
    go_to_place(goal_pose);//可以得到对应的状态
    sleep(10);
    tell_the_task("GO BACK");
    ROS_INFO("GO BACK");
    go_to_place(cur_pose);
}
void fare_well::go_to_the_door()
{
    //回到呼唤点后准备出门
    go_to_place(this->door_pos);//应该是到门外一点
    //然后开始导航建图.
}
void fare_well::go_to_the_shelf()
{
    //前往shelf位置
    go_to_place(this->shelf_pos);
   
}
//送完人之后回到原始等待位置
void fare_well::go_back_to_the_first_place()
{
    go_to_place(this->wait_pos);
}
void fare_well::tell_the_task(std::string temp)
{
    cout<<timer<<endl;
    timer+=1;
    procedure_voice.goal.sound_request.arg = temp.c_str();
    procedure_voice.goal.sound_request.arg2 = "voice_kal_diphone";
    procedure_voice.goal.sound_request.sound = -3;
    procedure_voice.goal.sound_request.volume = 1.0;
    procedure_voice.goal.sound_request.command = 1;
    sound_pub.publish(procedure_voice);
}

//首先假设我已经识别到人了,我应该到储物柜去,拿东西然后返回.也就是我要知道现在在哪
void fare_well::cb(const std_msgs::String::ConstPtr & msg )
    {
        //主要用语音监控所有的信息
        //时刻监听所有的控制信息
        
       //测试语音控制
       start_call = msg->data.c_str();
       cout<<start_call<<endl;
       
       if(is_equal(start_call,"i want to go。"))//你可以走了
       {
        robot_go_to_shelf=true;
       }
       if(is_equal(start_call,"you can go back。")||is_equal(start_call,"yes you can。"))
       {
           robot_go_back=true;
       }
       if(is_equal(start_call,"take me out。"))
       {
           robot_go_out_the_door=true;
       }

       //确定到柜子的信号
       if(robot_go_to_shelf==true)//应该用语音控制，但是局部又不能完全用语音控制,分节点控制，同时控制
       {
        order_command("stop listen");
        //首先得到呼唤消息
        //得到当前的位置
        tell_the_task("plase wait a minute , and i will take back your coat!");
        ROS_INFO("plase wait a minute , and i will take back your coat! ");
        get_present_pos(this->last_pos);
        go_to_the_shelf();//自己设置,应该会阻塞在这
        sleep(10);
        //去柜子面前

        //这里添加判断完成的时间控制器,或者状态控制器,一般来说可以给导航加上一个反馈器.
        //完成取物操作,返回呼唤点
        
        tell_the_task("ready to go back to the calling place!");
        ROS_INFO("ready to go back to the calling place!");
        go_to_place(this->last_pos);
        robot_go_to_shelf==false;
        start_call="";

        order_command("start listen");
       }
       
       //确定出门的信号,这个时候可以开启follow_me与gmapping,这个地方考虑到mbc可能会切换，最好不要切换mbc否则要重新呼唤服务器,会很麻烦
       
       if(robot_go_out_the_door==true)
       {

        order_command("stop listen");
        //我在里面可以不开amcl
        order_command("follow and slam");
        order_command("restart follower");
        
        //这里可以添加询问语句是否要出门
        //准备出门
        tell_the_task("let's go out , i will take you to your cab");
        ROS_INFO("let's go out , i will take you to your cab ");
        go_to_the_door();//自己设置
        robot_go_out_the_door=false;
        start_call="";

         order_command("start listen");
       }
       
       //储存地图开启amcl

       //准备回到最初状态，继续伺服
       if(robot_go_back==true)
       {
            order_command("stop listen");

            order_command("stop follower");
            
            order_command("save map");
            
            order_command("start amcl");
            
            tell_the_task("thank you for your coming!");
            ROS_INFO("thank you for your coming!");
            go_back_to_the_first_place();//一直在这个地方等着消息
            robot_go_back=false;
            work_done = true;
            start_call="";

            order_command("start listen");//这个类似时钟控制,重新开启
       }
    }
void fare_well::go_to_place(geometry_msgs::Pose temp)//整体应该优化的就是到达这个目标点的函数,可能不同的可以单独设置反馈函数,用一个通用反馈和特定化反馈.
    {

        navi_goal.target_pose.pose=temp;
        navi_goal.target_pose.header.frame_id="map";//设置目标坐标系
        navi_goal.target_pose.header.stamp=ros::Time::now(); 

        //通过调用服务实现设置目标点的操作.
        ROS_INFO("Sending goal!");
        mbc.sendGoal(navi_goal,
        boost::bind(&fare_well::doneCallback, this, _1, _2),
        boost::bind(&fare_well::activecb, this),
        boost::bind(&fare_well::feedbackcb, this,_1));
        //简单的等待
        ROS_INFO("Waiting for result!");
        mbc.waitForResult();//每一次可以等待的时间应该是以s为单位,等待时间，而且可以用这个进一步的进行PID控制啥的，这个就是控制底盘去设置底盘的目标点。
        if(mbc.getState()==actionlib::SimpleClientGoalState::SUCCEEDED)
        {
            ROS_INFO("You have reached the goal!");
            mbc.cancelGoal();
            return ;
        }
        else 
        {
            //取消目标点
           ROS_INFO("The base failed for some reason");
           mbc.cancelGoal();
           return ;
        }
    }

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "set_goal");//通过接收信息发送出去goal的指令
    fare_well test;
    ros::spin();
    return 0;
}

//-1.3534 2.0498 -0.00601196 
//.