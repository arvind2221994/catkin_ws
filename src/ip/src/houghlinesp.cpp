#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv/cv.hpp"
#include <stdio.h>
#include <sstream>
#include <iostream>

using namespace cv;
using namespace std;

# define linenumber 1000


class LineFinder {
private:
// original image
cv::Mat img;
// vector containing the end points
// of the detected lines
std::vector<cv::Vec4i> lines;
// accumulator resolution parameters
double deltaRho;
double deltaTheta;
// minimum number of votes that a line
// must receive before being considered
int minVote;
// min length for a line
double minLength;
// max allowed gap along the line
double maxGap;
public:
// Default accumulator resolution is 1 pixel by 1 degree
// no gap, no mimimum length
LineFinder() : deltaRho(1), deltaTheta(CV_PI/180),
minVote(10), minLength(0.), maxGap(0.) {}
// Set the resolution of the accumulator
void setAccResolution(double dRho, double dTheta) {
deltaRho= dRho;
deltaTheta= dTheta;
}
// Set the minimum number of votes
void setMinVote(int minv) {
minVote= minv;
}
// Set line length and gap
void setLineLengthAndGap(double length, double gap) {
minLength= length;
maxGap= gap;
}
	// Apply probabilistic Hough Transform
std::vector<cv::Vec4i> findLines(cv::Mat& binary) {
lines.clear();
cv::HoughLinesP(binary,lines,
deltaRho, deltaTheta, minVote,
minLength, maxGap);
return lines;
}
// Draw the detected lines on an image
void drawDetectedLines(cv::Mat &image,
cv::Scalar color=cv::Scalar(0,0,255)) {
	// Draw the lines
std::vector<cv::Vec4i>::const_iterator it2=
lines.begin();
while (it2!=lines.end()) {
cv::Point pt1((*it2)[0],(*it2)[1]);
cv::Point pt2((*it2)[2],(*it2)[3]);
cv::line( image, pt1, pt2, color,2);
++it2;
}
}
};


int main(int argc,char** argv)
{
	Mat src,srcg,dst;
	//CvCapture* capture;

	//capture=cvCaptureFromCAM(1);
	VideoCapture capture("CompCourse_right0.mpeg");
	/*double dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

   cout << "Frame Size = " << dWidth << "x" << dHeight << endl;
	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));*/
  
    //VideoWriter oVideoWriter ("ortho.avi", CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true); //initialize the VideoWriter object 
	while(true)
	{
	//src=imread(argv[1],1);
	capture>>src;

	imshow("input",src);
	cvtColor(src,srcg,CV_RGB2HSV);
	//inRange(srcg,  Scalar(100,10,150), Scalar(130,80,255), srcg);
	//inRange(srcg,  Scalar(0,0,250), Scalar(10,10,255), srcg);
	inRange(srcg,  Scalar(0,0,200), Scalar(140,255,255), srcg);
	//imshow("out",srcg);
	medianBlur(srcg,srcg,3);
	
	Canny(srcg,dst,50,150,3);
	imshow("canny",dst);
	// Create LineFinder instance
LineFinder finder;
// Set probabilistic Hough parameters
finder.setLineLengthAndGap(50,20);
finder.setMinVote(15);
// Detect lines and draw them
std::vector<cv::Vec4i> lines= finder.findLines(dst);
finder.drawDetectedLines(src);
//cv::namedWindow("Detected Lines with HoughP");
imshow("Detected Lines with HoughP",src);

//oVideoWriter.write(src); //writer the frame into the file
//imwrite("houghp.jpg",src);
cvWaitKey(60);
}

return 0;

}
