#include "ros/ros.h"
#include"msg_demo/srv_demo.h"//这个就是我建立的服务
bool add(msg_demo::srv_demo::Request &req,msg_demo::srv_demo::Response &res)
{
    res.sum=req.a+req.b;
    ROS_INFO("You want to konw the sum of x=%ld,y=%ld",(long int)req.a,(long int )req.b);
    ROS_INFO("Sending back to you the answer:[%ld]",(long int )res.sum);
    return true;//因为不是返回结果所以需要引用传递才能修改对应的值。
    //分开响应和返回值。
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "add_server");//节点的名称，节点通信需要向master注册
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("add_two_ints",add);//callback function
    ROS_INFO("ready to add two ints.");//本来就可以当成cpp程序来写，cpp程序换一个外壳就可以用ros跑
    ros::spin();//不断的等待请求，类似于whilespinonce
    return 0;
}
//建立的时候不能有空白文件