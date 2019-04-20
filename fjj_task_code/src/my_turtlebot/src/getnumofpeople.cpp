#include <boost/thread.hpp>
#include "sound_play/SoundRequestActionGoal.h"
#include <sstream>
#include "ros/ros.h"
#include "sound_play/SoundRequestActionGoal.h"
#include "std_msgs/String.h"
#include "opencv_apps/FaceArrayStamped.h"
#include <string.h>
#include <strings.h>
#include <iostream>
#include "std_msgs/String.h"
ros::Subscriber sub;
ros::Publisher pub;
int last_num=-1;
void callback(const opencv_apps::FaceArrayStampedConstPtr & num)
{
  sound_play::SoundRequestActionGoal output;
  std::stringstream ss;
  std_msgs::String num_str;
  int num_of_people=int(num->faces.size());
  if(num_of_people==last_num)
  {
    return ;
  }
  else
  {
  last_num=num_of_people;
  ss<<num_of_people<<" people";
  num_str.data = ss.str();
  output.goal.sound_request.arg=num_str.data.c_str();
  output.goal.sound_request.arg2="voice_kal_diphone";
  output.goal.sound_request.sound=-3;
  output.goal.sound_request.volume=1.0;
  output.goal.sound_request.command=1;
  ROS_INFO("%s\n\n",num_str.data.c_str());
  pub.publish(output);
  return ;
  }
}
int main(int argc, char *argv[])
{
  ros::init(argc, argv, "getnumofpeople");
  ros::NodeHandle nh;
  pub = nh.advertise<sound_play::SoundRequestActionGoal>("/sound_play/goal", 1000); 
  sub = nh.subscribe("/face_detection/faces",1,callback);
  ros::spin();
  return 0;//识别精度和及时性有问题。
}