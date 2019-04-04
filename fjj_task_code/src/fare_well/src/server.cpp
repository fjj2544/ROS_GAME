#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>

#include <fare_well/testConfig.h>

void callback(fare_well::testConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %d %f %s %s %d", 
            config.int_param, config.double_param, 
            config.str_param.c_str(), 
            config.bool_param?"True":"False", 
            config.size);
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "server");

    dynamic_reconfigure::Server<fare_well::testConfig> server;
    dynamic_reconfigure::Server<fare_well::testConfig>::CallbackType f;

    f = boost::bind(&callback, _1, _2);
    server.setCallback(f);

    ROS_INFO("Spinning node");
    ros::spin();
    return 0;
}
