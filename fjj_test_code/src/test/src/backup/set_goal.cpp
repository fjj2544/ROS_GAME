//定位的准确度。
//小物体，不会壁障。为什么不会壁障 我似乎可以导航到目标点去。。
#include "ros/ros.h"
#include"iostream"
#include<std_msgs/String.h>
#include<string.h>
//设置目标点的信息
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
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
/*-----------------------------------------------------------------------------------------------得到当前与目标的距离-------------------------------------------------------------*/
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

/*----------------------------------------------------------------------------------------------格式化字符串，为语音节点服务-------------------------------------------------------------*/
void clear_str(string & datastr)
{
    for(int i=0;i<datastr.length();i++)
    {
         if(datastr[i]>='a'&&datastr[i]<='z'||datastr[i]>='A'&&datastr[i]<='Z')
         {
             if(datastr[i]>='A'&&datastr[i]<='Z')
             {
                 datastr[i] = datastr[i] - 'A' + 'a';//小写化
             }
             continue;
         }
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

/*-----------------------------------------------------------------------------------------------得到当前点坐标-------------------------------------------------------------*/
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
/*-----------------------------------------------------------------------------------------------设置坐标点-------------------------------------------------------------*/
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
    void go_out_the_door();
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
    void cmd_cb(const std_msgs::String::ConstPtr &msg);
    void go_to_the_driver();
    void go_to_serve_place();
protected: 
    bool work_done;
    bool work_begin;
    //状态控制器,用于函数分频
    bool recognize_people;
    bool robot_go_to_the_shelf;
    bool robot_go_out_the_door;
    bool robot_go_to_the_door;
    bool robot_go_back_to_the_door;
    bool robot_go_to_the_cab;
    bool robot_go_back_to_the_serving_place;
    bool robot_grasp_the_coat;
    bool robot_go_back_to_the_call_place;//一定要知道阻塞在哪一步了
    //语音校准器
    int timer=1;//测试语音序列
    ros::Subscriber sub_voice;//回馈声音
    ros::Subscriber sub_cmd;
    ros::Publisher pub;
    ros::Publisher pub_pose;
    ros::Publisher sound_pub;
    ros::Publisher pub_command;
    ros::NodeHandle nh;
    MoveBaseClient mbc;
    geometry_msgs::Pose cur_pose;
    geometry_msgs::Pose outdoor_pose;//我就是应该恢复到door_pose那个地方,本来就没有变化
    geometry_msgs::Pose indoor_pose;//门内的地方
    geometry_msgs::Pose shelf_pos;//柜子位置
    geometry_msgs::Pose last_pos;//去柜子之前的位置
    geometry_msgs::Pose wait_pos;//等待的位置
    geometry_msgs::Pose driver_pos;//司机的位置,便于做反馈,如果我到达了司机的地方我就应该走了
    geometry_msgs::PoseWithCovarianceStamped out_door_pose;
    move_base_msgs::MoveBaseGoal navi_goal;//当前导航目标点
    std_msgs::String cmd;
    sound_play::SoundRequestActionGoal procedure_voice;
    std::string cmd_str;
    ros::Publisher pub_est_pose;

};

/*-----------------------------------------------------------------------------------------------主要的初始化点-------------------------------------------------------------*/
//在这里修改对应的节点信息

fare_well::fare_well():mbc(nh,"move_base",true)//记住应该旋转,不能不动..不动就容易搞不到位置.
    {

        // ROS_INFO("Waiting for the move_base action server");
        // mbc.waitForServer(ros::Duration(60));
        // ROS_INFO("Connected to move base server");

        /*-----------------------------------------------------------------------------------------------set_pose-------------------------------------------------------------*/
        //这里认为去门就是去停车点，开始观察。
        set_pos(outdoor_pose,-5.08,-1.47,0.0102,0.0,0.0,-0.484099,0.875);//设置门的位置  甚至我可以去那个cab 我是不是可以去停车点，然后找到准确的车子,也就是一个识别的过程
        set_pos(shelf_pos,-4.5592753277,1.7243,0.0102,0.0,0.0,0.999,-0.01456);//设置储物柜位置,这个就是fetch的操作
        set_pos(wait_pos,-0.2711,0.9813,0.0102,0.0,0.0,0.9978,-0.0648);
        set_pos(last_pos,0,0,0 , 0.006,0.006,0.005,0.993);
        set_pos(driver_pos,-4.5,-2.5,0,0,0,-0.43,0.61);//最好有俯角仰角计算
        set_pos(indoor_pose,-4.5592753277,1.7243,0.0102,0.0,0.0,0.999,-0.01456);
        out_door_pose.pose.pose = outdoor_pose;
        /*-----------------------------------------------------------------------------------------------pub_msg-------------------------------------------------------------*/
        pub_command = nh.advertise<std_msgs::String>("/control_command",1000);
        sound_pub = nh.advertise<sound_play::SoundRequestActionGoal>("/sound_play/goal", 1000);
        pub =  nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);//发送停止信息
        pub_pose = nh.advertise<geometry_msgs::Pose>("cur_pose",1000);
        pub_est_pose = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose",1000);
        /*-----------------------------------------------------------------------------------------------sub_msg-------------------------------------------------------------*/
        sub_voice = nh.subscribe("voiceWords",1000,&fare_well::cb,this);//没有办法控制区段循环
        sub_cmd = nh.subscribe("/control_command", 1000,&fare_well::cmd_cb,this);//集成终端
        /*-----------------------------------------------------------------------------------------------control_signal-------------------------------------------------------------*/
        recognize_people=false;
        robot_go_to_the_shelf=false;
        robot_go_out_the_door=false;
        robot_go_back_to_the_door=false;
        robot_go_to_the_cab=false;
        robot_go_back_to_the_serving_place=false;
        robot_grasp_the_coat=false;
        robot_go_back_to_the_call_place=false;//一定要知道阻塞在哪一步了
        robot_go_to_the_door = false;
        //表示工作完成
        work_done=false;
        //以整体为一个完成单位
        work_begin = false;
        /*-----------------------------------------------------------------------------------------------回到最初的伺服点-------------------------------------------------------------*/
        tell_the_task(" ");//连接服务器。
        mbc.waitForServer();
        sleep(2);
        cmd_str="";
        if(work_begin==false)
        {
            go_to_serve_place();
        }
    }

