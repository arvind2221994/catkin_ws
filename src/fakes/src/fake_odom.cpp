#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_publisher");

  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
  tf::TransformBroadcaster odom_broadcaster;

  double x = 0.0;
  double y = 0.0;
  double th = 0.0;

  double vrealx = 0.1,vx;
  double vrealy = 0.1,vy;
  double vth = 0.0;
  int length=1;
  double l=0.0;
  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();

  ros::Rate r(30.0);
  while(n.ok()){

    ros::spinOnce();               // check for incoming messages
    current_time = ros::Time::now();

    //compute odometry in a typical way given the velocities of the robot
    double dt = (current_time - last_time).toSec(); 
    //double delta_x = (vx * cos(th) - vy * sin(th)) * dt;
    //double delta_y = (vx * sin(th) + vy * cos(th)) * dt;
    double delta_x,delta_y,delta_th=0;
    /*
    //straight and right
    if(y<=3)
    { 
       th=3.14159/2.0;
       delta_x = 0;
       delta_y = vy*dt;
       x += delta_x;
       y += delta_y; 
       //th += delta_th;
    }
    else
    if(x<3)
    {
       th=0;
       delta_x = vx*dt;
       delta_y = 0;
       x += delta_x;
       y += delta_y;
       //th += delta_th;
    }*/
    // square spiraling outwards
    if((int)l==length)
    {
        l=0.0;
        length++;
        if(length%4==0)
        {
            th=3.14159; 
        }
        else
        if(length%4==1)
        {
            th=3.14159/2.0;
        }
        else
        if(length%4==2)
        {
            th=0;
        } 
        else
        {
            th=3.0*3.14159/2.0;
        }
    }
    if(length%2==1)
    {
        delta_x==0;
        vx=0;
        vy=vrealy;
        delta_y=vrealy*dt;
        if(length%4==1)
        {
            y+=delta_y;
	}
	else
            y-=delta_y;
        l+=delta_y;
    }
    else
    {
        delta_y==0;
        vy=0;
        vx=vrealx;
        delta_x=vrealx*dt;
        if(length%4==2)
        {
            x+=delta_x;
	}
	else
            x-=delta_x;
        l+=delta_x;
    }
        
    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;
    
    //set the pose covariance
    for (int i=0;i<36;i++)
    {
                if(i==0 || (i>5 && i%7 == 0)){
                    odom.pose.covariance[i]=0.01;
                }else
                    odom.pose.covariance[i]=0.00;
   }

    //set the velocity
    odom.child_frame_id = "base_link";
    odom.twist.twist.linear.x = vx;
    odom.twist.twist.linear.y = vy;
    odom.twist.twist.angular.z = vth;

    //set the twist covariance
   for (int i=0;i<36;i++)
   {
          if(i==0 || (i>5 && i%7 == 0)){
                odom.twist.covariance[i]=0.01;
          }
          else
                odom.twist.covariance[i]=0.00;
   }


    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;
    r.sleep();
  }
}
