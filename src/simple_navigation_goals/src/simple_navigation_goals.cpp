#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move forward as given
  goal.target_pose.header.frame_id = "odom";
  goal.target_pose.header.stamp = ros::Time::now();

  int x=0,y=0;
  int w=1;
  if(argc > 1){
  	ROS_INFO("x:");
  	ROS_INFO(argv[1]);
  sscanf(argv[1],"%d", &x);
  }
  if(argc > 2){
  	ROS_INFO("y:");
  	ROS_INFO(argv[2]);
  sscanf(argv[2],"%d", &y);
  }
  if(argc > 3){
  	ROS_INFO("w:");
  	ROS_INFO(argv[3]);
  sscanf(argv[3],"%d", &w);
  }

  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;
  goal.target_pose.pose.position.z = 0.0;
  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = 0.0;
  goal.target_pose.pose.orientation.w = w;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ROS_INFO("Goal sent!");
  while(ac.waitForResult(ros::Duration())){
    ROS_INFO("Waiting for result...");
   //ros::Duration(0.5).sleep(); // sleep for half a second
  }
  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved forward. Put treat!");
  else
    ROS_INFO("The base failed to move forward for some reason. Check again!");

  return 0;
}


