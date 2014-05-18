#include <ros/ros.h>
#include <cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <iostream>
#include <math.h>
#include <sensor_msgs/LaserScan.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;

    double LOG_SCALE = 40.0,
       PIXELS_PER_METER = 402,
       DISTANCE_FROM_FRONT = 0.2,
       RAY_THICKNESS = 1;
    
    cv_bridge::CvImage cv_image;
    /* Ros only works with absolute path */
    VideoCapture cap("/home/akhil/catkin_ws/src/temp/src/input_l2.avi");
   // cv_image.image = imread("/home/akhil/catkin_ws/src/temp/src/1.png");
	//VideoCapture cap(0);
    sensor_msgs::Image ros_image;
    Mat src;

  ros::Publisher pub = nh.advertise<sensor_msgs::LaserScan>("/static_image", 1);
  ros::Rate loop_rate(5);

  while (nh.ok()) 
  {
    Mat temp_src;
    vector<Vec4i> lines;
    //cv_image.image = imread("/home/akhil/catkin_ws/src/temp/src/1.png");
   
    cap >> cv_image.image;
    cv_image.encoding = "bgr8";
    src = cv_image.image;
	temp_src = src;
	
    /* This is the homography matrix that has been calculated */
    double H1[3][3]={
        -0.6831101842085501, -1.289368384246363, 512.2519923880192,
        -0.07436549596319565, -3.342666241293451, 1207.766297587992,
        -0.0001400102037052423, -0.00409440165884719, 1
    };
    cv::Mat H(3,3,CV_64F,H1);

    /* Declare a new Mat object which just contains black image */ 
    Mat HoughP(src.rows,src.cols,CV_8U,Scalar(0,0,0));
    Mat logPolar(src.rows,src.cols,CV_8U,Scalar(0,0,0));

    /* This part of the code includes perspective transform and thresholding the image */
  imshow("Input",temp_src);
    warpPerspective(src, src, H, Size(src.cols, src.rows));
    imshow("Ortho",src);
    cvtColor(src,src,CV_RGB2HSV);
	inRange(src,  Scalar(0,0,200), Scalar(140,255,255), src);
	medianBlur(src,src,3);
	Canny(src,src,50,150,3);

    /* Hough Lines being drawn from the input image which is thresholded */
    HoughLinesP(src, lines, 1, CV_PI/180, 15, 50, 20 );
    for( size_t i = 0; i < lines.size(); i++ ){
        Vec4i l = lines[i];
        line(HoughP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,255,255), 3, CV_AA);
    }

        
    /* Create temp IplImage to convert Mat to IplImage to work on cvLogPolar */
    IplImage temp = HoughP;
    IplImage* hough = &temp;
    IplImage temp1 = logPolar;
    IplImage* logP = &temp1;
    cvLogPolar(hough,logP,cvPoint2D32f(src.size().width/2,src.size().height),40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);

    /* Convert it back to Mat object */
    logPolar = cvarrToMat(logP,true);
    //double maxRadius = sqrt( logPolar.size().width * logPolar.size().width + logPolar.size().height * logPolar.size().height );
    //int temp_width = (int) ( LOG_SCALE * log( maxRadius ));
    //CvMat temp2 = logPolar;
    //cvGetSubRect( logP , &temp2 , cvRect(0,40,temp_width,40));
    //logPolar = Mat(&temp2,true);

    /* This part onwards is sending the obtained images as Laser scan data */
    Size img_size = logPolar.size();
    unsigned int num_readings = 1 + img_size.height/RAY_THICKNESS;
    unsigned int max_dist = img_size.width;

    double angle_width = M_PI/(double)(num_readings - 1);
    double ranges[num_readings];

    uint8_t* pixelPtr = (uint8_t*)logPolar.data;

    for(int i = 0; i < num_readings-1; i++){
        unsigned int row = i * RAY_THICKNESS;
        unsigned int c = 0;
        for(c = 0;c < max_dist ; c++){
            bool flag = false;
            for(unsigned int r = row;r < row + RAY_THICKNESS;r++){
                if(pixelPtr[r*max_dist + c] == 255) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }

        }
            double distance = exp(c/LOG_SCALE)/(double)PIXELS_PER_METER;
            ROS_INFO("%lf ",distance);
            ranges[num_readings - i - 1] = distance;
    }
    ranges[0] = ranges[1];

    ros::Time scan_time = ros::Time::now();

    sensor_msgs::LaserScan scan;
    scan.header.stamp = scan_time;
    scan.header.frame_id = "laser_frame";
    scan.angle_increment = angle_width;
    scan.angle_min = -M_PI/2.0;
    scan.angle_max = M_PI/2.0;
    scan.range_max = exp(max_dist/LOG_SCALE)/(double)PIXELS_PER_METER;
    scan.ranges.resize(num_readings);
    scan.intensities.resize(num_readings);
    for(unsigned int i=0;i<num_readings;++i){
        scan.ranges[i] = ranges[i];
        scan.intensities[i] = 300.0;
    }
    /* This part can be removed. It is only being used for debugging */
    cvtColor(temp_src,temp_src,CV_HSV2RGB);
    imshow("Output",HoughP);
    imshow("Out",logPolar);

    cv_image.toImageMsg(ros_image);
    cvWaitKey(30);
    pub.publish(scan);
  }
}
