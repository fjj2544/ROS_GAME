#include<ros/ros.h>
#include<std_msgs/Float64.h>
#include<math.h>
using namespace std;
const double pi = 4*atan(1.0);
double th1,th2,th3;
double temp_th;
const  double l1=10.5,l2=10.5,l3=7.0;
void cal_th1(double x, double y);
void cal(double x ,double y)
{
    th3 = -1.56;
    x =  x + l3*sin(th3);
    y = y - l3*cos(th3);
    double temp2 = x*x+y*y-l1*l1-l2*l2;
    temp2 = temp2 /(2*l1*l2);
    th2 = acos(temp2);
    double temp = l2*l2 - (x*x+y*y) - l1*l1;
    temp = temp /(-2*l1*sqrt(x*x+y*y));
    temp_th = acos(temp); 
    cal_th1(x,y);
}
void cal_th1(double x, double y)
{
    
    if(th2>0)
    {
        th1=atan(y/x)-temp_th;

    }
    else if(th2<0)
    {
        th2=atan(y/x)+temp_th;
    }

}

int main(int argc, char *argv[])
{
    //x y 测试 对于对应的位置给出设计角度 发送一次到不了这个位置
    ros::init(argc, argv, "control_arm");
    ros::NodeHandle nh;
    ros::Publisher pub_joint1 = nh.advertise<std_msgs::Float64>("/waist_controller/command", 1000);
    ros::Publisher pub_joint2 = nh.advertise<std_msgs::Float64>("/shoulder_controller/command", 1000);
    ros::Publisher pub_joint3 = nh.advertise<std_msgs::Float64>("/elbow_controller/command", 1000);
    ros::Publisher pub_joint4 = nh.advertise<std_msgs::Float64>("/wrist_controller/command", 1000);
    ros::Publisher pub_joint5 = nh.advertise<std_msgs::Float64>("/hand_controller/command", 1000);
    std_msgs::Float64 joint1,joint2,joint3,joint4,joint5;
    cal(10,20);
    cout<<th1<<endl;
    cout<<th2<<endl;
    ros::Rate loop_rate(1);
    while(ros::ok())
    {
    joint1.data = 1.565;
    joint2.data = th1;
    joint3.data = th2;
    joint4.data = th3;
    joint5.data = 0.0;
    pub_joint1.publish(joint1);
    pub_joint2.publish(joint2);
    pub_joint3.publish(joint3);
    pub_joint4.publish(joint4);
    pub_joint5.publish(joint5);
    loop_rate.sleep();
    ros::spinOnce();
    }
    return 0;
}   

/*
position: 
  x: -5.08212408378
  y: -1.47231815819
  z: 0.0102
orientation: 
  x: 0.0
  y: 0.0
  z: -0.484099946876
  w: 0.875012709299
---
*/

/*
position: 
  x: -0.27111253374
  y: 0.981326511646
  z: 0.0102
orientation: 
  x: 0.0
  y: 0.0
  z: 0.9978969046
  w: -0.0648210443463
---

*/
/*
position: 
  x: -4.55922753277
  y: 1.72430599082
  z: 0.0102
orientation: 
  x: 0.0
  y: 0.0
  z: 0.999892354475
  w: -0.0146724048193
---
*/