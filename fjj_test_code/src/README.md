程序清单

```cpp
set_goal.cpp     //功能集成化的核心节点，完成了整个流程的导航任务
open_voice.cpp   //语音唤醒节点
iat_publish.cpp  //语音识别节点
control_core.cpp //核心控制节点，处理大部分的控制信号
empty_node.cpp   //空节点，可以实现状态切换
```

仿真的步骤如下：

```bash
roslaunch fare_well fake_turtlebot_nav.launch             ##仿真环境
roslaunch test robot_voice.launch                         ##打开语音识别和语音输出
roslaunch fare_well amcl_demo.launch                      ##开启导航

rosrun test control_core                                  ##打开核心控制节点
rosrun test set_goal                                      ##打开核心操作节点

rostopic pub /voiceWords std_msgs/String "data: 'i want to leave'" 
rostopic pub /control_command std_msgs/String "data: 'robot finish recognize guest'" 
rostopic pub /control_command std_msgs/String "data: 'robot  get the coat'" 
rostopic pub /voiceWords std_msgs/String "data: 'go out'" 
rostopic pub /control_command std_msgs/String "data: 'robot arrive the cab'"
rostopic pub /voiceWords std_msgs/String "data: 'you can go back'" 
```

真实运行时导航和语音部分测试步骤如下：

```bash
roslaunch fare_well real_robot_bringup_with_kinect.launch ##启动机器人
roslaunch test robot_voice.launch                         ##打开语音识别和语音输出
roslaunch fare_well amcl_demo.launch                      ##开启导航

rosrun test control_core                                  ##打开核心控制节点
rosrun test set_goal                                      ##打开核心操作节点

rostopic pub /voiceWords std_msgs/String "data: 'i want to leave'" 
rostopic pub /control_command std_msgs/String "data: 'robot finish recognize guest'" 
rostopic pub /control_command std_msgs/String "data: 'robot  get the coat'" 
rostopic pub /voiceWords std_msgs/String "data: 'go out'" 
rostopic pub /control_command std_msgs/String "data: 'robot arrive the cab'"
rostopic pub /voiceWords std_msgs/String "data: 'you can go back'" 
```

必要的硬件

```
hokuyo
kinect || astra
```



必要的软件依赖

```

```



