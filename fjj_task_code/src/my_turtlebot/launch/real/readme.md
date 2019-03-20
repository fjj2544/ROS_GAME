现在可以发现基本的真实机器人仅仅是需要把传感器驱动和最小启动开启，那么机器人的模型可以自动加载，机器人的每一个传感器不一定能够完全的在rviz中显示出来
不过我们可以得到对应的传感器信息输出出来就好了，没有必要把所有的信息考虑1：1对称传输。]

仅仅以turtlebot 而言基本上就是源码包里面的启动方案.

基本上都是robot_state_publish发布了相关的tf坐标变换树

应该考虑解决这个 导航中比较困难的问题的分析。

1 能不能有地图？也就是内部地图和外部地图哪一个可以有？哪一个必须现场建立？
2 到底是人跟随机器人还是机器人跟随人？也就是应该是护送而不是引导，不是带领，也就是这个的主要难点是护送也就是人机协同。。那么识别司机有什么用处？也就是尽量避免减分。首先实现一个最基本的可能就是follow 去耦合化，目标单一化
4.2. Guiding to the cab location: Guiding the robot to the cab causes 40pts of score
reduction.
4.3. Guiding back to the house: Guiding the robot back to the arena causes 40pts of
score reduction.
下面这个就是难点 一开始尽量简化问题，问题分步。

总体计划书
短期目标
长期目标
希望解决的问题
技术路线


