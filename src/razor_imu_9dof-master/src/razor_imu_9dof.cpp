#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <razor_imu_9dof/RazorImu.h>

#include <sstream>
#include <fcntl.h>
#include <termios.h>
#include <math.h>
#include <stdlib.h>

#define DEFAULT_SERIALPORT "/dev/ttyUSB0"
#define DEFAULT_BAUDRATE 57600

// Global data
FILE *fpSerial = NULL; // serial port file pointer
ros::Publisher pubRazorImu;  // yaw, pitch, roll
ros::Publisher pubImu;  // ros imu sensor message
int rzIndex; // index number
int fd = -1;

//Initialize serial port, return file descriptor
FILE *serialInit(char * port, int baud) 
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


// Receive responses from Razor imu
// and publish as a ROS message
void *rcvThread(void *arg)
{
  razor_imu_9dof::RazorImu rz;
  sensor_msgs::Imu imuMsg;
  imuMsg.orientation_covariance[0] = 999999;
  imuMsg.orientation_covariance[4] = 9999999;
  imuMsg.orientation_covariance[8] = 999999;
  imuMsg.angular_velocity_covariance[0] = 9999;
  imuMsg.angular_velocity_covariance[4] = 9999;
  imuMsg.angular_velocity_covariance[8] = 0.02;
  imuMsg.linear_acceleration_covariance[0] = 0.2;
  imuMsg.linear_acceleration_covariance[4] = 0.2;
  imuMsg.linear_acceleration_covariance[8] = 0.2;

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

  int count=0;
  while (ros::ok()) {
      count++;
      printf("\nreached here flag 1\n");

      // clear the first line as it may be incomplete after flush
      //fgets(imuData,rcvBufSize,fpSerial);
      fgets(imuData,rcvBufSize,fpSerial);
      memset(imuData,0x0,rcvBufSize);  
      bufPos=fgets(imuData,rcvBufSize,fpSerial);
      printf("\ntrying %d  %s",count,imuData);
      if(bufPos == NULL){
          printf("bufPos is null\n");
      }

      //if (bufPos != NULL) {
      //  printf("\ntrying %d  %s",count,imuData);
      //  ROS_DEBUG("IMU Received Data: %s", imuData);

      //  // Remove '#YPR='
      //  char truncMsg[rcvBufSize];
      //  memcpy(truncMsg, &imuData[5], 45);

      //  // break into 3 strings separated by ','
      //  int i=0;
      //  char * tok;
      //  tok=strtok(truncMsg, ",");
      //  while (tok != NULL) {
      //    strcpy(msgArray[i], tok);
      //    tok=strtok(NULL,",");
      //    i++;
      //  }

      //  // store yaw, pitch, roll as radians
      //  rz.yaw = -(float) atof(msgArray[0]);
      //  rz.pitch = -(float) atof(msgArray[1]);
      //  rz.roll = -(float) atof(msgArray[2]);
      //  pubRazorImu.publish(rz);

      //  tf::Quaternion qt = tf::createQuaternionFromRPY(rz.roll*(M_PI/180), rz.pitch*(M_PI/180), rz.yaw*(M_PI/180));
      //  imuMsg.orientation.x = qt[0];
      //  imuMsg.orientation.y = qt[1];
      //  imuMsg.orientation.z = qt[2];
      //  imuMsg.orientation.w = qt[3];
      //  imuMsg.header.stamp = ros::Time::now();
      //  imuMsg.header.frame_id = "laser";
      //  
      //  // broadcast transform
      //  tf::Transform transform;
      //  transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
      //  transform.setRotation(qt);

      //  static tf::TransformBroadcaster br;
      //  br.sendTransform( tf::StampedTransform(transform, ros::Time::now(), "world","laser") );

      //  pubImu.publish(imuMsg);
      //}

    // flush the contents of the input
    tcflush(fd, TCIFLUSH);

    loop_rate.sleep();
    printf("reached here flag 1\n");
  }
  return NULL;
}


int main(int argc, char **argv)
{
  char port[20];    //port name
  int baud;     //baud rate 

  char rzTopic[20];
  char imuTopic[20];

  pthread_t rcvThrID;   //receive thread ID
  int err;

  //Initialize ROS
  ros::init(argc, argv, "razor_imu_9dof");
  ros::NodeHandle rosNode;
  ROS_INFO("razor_imu_9dof starting");

  //Open and initialize the serial port to the Razor IMU
  if (argc > 1) {
    if(sscanf(argv[1],"%d", &rzIndex)==1) {
      sprintf(rzTopic, "RazorImu", rzIndex);
      sprintf(imuTopic, "Imu", rzIndex);
    }
    else {
      ROS_ERROR("rzIndex parameter invalid");
      return 1;
    }
  }
  else {
    strcpy(rzTopic, "RazorImu");
    strcpy(imuTopic, "Imu");
  }

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
  fpSerial = serialInit(port, baud);
  if (!fpSerial ) {
    ROS_ERROR("unable to create a new serial port");
    return 1;
  }
  ROS_INFO("serial connection successful");


  //Setup to publish ROS messages
  pubRazorImu = rosNode.advertise<razor_imu_9dof::RazorImu>(rzTopic, 1);
  pubImu = rosNode.advertise<sensor_msgs::Imu>(imuTopic, 1);

  //Create receive thread
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

