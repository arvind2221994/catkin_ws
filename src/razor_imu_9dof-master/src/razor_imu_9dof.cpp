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

//Initialize serial port, return file descriptor
FILE *serialInit(char* port, int baud) 
{
  int BAUD = 0;
  struct termios newtio;
  FILE *fp = NULL;

  // Open the serial port as a file descriptor for low level configuration
  // read/write, not controlling terminal for process,
  fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY );
  if ( fd<0 ) {
    ROS_ERROR("serialInit: Could not open serial device %s",port);
    return fp;
  }

  // set up new settings
  memset(&newtio, 0,sizeof(newtio));
  newtio.c_cflag =  CS8 | CLOCAL | CREAD;  //no parity, 1 stop bit
  newtio.c_iflag = IGNCR;    //ignore CR, other options off
  newtio.c_iflag |= IGNBRK;  //ignore break condition
  newtio.c_oflag = 0;        //all options off
  newtio.c_lflag = ICANON;     //process input as lines

  // activate new settings
  tcflush(fd, TCIFLUSH);

  //Look up appropriate baud rate constant
  switch (baud) {
     case 57600:
     default:
	BAUD = B57600;
	break;
     case 38400:
        BAUD = B38400;
        break;
     case 19200:
        BAUD  = B19200;
        break;
     case 9600:
        BAUD  = B9600;
        break;
  }

  if (cfsetispeed(&newtio, BAUD) < 0 || cfsetospeed(&newtio, BAUD) < 0) {
    ROS_ERROR("serialInit: Failed to set serial baud rate: %d", baud);
    close(fd);
    return NULL;
  }
  tcsetattr(fd, TCSANOW, &newtio);
  tcflush(fd, TCIOFLUSH);

  //Open file as a standard I/O stream
  fp = fdopen(fd, "r+");
  if (!fp) {
    ROS_ERROR("serialInit: Failed to open serial stream %s", port);
    fp = NULL;
  }
  return fp;
}

//Function runs on a seperate thread and publishes ROS messages
void *rcvThread(void *arg)
{
  razor_imu_9dof::RazorImu rz;
  sensor_msgs::Imu msg_imu;
  
  //XXX : Possible error dummy values here
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
  char *bufPos;               //pointer for received string just used to check if there's data
  ROS_INFO("rcvThread: serial receive thread running");

  ros::Rate loop_rate(10); // 10 Hz
  double y,p,r;
  double a_x,a_y,a_z,g_x,g_y,g_z,m_x,m_y,m_z;

      
  //Have to remove first line from serial data contains junk
  fgets(imuData,rcvBufSize,fpSerial);
  while (ros::ok()) {

      //Clear the first line as it may be incomplete after flush
      memset(imuData,0x0,rcvBufSize);  
      bufPos=fgets(imuData,rcvBufSize,fpSerial);
      if(bufPos == NULL){
      }
      else{
        
        //Parsing the imuData string and publishing
        //Input format is #YPR=yaw,pitch,roll #A-C=ax,ay,az #M-C=mx,my,mz #G-C=gx,gy,gz <<< error posible please look into the output format and arrage accordingly
	    sscanf(imuData,"#YPR=%lf,%lf,%lf #A-C=%lf,%lf,%lf #M-C=%lf,%lf,%lf #G-C=%lf,%lf,%lf",&y,&p,&r,&a_x,&a_y,&a_z,&m_x,&m_y,&m_z,&g_x,&g_y,&g_z);
	    ROS_INFO("#YPR=%lf,%lf,%lf #A-C=%lf,%lf,%lf #M-C=%lf,%lf,%lf #G-C=%lf,%lf,%lf",y,p,r,a_x,a_y,a_z,m_x,m_y,m_z,g_x,g_y,g_z);

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
        //NOTE: Values can be negated based on orientation of imu
	    msg_imu.linear_acceleration.x = a_x;
	    msg_imu.linear_acceleration.y = a_y;
	    msg_imu.linear_acceleration.z = a_z;

	    //Angular rates
        //NOTE: Values can be negated based on orientation of imu
	    msg_imu.angular_velocity.x = g_x;
	    msg_imu.angular_velocity.y = g_y;
	    msg_imu.angular_velocity.z = g_z;
        
        //XXX: possible error 
        tf::Quaternion qt = tf::createQuaternionFromRPY(r, p, y);
        msg_imu.orientation.x = 0; //qt[0];
        msg_imu.orientation.y = 0; //qt[1];
        msg_imu.orientation.z = 0; //qt[2];
        msg_imu.orientation.w = 1; //qt[3];
        msg_imu.header.stamp = ros::Time::now();
        
        //Transform
        //NOTE: Should be changed based on the imu placement
        tf::Transform transform;
        transform.setOrigin( tf::Vector3(0.08, 0.0, 0.125) );
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
        
      }
    
    // flush the contents of the input
    tcflush(fd, TCIFLUSH);

    loop_rate.sleep();
    printf("reached here flag 1 \n");
  }
  return NULL;
}


int main(int argc, char **argv)
{
  std::string port; //port name
  int baud;         //baud rate 

  std::string rzTopic;  //topic name for ypr data
  std::string imuTopic; //topic name for imu data
  std::string magTopic; //topic name for mag data

  pthread_t rcvThrID;   //receive thread ID
  int err;

  //Initialize ROS
  ros::init(argc, argv, "razor_imu_9dof");
  ros::NodeHandle nh;
  ROS_INFO("razor_imu_9dof starting");

  //Taking the topic names as params defaults are already declared
  nh.param("rzTopic",rzTopic,std::string("rz_data"));
  nh.param("imuTopic",imuTopic,std::string("imu_data"));
  nh.param("magTopic",magTopic,std::string("mag_data"));

  nh.param("port",port,std::string(DEFAULT_SERIALPORT));    
  nh.param("baud",baud,int(DEFAULT_BAUDRATE));    

  //Apparently ros cannot print std::string so converting it into char*
  ROS_INFO("connection initializing (%s) at %d baud", port.c_str(), baud);
  fpSerial = serialInit((char*)port.c_str(), baud);
  if (!fpSerial ) {
    ROS_ERROR("unable to create a new serial port");
    return 1;
  }
  ROS_INFO("serial connection successful");
  
  //Advertising topic names to remaining ros system
  pubRazorImu = nh.advertise<razor_imu_9dof::RazorImu>(rzTopic, 1);
  pubImu = nh.advertise<sensor_msgs::Imu>(imuTopic, 1);
  
  //TODO:Magneto meter publisher requires a custom defined type not done yet

  //Create receive thread the messages are received and published from this thread
  err = pthread_create(&rcvThrID, NULL, rcvThread, NULL);
  if (err != 0) {
    ROS_ERROR("unable to create receive thread");
    return 1;
  }

  //Process ROS messages and send serial commands to uController
  ros::spin();

  fclose(fpSerial);
  ROS_INFO("razor_imu_9dof stopping");
  return 0;
}
