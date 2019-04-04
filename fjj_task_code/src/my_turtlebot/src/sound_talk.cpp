/**
 * 该例程将发布chatter话题，消息类型String
 */
 
#include <sstream>
#include "ros/ros.h"
#include "sound_play/SoundRequestActionGoal.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "sound_talk");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
    ros::Publisher chatter_pub = n.advertise<sound_play::SoundRequestActionGoal>("/sound_play/goal", 1000);

    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // 初始化std_msgs::String类型的消息
        std_msgs::String msg;
        sound_play::SoundRequestActionGoal temp;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        temp.goal.sound_request.arg="hello world";
        temp.goal.sound_request.arg2="voice_kal_diphone";
        temp.goal.sound_request.sound=-3;
        temp.goal.sound_request.volume=1.0;
        temp.goal.sound_request.command=1;
        // 发布消息
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(temp);

        // 循环等待回调函数
        ros::spinOnce();

        // 按照循环频率延时
        loop_rate.sleep();
        ++count;
    }

    return 0;
}