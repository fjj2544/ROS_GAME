#include<ros/ros.h>
using namespace std;
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "empty_node");
    ros::spin();
    return 0;
}
