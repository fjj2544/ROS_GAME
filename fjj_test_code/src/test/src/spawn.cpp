#include<geometry_msgs/Twist.h>
#include<ros/ros.h>
#include<iostream>
#include<map>
//下面是实现kbhit的
#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include<iostream>


using namespace std;


static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyboard();
void close_keyboard();
bool kbhit();
char readch();
void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}
void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}
bool kbhit()
{
    char ch;
    int nread;
    if(peek_character != -1)
        return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1) {
      peek_character = ch;
      return 1;
    }
    return 0;
}
char readch()
{
    char ch;
    if(peek_character != -1) {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}


geometry_msgs::Twist vel_cmd;//全局的速度
double v_scale=1.0,w_scale=1.0;
char last_key;//记录便于处理
/*
定义加速和减速
Q E分别加速线速度和角速度
Z C分别减速线速度和角速度
*/
map<int,char> kb_key;
void init()
{
    for(char i='0';i<='9';i++)
    {
        kb_key[int(i)]=i;
    }
    for(char i='A';i<='Z';i++)
    {
        kb_key[int(i)]=i;
    }
    for(char i='a';i<='z';i++)
    {
        kb_key[int(i)]=i;
    }
}
void set_vel(geometry_msgs::Twist &object ,double v_x,double v_y,double v_z,double w_x,double w_y,double w_z )
{
    object.linear.x=v_x;
    object.linear.y=v_y;
    object.linear.z=v_z;
    object.angular.x=w_x;
    object.angular.y=w_y;
    object.angular.z=w_z;    
}//利用键盘控制节点控制速度..
//确定规则
/*
WASD
上下左右
Q E 加速减速
*/
void key_cb(int ch)
{
    switch (kb_key[ch])
    {
        case 'q':
        case 'Q':
            {
               
                w_scale *=1.0;
                v_scale *= 1.1;
                ROS_INFO("linear speed up!");
            }
            break;
        case 'w':
        case 'W':
             {
                 
                 set_vel(vel_cmd,1.0,0,0, 0,0,0);//只要没有点就没有速度
                  ROS_INFO("go straight!");
             }
            break;
        case 'e':
        case 'E':
            {   
                w_scale *=1.1;
                v_scale *=1.0;
                 ROS_INFO("angular speed up!");
            }
            break;
        case 'a':
        case 'A':
             {
                 
                 set_vel(vel_cmd,0,0,0, 0,0,1.0);//只要没有点就没有速度

                  ROS_INFO("turn left!");
             }
            break;
        case 's':
        case 'S':
           {   
                ROS_INFO("go backward!");
               set_vel(vel_cmd,-1.0,0,0, 0,0,0);//只要没有点就没有速度
           }
            break;
        case 'd':
        case 'D':
            {
                 ROS_INFO("turn right!");
                set_vel(vel_cmd,0,0,0, 0,0,-1.0);//只要没有点就没有速度
                
            }
            break;
        case 'z':
        case 'Z':
            {   
                 ROS_INFO("linear speed down !");
                w_scale*=1.0;
                v_scale*=0.9;//每次敲击才会有速度?还是一开始就有速度?
            }
            break;
        case 'c':
        case 'C':
            {   
                 ROS_INFO("angular speed up!");
                w_scale*=0.9;
                v_scale*=1.0;//每次敲击才会有速度?还是一开始就有速度?
            }
            break;
        case 'r':
        case 'R'://自旋转,顺时针
            {   
                 ROS_INFO("let spin !");
                set_vel(vel_cmd,0,0,0, 0,0,-1.0);//只要没有点就没有速度
            }
            break;
            
        default:
        {
            w_scale=0.0;
            v_scale=0.0;//每次敲击才会有速度?还是一开始就有速度?
        }
    }
    set_vel(vel_cmd ,vel_cmd.linear.x*v_scale
                    ,vel_cmd.linear.y*v_scale
                    ,vel_cmd.linear.z*v_scale
                    ,vel_cmd.angular.x*w_scale
                    ,vel_cmd.angular.y*w_scale
                    ,vel_cmd.angular.z*w_scale);//每次敲击键盘都会加一次速,不会一直加速,直到一下次敲击键盘才会加速

                    ROS_INFO("current linear_x:%f\n",vel_cmd.linear.x);
                    ROS_INFO("current linear_y:%f\n",vel_cmd.linear.y);
                    ROS_INFO("current linear_z:%f\n",vel_cmd.linear.z);
                    ROS_INFO("current angular_x:%f\n",vel_cmd.angular.x);
                    ROS_INFO("current angular_y:%f\n",vel_cmd.angular.y);
                    ROS_INFO("current angular_z:%f\n",vel_cmd.angular.z);
                    ROS_INFO("current linear_a:%f\n",v_scale);
                    ROS_INFO("current angular_a:%f\n",w_scale);
}
void get_key()
{
    int ch;
    if(kbhit())
    {
        ch = readch();
        if(ch==3||ch==26)//return ; exit
        {
            last_key=ch;
            return ;
        }
        //采用WASD的方法
        key_cb(ch);
        last_key = ch;
    }
    else
    {
        if(last_key=='R'||last_key=='r')//实现一个旋转的控制
            {
                ROS_INFO("You're now spinning!");
            }
        else
            set_vel(vel_cmd,0,0,0, 0,0,0);//只要没有点就没有速度
    }
}
//功能实现了但是有一定的阻塞.
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "spawn");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
    set_vel(vel_cmd,0,0,0, 0,0,1);
    ros::Rate loop_rate(10);
    init();
    init_keyboard();
    while(ros::ok()&&last_key!=3&&last_key!=26)//ctrl+c ctrl+z
    {
        get_key();//响应键盘事件
        pub.publish(vel_cmd);
        loop_rate.sleep();
        ros::spinOnce();
    }
    close_keyboard();
    return 0;
}
