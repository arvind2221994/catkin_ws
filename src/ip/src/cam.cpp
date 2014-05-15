#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv/cv.hpp"
#include <stdio.h>
#include <sstream>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

Mat src;
VideoCapture cap(0);
while(true)
{
cap>>src;
imshow("input",src);
cvWaitKey(60);
}
return 0;
}
