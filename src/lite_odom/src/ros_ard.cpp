/*
 * ros_ard.cpp
 *
 * Takes all encoder values and processes their calculations here giving individual motor velocities as commands. 
 *
 * Author: P,Abhiyan, IGVC
 */

#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <litemsgs/lite.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <math.h>
#include <stdlib.h>
#include "std_msgs/UInt32.h"





ros::Publisher odom_pub;

void RticksCallback( const std_msgs::UInt32::ConstPtr & tpsR ) {
   // TicksPerSecond 
 ROS_INFO("I heard tpsR");
}

void LticksCallback( const std_msgs::UInt32::ConstPtr & tpsL ) {
   // TicksPerSecond 
  ROS_INFO("I heard tpsL");
}





void odom_cb( const litemsgs::lite::ConstPtr & msg ) {
   static tf::TransformBroadcaster odom_tf;
   // odometry message
   nav_msgs::Odometry out;
   out.pose.pose = msg->pose;
   out.twist.twist = msg->twist;
   out.header = msg->header;
   out.child_frame_id = msg->child_frame_id;

   odom_pub.publish(out);

   // tf transform
   geometry_msgs::TransformStamped transform;
   transform.header = msg->header;
   transform.child_frame_id = msg->child_frame_id;
   transform.transform.translation.x = msg->pose.position.x;
   transform.transform.translation.y = msg->pose.position.y;
   transform.transform.translation.z = msg->pose.position.z;
   transform.transform.rotation = msg->pose.orientation;
   odom_tf.sendTransform(transform);
}

int main(int argc, char ** argv) {

   ros::init(argc, argv, "ros_ard");

   ros::NodeHandle n;
	
   ros::Subscriber sR = n.subscribe("tpsR", 100, &RticksCallback);
   ros::Subscriber sL = n.subscribe("tpsL", 100, &LticksCallback);


   ros::Subscriber sodom = n.subscribe("gagan", 2, &odom_cb);

   odom_pub = n.advertise<nav_msgs::Odometry>("odom", 2);

   ros::spin();
}

