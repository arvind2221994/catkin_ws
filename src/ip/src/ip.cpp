#include <iostream>
#include <cmath>
#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/LaserScan.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/imgproc_c.h"

using namespace cv;
using namespace std;

Point findmin(Mat CurrImage, float theta, Point rot_center, float diaglen, int bin_w)
{
    int midx, midy, i, j, newx, newy,row,col;
    Point POI;
    float radiusVector,angle,rads;

    midy=rot_center.y;
    midx=rot_center.x;
    rads=(3.14159*theta/180);

    row=CurrImage.rows;
    col=CurrImage.cols;

    Mat normalThresholdedImage(2*row/**(1+abs(sin(rads)))*/, 2*col/**(1+abs(sin(rads)))*/, CV_8UC1, Scalar(0,0,0));
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            radiusVector=sqrt((i-midy)*(i-midy) + (j-midx)*(j-midx));
            angle=atan2(i-midy, j-midx);
            newx=radiusVector*cos(angle + rads) + midx;
            newy=radiusVector*sin(angle + rads) + midy;

            normalThresholdedImage.at<uchar>(newy,newx)=CurrImage.at<uchar>(i, j);
            
        }
    }

    Mat normalThresholdedImage2(diaglen, diaglen, CV_8UC1, Scalar(0,0,0));
    /*/// Display
    namedWindow("Output2", CV_WINDOW_AUTOSIZE );
    imshow("Output2", normalThresholdedImage );
    waitKey(0);*/

    int flag=0;

    for(int i=diaglen - 1; i>0 && flag==0; i--)
    {
        normalThresholdedImage.copyTo(normalThresholdedImage2);
        for(int j=0; j<diaglen; j++)
            if(normalThresholdedImage.at<uchar>(i, j)!=0)
            {
                POI.x=j;
                POI.y=i;
                flag=1;
                break;
            }
        line( normalThresholdedImage2, Point( 0, i ) ,
                       Point( normalThresholdedImage2.cols-1, i),
                       Scalar( 150, 0, 0), 2, 8, 0  );
        //imshow("Output2", normalThresholdedImage2 );
        //waitKey(0);
    }
    //cout<<"\nAND THE ANSWER IS: Before Rotation"<<POI<<'\n';
    
    radiusVector=sqrt((POI.y-midy)*(POI.y-midy) + (POI.x-midx)*(POI.x-midx));
    angle=atan2(POI.y-midy, POI.x-midx);
    POI.x=radiusVector*cos(angle-rads)+midx;
    POI.y=radiusVector*sin(angle-rads)+midy;
    
    //cout<<"\tAfr Rotation: "<<POI<<'\n';
    POI.x*=1.5;     //Calibration Factor
    //cout<<"\tAfter multiplying with calibration factor, it is "<<POI;

    return POI;

}


