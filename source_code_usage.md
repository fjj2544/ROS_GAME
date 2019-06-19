```bash
roslaunch fare_well amcl_demo.launch # start navigation
roslaunch fare_well real_robot_bringup_with_kinect.launch #start the robot
roslaunch test robot_voice.launch #open speak and listen node
rosrun test control_core # open control node
### before start this node you must adjust your position in RVIZ for instance:rosrun rviz rviz
rosrun test set_goal # major program
```





