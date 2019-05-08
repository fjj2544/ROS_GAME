
#include <ros/ros.h>
#include <ros/console.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/simple_client_goal_state.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/String.h>

  typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ActionClient;

  class NavGoalManager {
    public:
      /**
       * @brief: Constructor for the goal manager.
       */
      NavGoalManager();

      /**
       * @brief: Handler for new goals sent to the basic interface.
       */
      void goalSimple(const geometry_msgs::PoseStamped::ConstPtr& goal);

      /**
       * @brief: Handler for cancelation signals sent to the basic interface.
       */
      void cancelSimple(const std_msgs::String::ConstPtr& goal);

     private:
      ActionClient actionClient;
      ros::Subscriber goal_sub_;
      ros::Subscriber cancel_sub_;
      ros::NodeHandle goal_sub_nh;
    public:
      // Probably some internal helper methods.
      void doneCallback(const actionlib::SimpleClientGoalState &state,
                        const move_base_msgs::MoveBaseResultConstPtr &result);
      void feedbackcb(
          const move_base_msgs::MoveBaseFeedbackConstPtr & fb);
      void activefb();
  };


  NavGoalManager::NavGoalManager():actionClient("move_base",true){
    // Subscribe to the simple goal message.
    ROS_INFO("To register subcribers");
    goal_sub_nh = ros::NodeHandle("nav_manager");
    goal_sub_ = goal_sub_nh.subscribe<geometry_msgs::PoseStamped>("goal", 1, boost::bind(&NavGoalManager::goalSimple, this, _1));
    cancel_sub_ = goal_sub_nh.subscribe<std_msgs::String>("cancel", 1, boost::bind(&NavGoalManager::cancelSimple, this, _1));

    ROS_INFO("To start action lib");
    // Connect to the move_base action server
   // actionClient = new ActionClient("move_base", true); // create a thread to handle subscriptions.
    actionClient.waitForServer();
    ROS_INFO("Server found");

  }

  void NavGoalManager::goalSimple(const geometry_msgs::PoseStamped::ConstPtr& goal) {
    ROS_INFO_NAMED("nav goal manager","Goal Callback. Resending to move_base.");
    // We should cancel previous goals here.
    move_base_msgs::MoveBaseGoal action_goal;
    action_goal.target_pose.header = goal->header;
    action_goal.target_pose.pose = goal->pose;
    actionClient.sendGoal(action_goal,
                           boost::bind(&NavGoalManager::doneCallback, this, _1, _2),
                           boost::bind(&NavGoalManager::activefb, this),
                           boost::bind(&NavGoalManager::feedbackcb, this, _1));
  }
  void NavGoalManager::feedbackcb(const move_base_msgs::MoveBaseFeedbackConstPtr & fb)
  {}
  void NavGoalManager::doneCallback(const actionlib::SimpleClientGoalState &state,
                                    const move_base_msgs::MoveBaseResultConstPtr &result) {
  }
  
void NavGoalManager::activefb(){

}
  void NavGoalManager::cancelSimple(const std_msgs::String::ConstPtr& goal) {
    ROS_INFO_NAMED("nav goal manager","Cancel Callback. Resending to move_base.");
    // We should cancel previous goals here.
    actionClient.cancelAllGoals();
  }

void subCallback(const std_msgs::StringConstPtr &msg)
{
    std::string mystr=msg->data;
    if(mystr.compare("shut down")==0)
    { 
      ROS_INFO("I am here!");
      ros::shutdown();
    }
}
int main(int argc, char *argv[])
{
  ros::init(argc, argv, "my_test");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("control_command", 1000, subCallback);
  ros::spin();
  return 0;
}