/*--------------------------------------------------------------------------------这个节点实现异步控制运动状态，连接控制中枢 等下我会给出对应的节点分布图和节点功能图----------------------------------------------------------*/
void fare_well::order_command(std::string ss)
{
    cmd.data=ss;//关键
    pub_command.publish(cmd);
    sleep(1);
}
/*-------------------------------------------------------------------------------------------------语音相关操作-----------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------主要的说话节点-------------------------------------------------------------*/
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
    sleep(2);
}
/*-----------------------------------------------------------------------------------------------去往的地点操作-------------------------------------------------------------*/
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
            ROS_INFO("You  reached the goal!");
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
void fare_well::go_to_serve_place()
{
    tell_the_task("now i will go to the waiting place to wait your command!");
    ROS_INFO("now i will go to the waiting place to wait your command!");
    order_command("start listen");//这个用来唤醒监听节点
    go_to_place(this->wait_pos);
}
void fare_well::go_to_the_shelf()
{
    //前往shelf位置
    go_to_place(this->shelf_pos);
   
}
void fare_well::go_to_the_door()
{
    go_to_place(this->indoor_pose);
}
void fare_well::go_out_the_door()
{
    //回到呼唤点后准备出门
    go_to_place(this->outdoor_pose);//应该是到门外一点
    //然后开始导航建图.
}
void fare_well::go_to_the_driver()
{
    go_to_place(this->driver_pos);
}
//送完人之后回到原始等待位置
void fare_well::go_back_to_the_first_place()
{
    go_to_place(this->wait_pos);
}
/*-----------------------------------------------------------------------------------------------集成取回操作-------------------------------------------------------------*/
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
/*-----------------------------------------------------------------------------------------------导航反馈函数，可以修改的地方-------------------------------------------------------------*/
//过程反馈函数
void fare_well::feedbackcb(const move_base_msgs::MoveBaseFeedbackConstPtr & fb)//反馈控制函数,每次甚至可以不同导入不同的函数指针。。每次的反馈都不同
{
    if(is_equal(cmd_str,"task cancel"))
    {
        this->mbc.cancelAllGoals();
        return ;
    }
    cur_pose = fb->base_position.pose;
    geometry_msgs::Pose goal_pose = navi_goal.target_pose.pose;//通过计算空间距离来判断完成情况
    double cur_dis=get_distance(goal_pose,cur_pose);
    double eps=0.001;//单位为m,利用比较小的
    if(cur_dis<=eps)
    {
        //this->mbc.cancelAllGoals();//已经到了
        ROS_INFO("I  arrived the goal!");
    }
    pub_pose.publish(cur_pose);//发布当前的位姿信息
    //这个可以用所谓rqt_consel得到对应的信息,完全控制。
}
//激活反馈函数
void fare_well::activecb()
{
    ROS_INFO("actived");
}
//完成反馈函数
void fare_well::doneCallback(const actionlib::SimpleClientGoalState &state,
const move_base_msgs::MoveBaseResultConstPtr &result)
{  
    
}
/*-----------------------------------------------------------------------------------------------主要的信号控制流程------------------------------------------------------------*/
void fare_well::cmd_cb(const std_msgs::String::ConstPtr &msg)
{
    //我们应该可以导航到一个我们可以看得到的地方，然后去识别司机。。识别到司机之后就拿伞走人
    cmd_str = msg->data.c_str();
    //完成task1从启动到识别,这个可以考虑到一个固定位置
   /*----------------------------------------------------------------------------------------------任务一识别对应的人然后去柜子-------------------------------------------------------------*/
    if( work_begin && is_equal(cmd_str,"robot finish recognize the people")||is_equal(cmd_str,"robot  finish first task"))//大小写问题也要注意
    {
        robot_go_to_the_shelf = true;
        
        order_command("stop listen");
        tell_the_task("plase wait a minute , and i will take back your coat!");
        ROS_INFO("plase wait a minute , and i will take back your coat! ");
        get_present_pos(this->last_pos);
        go_to_the_shelf();//自己设置,应该会阻塞在这,到了之后应该发送对应的信息，说我到了，然后我就开始完成其他的操作
        
        robot_go_to_the_shelf = false;
        cmd_str = "";
        return ;
    }
    /*----------------------------------------------------------------------------------------------任务二取得对应的物品然后回去-------------------------------------------------------------*/
    //完成task2取得物品
    if( work_begin && is_equal(cmd_str,"robot  get the coat")||is_equal(cmd_str,"robot finish second task"))
    {
        robot_go_back_to_the_call_place = true;

        order_command("stop listen");
        
        tell_the_task("ready to go back to the calling place!");
        ROS_INFO("ready to go back to the calling place!");
        go_to_place(this->last_pos);//回到固定点之后可以考虑说走吧我们出去吧,到了地点之后就可以set_true了

        robot_go_back_to_the_call_place = false;
        
        
        tell_the_task("here is you coat");
        sleep(1);
        tell_the_task("are you ready to go out?");//等人穿衣服
        
        order_command("start listen");
        cmd_str = "";
        return ;
    }
    /*-----------------------------------------------------------------------------------------------任务三把衣服给对应的人然后出去-------------------------------------------------------------*/
    //如果已经拿好了东西，我就准备走了,必须能够在任何时候停止导航
    //这时候要把东西给对应的人 首先到门内位置然到门外位置
    //我们可以多次尝试然后用rosbag来播放 ,准备到门内 
    if(work_begin && is_equal(cmd_str,"robot ready to go to the door"))
    {
        robot_go_to_the_door = true;
        order_command("stop listen");

        go_to_the_door();
        
        order_command("robot will go out");
        robot_go_to_the_door = false;
    }
    //然后机器人准备到门外观察点去,采用两次导航出门
    if( work_begin && is_equal(cmd_str,"robot will go out"))
    {
        robot_go_out_the_door = true;

        tell_the_task("let's go out , i will take you to your cab");
        ROS_INFO("let's go out , i will take you to your cab ");
        //自己设置,这个就应该是导航到对应的点，然后在找司机的时候开启建图,等下我出去的时候gmapping似乎要一直开着，因为这次建的图会被刷新，那么这个图被刷新了怎么办？,gmapping会刷新地图,理解一下
        //假设我们要去一个没有地图的地方然后回来,或者我不开amcl直接开gmapping可不可以，如果可以那就没有问题，不用follow me 可以尝试一下 可以尝试不开gmapping 主要是固定位置扫描 出去没有必要开gmapping否则我回不去
        //或者说我出去不可能开gmapping否则我不可能知道位置然后也回不去所以就是一个导航,没有什么gmapping的过程，也没有follow的过程,进行测试发现不能开gmapping,除非gmapping是修补地图，否则不能用gmapping
        //比较关键的是导航的反馈 可以旋转识别人,如果不行我甚至可以导航到对应的位置,或者说amcl对应的map坐标系不同 因为我没有把地图发到对应的topic,或者我就是可以用gmapping不用amcl,没有必要切换,可以考虑一下
        go_to_the_door();

        //出门时刻的pose
        out_door_pose.pose.pose = cur_pose;//准备回归状态
        
        robot_go_out_the_door =false;
        cmd_str = "";
        return ;
    }
    //这个地方用gmapping
    if(work_begin && is_equal(cmd_str,"find the cab pose"))
    {
        robot_go_to_the_cab = true;
        order_command("close amcl");//这个很关键
        sleep(3);//等待状态切换,状态切换器
         order_command("start gmapping");//amcl关闭,回去之后切换为amcl,然后去一个固定位置
        //准备下一次利用gmapping的坐标系返回
        sleep(3);
        get_present_pos(this->last_pos);
        tell_the_task("this way please!");
        ROS_INFO("this way please!");
        sleep(5);//必须添加等待时间。。
        go_to_the_driver();//这个是当前坐标系下的driver
        order_command("robot arrive the cab");
        cmd_str = "";
        robot_go_to_the_cab =false;
    }
    /*-----------------------------------------------------------------------------------------------任务四通过识别到了位置然后取得雨伞准备回去-------------------------------------------------------------*/
    if( work_begin && is_equal(cmd_str,"robot arrive the cab"))//这个时候应该把东西放下，然后问是否可以回去，然后说回去吧
    {
        
        tell_the_task("thank you for your coming!");
        ROS_INFO("thank you for your coming!");
        tell_the_task("can you give me the umbrella?");
        sleep(5);
        order_command("start listen");
        cmd_str = "";
    }
    //这个就是所谓的可以回去了,放完东西然后问是不是可以回去了,应该是给人手上或者桌子上,这里要放东西
    //最后一件任务就是放东西,或者把行李给人,采用双通道控制每一个通道进入之后立刻阻塞第二个通道
    if( work_begin && is_equal(cmd_str,"robot get the umbrella")||is_equal(cmd_str,"robot  finish last task"))
    {
        order_command("stop listen");
        robot_go_back_to_the_door = true;
        tell_the_task("get back the door!");
        ROS_INFO("get back the door!");
        go_to_place(this->last_pos);//回到接口点,这个地方必须回到初始点
        robot_go_back_to_the_door =false;
        order_command("close gmapping");
        sleep(5);
        order_command("start amcl");//开始导航回去 原来一直是gmapping的
        //接口位姿恢复,自动化位姿恢复技术,等下晚上来总结一下相关内容。
        for(int i=1;i<=10;i++)//10次位姿矫正
       { pub_est_pose.publish(out_door_pose);//进行位姿恢复
         sleep(1);
       }
        cmd_str ="";
    }
    if(work_begin && is_equal(cmd_str,"start amcl"))
        {//程序冲突才坑。。
        sleep(5);
        pub_est_pose.publish(out_door_pose);//进行位姿恢复
         robot_go_back_to_the_serving_place = true;
        // tell_the_task("get back to the serving place!");
        // ROS_INFO("get back to the serving place!");
        // go_to_serve_place(); //一直在这个地方等着消息,从接口点回去,但是最好向后旋转一段
        //准备开始对话,进入新的一轮工作,增强阻塞思想，利用work_done等bool信号阻塞无效操作保证每次都在正常的操作过程中

        go_to_serve_place();
        order_command("start listen");
        robot_go_back_to_the_serving_place = false;
        //回归最初状态
        work_begin = false;
        work_done = true;
        // tell_the_task("get back to the serving place!");
        // ROS_INFO("get back to the serving place!");
        
        cmd_str = "";
        }

}
/*-----------------------------------------------------------------------------------------------语音控制反馈，我主流全部用语音控制-------------------------------------------------------------*/
void fare_well::cb(const std_msgs::String::ConstPtr & msg )
    {
        std::string voice_command;
        voice_command = msg->data.c_str();
        cout<<voice_command<<endl;
       /*-----------------------------------------------------------------------------------------------语音开启机器人运动-------------------------------------------------------------*/
       if(is_equal(voice_command,"i want to go")||is_equal(voice_command,"take me out"))
       {
           order_command("stop listen");
           tell_the_task("task confirmed!");
           //认清是谁做好标记，这里交给视觉识别
           tell_the_task("start recognizing");
           ROS_INFO("start recognizing");
           //开始工作
           work_begin = true;
           work_done = false;
       }
      /*-----------------------------------------------------------------------------------------------控制出门节点，准备到门的内部区域-------------------------------------------------------------*/
       //确定人是否想走,如果想走，那么我们就出去，其实我可以导航到固定的点，然后定点扫描,也就是不可能是follow,因为要我引导别人，就是说我要知道我要去哪，然后我要知道我要识别谁,我导航过去之后要能够回来,最后应该把雨伞取回来
       if(work_begin && is_equal(voice_command,"we can go out")||is_equal(voice_command,"go out"))
       {
           order_command("stop listen");
           order_command("robot ready to go to the door");//硬控
       }
     /*-----------------------------------------------------------------------------------------------最后一次语音通信控制他们离开-------------------------------------------------------------*/
       if(work_begin && is_equal(voice_command,"you can go back")||is_equal(voice_command,"go back"))
       {
           order_command("robot  finish last task");
       }

    }
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "set_goal");//通过接收信息发送出去goal的指令
    fare_well test;
    ros::spin();
    return 0;
}
