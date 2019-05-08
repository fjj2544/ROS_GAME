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