/*
 * dagny_odom.cpp
 *
 * Take simple odometry messages and republish them as full Odometry messages
 *  and as a tf transform
 *
 * Author: Austin Hendrix
 */

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <litemsgs/lite.h>
#include <tf/transform_broadcaster.h>

ros::Publisher odom_pub;

void odom_cb( const litemsgs::lite::ConstPtr & msg ) {
   static tf::TransformBroadcaster odom_tf;
   // odometry message
   nav_msgs::Odometry out;
   out.pose.pose = msg->pose;
   for (int i=0;i<36;i++)
   {
		if(i==0 || (i>5 && i%7 == 0))
		out.pose.covariance[i]=0.01;
		else
		out.pose.covariance[i]=0.00;
   }

   out.twist.twist = msg->twist;
   for (int i=0;i<36;i++)
   {
          if(i==0 || (i>5 && i%7 == 0))
		out.twist.covariance[i]=0.01;
		else
		out.twist.covariance[i]=0.00;
   }

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
   ros::init(argc, argv, "modif_odom");

   ros::NodeHandle nh;

   ros::Subscriber s = nh.subscribe("odom_sub", 2, &odom_cb);
   ROS_INFO("bhavya!!!");
   odom_pub = nh.advertise<nav_msgs::Odometry>("odom", 2);

   ros::spin();
}

