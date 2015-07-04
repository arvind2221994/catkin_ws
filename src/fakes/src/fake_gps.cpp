#include "ros/ros.h"

#include <sstream>
#include <fcntl.h>
#include <termios.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SERIALPORT "/dev/ttyUSB0"
#define DEFAULT_BAUDRATE 19200

//NOTE::Start reading from the main then onto the rcvThread function it helps :)
// Global data
FILE *fpSerial = NULL; // serial port file pointer

//Publishers for data 
//ros::Publisher pubRazorImu;// yaw, pitch, roll (not used in code but can be done)
//ros::Publisher pubImu;     // ros imu sensor message 
//ros::Publisher pubMag;     // ros mag sensor message (not working presently)
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
  //razor_imu_9dof::RazorImu rz;
  //sensor_msgs::Imu msg_imu;
  //
  ////Please be carefull this maybe wrong <<< error possible
  //msg_imu.orientation_covariance[0] = 999999;
  //msg_imu.orientation_covariance[4] = 9999999;
  //msg_imu.orientation_covariance[8] = 999999;
  //msg_imu.angular_velocity_covariance[0] = 9999;
  //msg_imu.angular_velocity_covariance[4] = 9999;
  //msg_imu.angular_velocity_covariance[8] = 0.02;
  //msg_imu.linear_acceleration_covariance[0] = 0.2;
  //msg_imu.linear_acceleration_covariance[4] = 0.2;
  //msg_imu.linear_acceleration_covariance[8] = 0.2;

  int rcvBufSize = 500;
  char imuData[rcvBufSize];   //received string from imu
  char *bufPos;
  //char* msgArray[3];

  //// initialise and clear msgArray
  //for (int j=0; j<3; j++) {
  //  msgArray[j] = new char[15];
  //}

  //ROS_INFO("rcvThread: serial receive thread running");

  ros::Rate loop_rate(10); // 10 Hz
  //double y,p,r;
  //double a_x,a_y,a_z,g_x,g_y,g_z,m_x,m_y,m_z;

      
  while (ros::ok()) {

    //Clear the first line as it may be incomplete after flush
    memset(imuData,0x0,rcvBufSize);  
    while (fgets(imuData,rcvBufSize,fpSerial) != NULL) {
        printf("%s",imuData);
        memset(imuData,0x0,rcvBufSize);  
    }
        
    // flush the contents of the input
    tcflush(fd, TCIFLUSH);

    loop_rate.sleep();
  }
  return NULL;
}


int main(int argc, char **argv)
{
  char port[20];    //port name
  int baud;         //baud rate 

  //char rzTopic[20];  //topic name for ypr data
  //char imuTopic[20]; //topic name for imu data
  //char magTopic[20]; //topic name for mag data

  pthread_t rcvThrID;   //receive thread ID
  int err;

  //Initialize ROS
  ros::init(argc, argv, "razor_imu_9dof");
  ros::NodeHandle nh;
  ROS_INFO("gps_test starting");

  ////Arguments can be given to package
  ////Open and initialize the serial port to the Razor IMU
  //if (argc > 1) {
  //  if(sscanf(argv[1],"%d", &rzIndex)==1) {
  //    sprintf(rzTopic, "imu_ypr_data", rzIndex);
  //    sprintf(imuTopic, "imu_data", rzIndex);
  //    sprintf(magTopic, "imu_mag_data", rzIndex);
  //  }
  //  else {
  //    ROS_ERROR("rzIndex parameter invalid");
  //    return 1;
  //  }
  //}
  //else {
  //  strcpy(rzTopic, "imu_ypr_data");
  //  strcpy(imuTopic, "imu_data");
  //  strcpy(magTopic, "imu_mag_data");
  //}
  //  
  ////checking if there is a serial port given like /dev/ttyACM0 
  //strcpy(port, DEFAULT_SERIALPORT);
  if (1){
     strcpy(port, "/dev/ttyACM0");
     ROS_INFO("in");
  }

  baud = DEFAULT_BAUDRATE;
  //if (argc > 3) {
  //  if(sscanf(argv[3],"%d", &baud)!=1) {
  //    ROS_ERROR("baud rate parameter invalid");
  //    return 1;
  //  }
  //}

  ROS_INFO("connection initializing (%s) at %d baud", port, baud);
  fpSerial = serialInit(port, baud);
  if (!fpSerial ) {
    ROS_ERROR("unable to create a new serial port");
    return 1;
  }
  ROS_INFO("serial connection successful");
  
  //Advertising topic names to remaining ros system
  //pubRazorImu = nh.advertise<razor_imu_9dof::RazorImu>(rzTopic, 1);
  //pubImu = nh.advertise<sensor_msgs::Imu>(imuTopic, 1);
  //magneto meter publisher requires a custom defined type not done yet

  //Create receive thread the messages are received and published from this thread
  err = pthread_create(&rcvThrID, NULL, rcvThread, NULL);
  if (err != 0) {
    ROS_ERROR("unable to create receive thread");
    return 1;
  }

  //Process ROS messages and send serial commands to uController
  ros::spin();

  fclose(fpSerial);
  ROS_INFO("gps_test stopping");
  return 0;
}

