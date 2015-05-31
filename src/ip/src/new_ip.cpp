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

    Mat tempImage(2*row/**(1+abs(sin(rads)))*/, 2*col/**(1+abs(sin(rads)))*/, CV_8UC1, Scalar(0,0,0));
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            radiusVector=sqrt((i-midy)*(i-midy) + (j-midx)*(j-midx));
            angle=atan2(i-midy, j-midx);
            newx=radiusVector*cos(angle + rads) + midx;
            newy=radiusVector*sin(angle + rads) + midy;

            tempImage.at<uchar>(newy,newx)=CurrImage.at<uchar>(i, j);
            
        }
    }

    Mat tempImage2(diaglen, diaglen, CV_8UC1, Scalar(0,0,0));
    /*/// Display
    namedWindow("Output2", CV_WINDOW_AUTOSIZE );
    imshow("Output2", tempImage );
    waitKey(0);*/

    int flag=0;

    for(int i=diaglen - 1; i>0 && flag==0; i--)
    {
        tempImage.copyTo(tempImage2);
        for(int j=0; j<diaglen; j++)
            if(tempImage.at<uchar>(i, j)!=0)
            {
                POI.x=j;
                POI.y=i;
                flag=1;
                break;
            }
        line( tempImage2, Point( 0, i ) ,
                       Point( tempImage2.cols-1, i),
                       Scalar( 150, 0, 0), 2, 8, 0  );
        //imshow("Output2", tempImage2 );
        //waitKey(0);
    }
    cout<<"\n\nAND THE ANSWER IS: "<<POI<<'\n';
    
    radiusVector=sqrt((POI.y-midy)*(POI.y-midy) + (POI.x-midx)*(POI.x-midx));
    angle=atan2(POI.y-midy, POI.x-midx);
    POI.x=radiusVector*cos(angle-rads)+midx;
    POI.y=radiusVector*sin(angle-rads)+midy;
    
    cout<<"\n\nAND THE ANSWER IS: "<<POI<<'\n';
    POI.x*=1.3;
    cout<<"\nAccounting for bin width, it is "<<POI;

    return POI;

}


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
    //VideoCapture cap("/home/akhil/catkin_ws/src/temp/src/input_l2.avi");
   // cv_image.image = imread("/home/akhil/catkin_ws/src/temp/src/1.png");
	VideoCapture cap(0);
    sensor_msgs::Image ros_image;
    Mat imgOriginal;

  ros::Publisher pub = nh.advertise<sensor_msgs::LaserScan>("scan", 1);
  ros::Rate loop_rate(5);

  while (nh.ok()) 
  {
    Mat temp_src;
    vector<Vec4i> lines;
    //cv_image.image = imread("/home/akhil/catkin_ws/src/temp/src/1.png");
   
    cap >> cv_image.image;
    cv_image.encoding = "bgr8";
    imgOriginal = cv_image.image;
	temp_src = imgOriginal;

	
    /* This is the homography matrix that has been calculated */
    double H1[3][3]={
        -0.6831101842085501, -1.289368384246363, 512.2519923880192,
        -0.07436549596319565, -3.342666241293451, 1207.766297587992,
        -0.0001400102037052423, -0.00409440165884719, 1
    };
    cv::Mat H(3,3,CV_64F,H1);

    /* Declare a new Mat object which just contains black image */ 
    Mat HoughP(imgOriginal.rows,imgOriginal.cols,CV_8U,Scalar(0,0,0));
    Mat logPolar(imgOriginal.rows,imgOriginal.cols,CV_8U,Scalar(0,0,0));

    //////////////////////////////////////////////////////////////////////////NNNNNEEEEEEWWWWWWWWWWWWW

  Mat b_hist, dst;


   // imgOriginal=imgOriginal(Rect(0, 0.2*imgOriginal.rows, imgOriginal.cols, 0.7*imgOriginal.rows));
    Mat imgHSV,imSimple,imResult,imBlue, histimage;
    Mat bgr_planes[3];
    split(imgOriginal,bgr_planes);
    imBlue = bgr_planes[0];

    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
    //inRange(imBlue,Scalar(235,235, 235),Scalar(255, 255, 255),imSimple);

    Mat imgThresholded;

    inRange(imgHSV, Scalar(0, 120, 121), Scalar(24, 255, 255), imgThresholded); //Threshold the image

    //morphological opening (remove small objects from the foreground)
    //erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(45, 45)) );
    dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(35, 35)) );
    bitwise_not(imgThresholded,imgThresholded);

    //morphological closing (fill small holes in the foreground)
    /*dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    //imResult = imSimple+imgThresholded;
    dilate( imResult, imResult, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    erode(imResult, imResult, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    namedWindow("Result Image", CV_NORMAL);
    imshow("Result Image", imResult);*/

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
       
        //imshow("Output", histImage );
        double max;
        Point maxLoc;
        // Get min and max values
        hist_w = b_hist.rows - maxLoc.y - 1;

        Mat temp_hist = b_hist(Rect(0, 0.05*histSize, 1, 0.859375 * histSize)); //This is to avoid super high white which might come from white barrels, etc
        minMaxLoc(temp_hist, 0, &max, 0, &maxLoc);

        b_hist=b_hist(Rect( 0, maxLoc.y, 1, b_hist.rows - maxLoc.y - 1 ) ); //The histogram given by opencv is filled in column-major
        histSize = b_hist.rows;
        //hist_w = histSize;

        cout<<"\n\nStage2: After Trimming from Maximum:"
            <<"\nMaximum Value: "<<max<<"\tLocation: "<<maxLoc.y
            <<"\nHistSize = "<<histSize<<"and hist_w = "<<hist_w<<'\n';

        // Draw the histograms for B, G and R
        Mat histImage2( hist_h, hist_w, CV_8UC1, Scalar( 0,0,0) );

        /// Draw the histogram
        for( int i = 1; i < histSize; i++ )
            line( histImage2, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                           Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                           Scalar( 255, 0, 0), 3, 8, 0  );                      //line thickness has been increased on purpose so that hough line transform gives better results



        Mat histImage3(hist_h, hist_w, CV_8UC1, Scalar(0,0,0));

        vector<Vec4i> line;
        HoughLinesP(histImage2, line, 1, CV_PI/180, 1, 50, 20 ); //detects the lines with min rho=1, theta=PI/180, numbers_of_votes>15
        for( size_t i = 0; i < line.size(); i++ )
        {
            Vec4i l = line[i];
            line(histImage3, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,255,255), 1, CV_AA);  //draw using the detected lines
        }


        float diaglen = sqrt( histImage3.rows*histImage3.rows + histImage3.cols*histImage3.cols );
        Point rot_center( 0, 0);
        Point min_of_hist = findmin(histImage3, -15, rot_center, diaglen, bin_w);

      

       
        int fin_thresh = min_of_hist.x + maxLoc.y, simpleThreshold=240;
        fin_thresh>255?fin_thresh=250:1;
        fin_thresh<200?fin_thresh=200:1;




        //Start of Convex Hulling part
        inRange(bgr_planes[0], Scalar(fin_thresh, 0, 0), Scalar(255,255,255), dst );
        Mat src=dst.mul(imgThresholded);

    //////////////////////////////////////////////////////////////////////////NNNNEEEEWWWWWWWWWWWWWWWWWW

    /* This part of the code includes perspective transform and thresholding the image */
    imshow("Input",temp_src);
    warpPerspective(src, src, H, Size(src.cols, src.rows));

  //  imshow("Ortho",src);
    /*cvtColor(src,src,CV_RGB2HSV);
	inRange(src,  Scalar(0,0,180), Scalar(160,255,255), src);*/
	medianBlur(src,src,3);
	Canny(src,src,40,160,3);

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

    sensor_msgs::LaserScan scan_cam;
    scan_cam.header.stamp = scan_time;
    scan_cam.header.frame_id = "laser_frame";
    scan_cam.angle_increment = angle_width;
    scan_cam.angle_min = -M_PI/2.0;
    scan_cam.angle_max = M_PI/2.0;
    scan_cam.range_max = exp(max_dist/LOG_SCALE)/(double)PIXELS_PER_METER;
    scan_cam.ranges.resize(num_readings);
    scan_cam.intensities.resize(num_readings);
    for(unsigned int i=0;i<num_readings;++i){
        scan_cam.ranges[i] = ranges[i];
        scan_cam.intensities[i] = 300.0;
    }
    /* This part can be removed. It is only being used for debugging */
   // cvtColor(temp_src,temp_src,CV_HSV2RGB);
    imshow("Output",HoughP);
    imshow("Out",logPolar);

    cv_image.toImageMsg(ros_image);
    cvWaitKey(30);
    pub.publish(scan_cam);
  }
}
