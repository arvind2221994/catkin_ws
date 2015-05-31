#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <maiss_nav/ObservedState.h>
#include <move_base_msgs/MoveBaseActionResult.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <math.h>
#include <stdlib.h>



using namespace ros;
using namespace move_base_msgs;



typedef actionlib::SimpleActionClient<MoveBaseAction> MoveBaseClient;



class StuckRobotMonitor
{
  private:
    /// Callbacks
    void resultReceivedCallback (const MoveBaseActionResult& msg);
    void currentGoalCallback (const MoveBaseActionGoal& msg);
    
    NodeHandle n_;
    
    
    
    Subscriber result_sub_;
    Subscriber goal_sub_;
    Publisher goal_pub_;
    boost::shared_ptr<MoveBaseClient> mb_client_;
    
  public:
    StuckRobotMonitor() :
      n_(),
      result_sub_ (n_.subscribe ("move_base/result", 1, &StuckRobotMonitor::resultReceivedCallback, this)),
      goal_sub_ (n_.subscribe ("move_base/goal", 1, &StuckRobotMonitor::currentGoalCallback, this)),
      mb_client_ (new MoveBaseClient ("move_base", true)) {
      mb_client_->waitForServer();
    }
    
    MoveBaseGoal currentGoal_;
    
    ~StuckRobotMonitor() {}
};



/** Callback to receive a robot pose.
    The estimation of the state is only published when a robot pose is received.
*/
void StuckRobotMonitor::resultReceivedCallback (const MoveBaseActionResult& msg)
{
  if (msg.status.status == 4) { // robot is stuck, re-send the last goal to force it to move (if possible)
    ROS_ERROR ("Resending goal");
    
    mb_client_->sendGoal (currentGoal_);
  }
}



void StuckRobotMonitor::currentGoalCallback (const MoveBaseActionGoal& msg)
{
  currentGoal_ = msg.goal;
}



/// Main loop
int main (int argc, char** argv)
{
  init (argc, argv, "stuck_robot_monitor");
  
  StuckRobotMonitor srm;
  
  spin();
  
  return 0;
}
