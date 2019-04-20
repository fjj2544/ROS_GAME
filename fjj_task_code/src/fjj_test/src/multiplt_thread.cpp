#include "ros/ros.h"
#include"iostream"

int main(int argc, char *argv[])
{
    ros::MultiThreadedSpinner spiner(4);
    spiner.spin();
    return 0;
}