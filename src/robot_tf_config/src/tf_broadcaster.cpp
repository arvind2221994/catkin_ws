// Broadcasting a Transform


#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(50);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.25, 0.0, 0.41)),
        ros::Time::now(),"base_link", "base_laser"));		/*For LiDAR scans*/
	
     broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.4)),
        ros::Time::now(),"base_link", "cam_laser"));      /*For images as laser scan*/
     
     broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, -0.195)),
        ros::Time::now(),"base_link", "base_footprint"));      /*Base footprint for IMU*/
    r.sleep();
  }
}