int main( int argc, char** argv )
{
	ros::init(argc, argv, "image_publisher");
	ros::NodeHandle nh;

	double LOG_SCALE = 40.0,
		PIXELS_PER_METER = 402,
		DISTANCE_FROM_FRONT = 0.2,
		RAY_THICKNESS = 1;

	cv_bridge::CvImage cv_image;
	/* Ros only works with absolute path */
	sensor_msgs::Image ros_image;
	Mat imgOriginal;

	ros::Publisher pub = nh.advertise<sensor_msgs::LaserScan>("scan", 1);
	ros::Rate loop_rate(15);
	VideoCapture cap;
    Mat src=Mat::zeros(640, 640, CV_8UC1);

    /*if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "IGVC: Cannot open the web cam" << endl;
        return -1;
    }*/

    while (nh.ok())
    {
        Mat bgr_planes[3], normalThresholded;
        medianBlur(src,src,3); //blurring the image by convolution to aperture size 3 matrix
	
		cap >> cv_image.image;
		cv_image.encoding = "bgr8";
//		src = cv_image.image;
        
        imshow("Input",src);
		//src=src(Rect(0.2*src.cols, 0.3*src.rows, 0.6*src.cols, 0.6*src.rows));
        split(src,bgr_planes);

        Mat src_HSV, whiteThresholded, orangeThresholded;
        
        cvtColor(src, src_HSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
        inRange(src,Scalar(235,235, 235),Scalar(255, 255, 255),whiteThresholded);
        inRange(src_HSV, Scalar(0, 120, 121), Scalar(24, 255, 255), orangeThresholded); //Threshold the image
        inRange(bgr_planes[0], Scalar(190, 190, 190), Scalar(255,255,255), normalThresholded );

        //morphological opening (remove small objects from the foreground)
        erode(orangeThresholded, orangeThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( orangeThresholded, orangeThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        //morphological closing (fill small holes in the foreground)
        dilate( orangeThresholded, orangeThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        erode(orangeThresholded, orangeThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        
        

        Mat b_hist, dst;
        int histSize = 256; /// Establish the number of bins

        /// Set the ranges ( for (B,G,R) )
        float range[] = { 0, 256 } ;
        const float* histRange = { range };

        int hist_w = 256; int hist_h = 400;
        int bin_w = cvRound( (double) hist_w / histSize );

        bool uniform = true; bool accumulate = false;

        calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate ); /// Compute the histograms
        normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat() );  /// Normalize the result to [ 0, histImage.rows ]

        /// Display
        double max;
        Point maxLoc;
        // Get min and max values
        hist_w = b_hist.rows - maxLoc.y - 1;

        Mat normalThresholded_hist = b_hist(Rect(0, 0.05*histSize, 1, 0.859375 * histSize)); //This is to avoid super high white which might come from white barrels, etc
        minMaxLoc(normalThresholded_hist, 0, &max, 0, &maxLoc);

        b_hist=b_hist(Rect( 0, maxLoc.y, 1, b_hist.rows - maxLoc.y - 1 ) ); //The histogram given by opencv is filled in column-major
        histSize = b_hist.rows;
        
        // Draw the histograms for B, G and R
        Mat histImage( hist_h, hist_w, CV_8UC1, Scalar( 0,0,0) );

        /// Find elbow by Hough Line Transform of trimmed histogram's minima after rotation
        for( int i = 1; i < histSize; i++ )
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
               Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
               Scalar( 255, 0, 0), 3, 8, 0  );                      //line thickness has been increased on purpose so that hough line transform gives better results


        vector<Vec4i> lines;
        HoughLinesP(histImage, lines, 1, CV_PI/180, 1, 50, 20 ); //detects the lines with min rho=1, theta=PI/180, numbers_of_votes>15

        histImage.release();
        histImage=Mat::zeros(hist_h, hist_w, CV_8UC1);
        for( size_t i = 0; i < lines.size(); i++ )
        {
            Vec4i l = lines[i];
            line(histImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,255,255), 1, CV_AA);  //draw using the detected lines
        }


        float diaglen = sqrt( histImage.rows*histImage.rows + histImage.cols*histImage.cols );
        Point rot_center( 0, 0);
        Point min_of_hist = findmin(histImage, -5, rot_center, diaglen, bin_w);

        

        int fin_thresh = min_of_hist.x + maxLoc.y, simpleThreshold=240;
        fin_thresh>255?fin_thresh=250:1;
        fin_thresh<200?fin_thresh=200:1;
        inRange(bgr_planes[0], Scalar(fin_thresh), Scalar(255), dst );




        //Start of Obstacle Avoidance part
		Mat barrels(src.rows,src.cols,CV_32F,Scalar(0,0,0)), canny_output, drawing = Mat::zeros( src.size(), CV_8UC1 );
        int kernel_rows = 71;
        Mat kernel = Mat::ones(kernel_rows,1,CV_32F) / (float)(kernel_rows);
        filter2D(orangeThresholded, barrels, -1 , kernel, Point(-1, -1), 0, BORDER_DEFAULT );
        dilate( barrels, barrels, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );

        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;

        dilate( whiteThresholded, whiteThresholded, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );
        erode( whiteThresholded, whiteThresholded, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );

        /// Find contours
        threshold( whiteThresholded, canny_output, 50, 255, 0 );
        findContours( canny_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

        /// Find the convex hull object for each contour
        vector<vector<Point> >hull( contours.size() );
        for( int i = 0; i < contours.size(); i++ )
        {  convexHull( Mat(contours[i]), hull[i], false );	}

        /// Draw contours if very big area
        for( int i = 0; i< contours.size(); i++ )
        {
            if( contourArea(contours[i])>3500)
                drawContours( drawing, hull, i, Scalar(255,255,255), CV_FILLED, 8, vector<Vec4i>(), 0, Point() );
        }

        
        inRange(barrels, Scalar(30,0,0), Scalar(255,255,255), barrels);
        drawing = drawing + barrels;
        dst = dst - drawing;

        
        //Do HoughP to get it as lines
        Mat HoughP=Mat::zeros(dst.size(), CV_8UC1);
        lines.clear();
        Canny(dst,dst,40,160,3);
        HoughLinesP(dst, lines, 1, CV_PI/180, 15, 50, 20 ); //detects the lines with min rho=1, theta=PI/180, numbers_of_votes>15,
        // min line length =50 to avoid noise, max gap allowed between two points on a line to link =20
        for( size_t i = 0; i < lines.size(); i++ )
        {
            Vec4i l = lines[i];
            line(HoughP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,255,255), 3, CV_AA);  //draw using the detected lines
        }


        double H1[3][3] = {1.543791996263136, 3.246012361455426, -256.6805435376367,
		  -0.164374722578045, 7.310327485421315, -354.9105635310093,
		  -0.0002339195230311428, 0.01028098053326668, 1};
		Mat H(3,3,CV_64F,H1), logPolar(src.rows,src.cols,CV_8U,Scalar(0,0,0));
		warpPerspective(HoughP, HoughP, H, Size(src.cols, src.rows));



		// Create temp IplImage to convert Mat to IplImage to work on cvLogPolar 
	    IplImage temp = HoughP;
	    IplImage temp1 = logPolar;
	    cvLogPolar(&temp,&temp1,cvPoint2D32f(src.size().width/2,src.size().height),40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);

	    // Convert it back to Mat object 
	    logPolar = cvarrToMat(&temp1,true);


	    Size img_size = logPolar.size();
	    unsigned int num_readings = 1 + img_size.height/RAY_THICKNESS;
	    unsigned int max_dist = img_size.width;

	    double angle_width = M_PI/(double)(num_readings - 1);
	    double ranges[num_readings];

	    uint8_t* pixelPtr = (uint8_t*)logPolar.data;

        bool blackImageFlag=true;

	    for(int i = 0; i < num_readings-1; i++)
	    {
	        unsigned int row = i * RAY_THICKNESS;
	        unsigned int c = 0;
	        for(c = 0;c < max_dist ; c++)
	        {
	            bool flag = false;
	            for(unsigned int r = row;r < row + RAY_THICKNESS;r++)
	            {
	                if(pixelPtr[r*max_dist + c] == 255)
	                {
	                    flag = true;
                        blackImageFlag=false;
	                    break;
	                }
	            }
	            if(flag)
	            {
	                break;
	            }

	        }
            double distance = exp(c/LOG_SCALE)/(double)PIXELS_PER_METER;
            ROS_INFO("%lf ",distance);
            //ranges[num_readings - i - 1] = distance;
	    }
	    ranges[0] = ranges[1];

            //if(blackImageFlag==true)
            for(int i=0; i<num_readings-1; i++)
                ranges[i]=0;

	    ros::Time scan_time = ros::Time::now();

	    sensor_msgs::LaserScan scan_cam;
	    scan_cam.header.stamp = scan_time;
	    scan_cam.header.frame_id = "laser_frame";
	    scan_cam.angle_increment = angle_width;
	    scan_cam.angle_min = -M_PI/2.0;
	    scan_cam.angle_max = M_PI/2.0;
	    scan_cam.range_max = exp(max_dist/LOG_SCALE)/(double)PIXELS_PER_METER;
	    scan_cam.ranges.resize(num_readings);
	    scan_cam.intensities.resize(num_readings);
	    for(unsigned int i=0;i<num_readings;++i)
	    {
	        scan_cam.ranges[i] = ranges[i];
	        scan_cam.intensities[i] = 300.0;
	    }
	    
	    imshow("Output",HoughP);
	    imshow("Out",logPolar);

	    cv_image.toImageMsg(ros_image);
	    cvWaitKey(30);
	    pub.publish(scan_cam);

    }
}
