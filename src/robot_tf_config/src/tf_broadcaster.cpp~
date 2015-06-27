// Broadcasting a Transform


#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.25, 0.0, 0.35)),
        ros::Time::now(),"base_link", "base_laser"));		/*For LiDAR scans*/
	
     broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.20, 0.0, 0.45)),
        ros::Time::now(),"base_link", "laser_frame"));      /*For images as laser scan*/
    r.sleep();
  }
}
