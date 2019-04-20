这里是ros基本的知识点总结，包括相关知识点内容以及相关的最优解决方案，最关键就是python和从cpp转换，循环分支，节点收发，同步性、异步性。

# `ros::spinOnce`

只能监听不能循环，结合`ros::ok`可以实现控制速度的监听反馈函数（也就是控制sub中的反馈）

```c++
ros::Rate loop_rate(10);
while(ros::ok())
{
    ros::spinOnce();
    loop_rate.sleep();
}
```

也就是不管是spin还是spinOnce都是针对sub回调而言的，并不是循环发送，甚至循环整个程序。也就是如果程序仅仅是发布话题可以不加上这个spin因为没有任何作用。

