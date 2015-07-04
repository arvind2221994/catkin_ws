#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <razor_imu_9dof/RazorImu.h>

#include <sstream>
#include <fcntl.h>
#include <termios.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SERIALPORT "/dev/ttyUSB0"
#define DEFAULT_BAUDRATE 57600

#define DEG2RAD M_PI/180

//NOTE::Start reading from the main then onto the rcvThread function it helps :)
// Global data
FILE *fpSerial = NULL; // serial port file pointer

//Publishers for data 
ros::Publisher pubRazorImu;// yaw, pitch, roll (not used in code but can be done)
ros::Publisher pubImu;     // ros imu sensor message 
ros::Publisher pubMag;     // ros mag sensor message (not working presently)
int rzIndex; // index number
int fd = -1;

// Receive responses from Razor imu
// and publish as a ROS message
void *rcvThread(void *arg)
{
  razor_imu_9dof::RazorImu rz;
  sensor_msgs::Imu msg_imu;
  
  //Please be carefull this maybe wrong <<< error possible
  msg_imu.orientation_covariance[0] = 999999;
  msg_imu.orientation_covariance[4] = 9999999;
  msg_imu.orientation_covariance[8] = 999999;
  msg_imu.angular_velocity_covariance[0] = 9999;
  msg_imu.angular_velocity_covariance[4] = 9999;
  msg_imu.angular_velocity_covariance[8] = 0.02;
  msg_imu.linear_acceleration_covariance[0] = 0.2;
  msg_imu.linear_acceleration_covariance[4] = 0.2;
  msg_imu.linear_acceleration_covariance[8] = 0.2;

  int rcvBufSize = 500;
  char imuData[rcvBufSize];   //received string from imu
  char *bufPos;
  char* msgArray[3];

  // initialise and clear msgArray
  for (int j=0; j<3; j++) {
    msgArray[j] = new char[15];
  }

  ROS_INFO("rcvThread: serial receive thread running");

  ros::Rate loop_rate(10); // 10 Hz
  double y,p,r;
  double a_x = 250,a_y = 0,a_z = 0;
  double g_x = 0,g_y = 0,g_z = 0;
  double m_x = 0,m_y = 0,m_z = 0;

      
  while (ros::ok()) {
      //printf("\nreached here flag 1\n");

      ////Clear the first line as it may be incomplete after flush
      //bufPos=fgets(imuData,rcvBufSize,fpSerial);
      //if(bufPos == NULL){
      //    printf("bufPos is null\n");
      //}
      //else{
      //  printf("\ntrying  %s",imuData);
        
        //Parsing the imuData string and publishing
        //Input format is #YPR=yaw,pitch,roll #A-C=ax,ay,az #M-C=mx,my,mz #G-C=gx,gy,gz <<< error posible please look into the output format and arrage accordingly
	    //sscanf(imuData,"#YPR=%lf,%lf,%lf #A-C=%lf,%lf,%lf #M-C=%lf,%lf,%lf #G-C=%lf,%lf,%lf",&y,&p,&r,&a_x,&a_y,&a_z,&m_x,&m_y,&m_z,&g_x,&g_y,&g_z);
	    //printf("#YPR=%lf,%lf,%lf #A-C=%lf,%lf,%lf #M-C=%lf,%lf,%lf #G-C=%lf,%lf,%lf",y,p,r,a_x,a_y,a_z,m_x,m_y,m_z,g_x,g_y,g_z);

        //Calculations as done in https://github.com/FroboLab/FroboMind/blob/master/fmSensors/global_sensing/imu/sparkfun_razor_9dof/src/sparkfun_9dof.cpp 
        a_x = a_x / 1000.0 * 4 * 9.82;
        a_y = a_y / 1000.0 * 4 * 9.82;
        a_z = a_z / 1000.0 * 4 * 9.82;
	    g_x = g_x * 1/14.375 * DEG2RAD;
	    g_y = g_y * 1/14.375 * DEG2RAD;
	    g_z = g_z * 1/14.375 * DEG2RAD;
	    m_x = m_x / 660.0;
	    m_y = m_y / 660.0;
	    m_z = m_z / 660.0;
        
        //The publishing part
        ++msg_imu.header.seq;
	    msg_imu.header.frame_id = "imu_frame";
	    msg_imu.header.stamp = ros::Time::now();
        	
        //Acceleration
	    msg_imu.linear_acceleration.x = a_x;
	    msg_imu.linear_acceleration.y = a_y;
        //negate z if gives wrong value depends on orientation of sensor i suppose
	    msg_imu.linear_acceleration.z = a_z;

	    //Angular rates
	    msg_imu.angular_velocity.x = g_x;
	    msg_imu.angular_velocity.y = g_y;
        //negate z if gives wrong value depends on orientation of sensor i suppose
	    msg_imu.angular_velocity.z = g_z;
        
        //This is copy pasted directly from the code <<< error possible
        tf::Quaternion qt = tf::createQuaternionFromRPY(r, p, y);
        msg_imu.orientation.x = qt[0];
        msg_imu.orientation.y = qt[1];
        msg_imu.orientation.z = qt[2];
        msg_imu.orientation.w = qt[3];
        msg_imu.header.stamp = ros::Time::now();
        
        // broadcast transform
        tf::Transform transform;
        transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
        transform.setRotation(qt);

        static tf::TransformBroadcaster br;
        br.sendTransform( tf::StampedTransform(transform, ros::Time::now(), "base_link","imu_frame") );

        //Publishers for imu data and magnetometer data are declared as global variables
        //Naming Imu publisher as required by robot_pose_ekf package
        //Publishing imu data here magneto meter not needed in imu data
        pubImu.publish(msg_imu);
          
        //Uncomment if magneto meter readings are needed(presently not working)
	    //++msg_mag_.header.seq;
	    //msg_mag_.header.frame_id = frame_id_;
	    //msg_mag_.header.stamp = ros::Time::now();
	    //msg_mag_.x = m_x;
	    //msg_mag_.y = m_y;
	    //msg_mag_.z = m_z;

	    //pub_mag_.publish(msg_mag_);
        
      //}
    a_x = 250;
    
    loop_rate.sleep();
  }
  return NULL;
}


int main(int argc, char **argv)
{
  char port[20];    //port name
  int baud;         //baud rate 

  char rzTopic[20];  //topic name for ypr data
  char imuTopic[20]; //topic name for imu data
  char magTopic[20]; //topic name for mag data

  pthread_t rcvThrID;   //receive thread ID
  int err;

  //Initialize ROS
  ros::init(argc, argv, "razor_imu_9dof");
  ros::NodeHandle nh;
  ROS_INFO("razor_imu_9dof starting");

  //Arguments can be given to package
  //Open and initialize the serial port to the Razor IMU
  if (argc > 1) {
    if(sscanf(argv[1],"%d", &rzIndex)==1) {
      sprintf(rzTopic, "imu_ypr_data", rzIndex);
      sprintf(imuTopic, "imu_data", rzIndex);
      sprintf(magTopic, "imu_mag_data", rzIndex);
    }
    else {
      ROS_ERROR("rzIndex parameter invalid");
      return 1;
    }
  }
  else {
    strcpy(rzTopic, "imu_ypr_data");
    strcpy(imuTopic, "imu_data");
    strcpy(magTopic, "imu_mag_data");
  }
    
  //checking if there is a serial port given like /dev/ttyACM0 
  strcpy(port, DEFAULT_SERIALPORT);
  if (argc > 2)
     strcpy(port, argv[2]);

  baud = DEFAULT_BAUDRATE;
  if (argc > 3) {
    if(sscanf(argv[3],"%d", &baud)!=1) {
      ROS_ERROR("baud rate parameter invalid");
      return 1;
    }
  }

  ROS_INFO("connection initializing (%s) at %d baud", port, baud);
  ROS_INFO("serial connection successful");
  
  //Advertising topic names to remaining ros system
  pubRazorImu = nh.advertise<razor_imu_9dof::RazorImu>(rzTopic, 1);
  pubImu = nh.advertise<sensor_msgs::Imu>(imuTopic, 1);
  //magneto meter publisher requires a custom defined type not done yet

  //Create receive thread the messages are received and published from this thread
  err = pthread_create(&rcvThrID, NULL, rcvThread, NULL);
  if (err != 0) {
    ROS_ERROR("unable to create receive thread");
    return 1;
  }

  //Process ROS messages and send serial commands to uController
  ros::spin();

  ROS_INFO("razor_imu_9dof stopping");
  return 0;
}

