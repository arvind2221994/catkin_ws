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

class LineFinder{
    private :
        cv::Mat img;
        std::vector<cv::Vec4i> lines;
        double deltaRho;
        double deltaTheta;
        int minVote;
        double minLength;
        double maxGap;
    public:
        LineFinder() :  deltaRho(1), 
        deltaTheta(CV_PI/180), 
        minVote(10),
        minLength(0.) {}
        void setAccResolution(double dRho, double dTheta){
            deltaRho = dRho;
            deltaTheta = dTheta;
        }

        void setMinVote(int minv){
            minVote = minv;
        }

        void setLineLengthAndGap(double length, double gap){
            minLength = length;
            maxGap = gap;
        }

        std::vector<cv::Vec4i> findLines(cv::Mat& binary){
            lines.clear();
            cv::HoughLinesP(binary, lines, deltaRho, deltaTheta, minVote, minLength, maxGap);
            return lines;
        }

        void drawDetectedLines(cv::Mat &image, cv::Scalar color=cv::Scalar(255,255,255)){
            std::vector<cv::Vec4i>::const_iterator it2 = lines.begin();
            while(it2!=lines.end()){
                cv::Point pt1((*it2)[0], (*it2)[1]);
                cv::Point pt2((*it2)[2], (*it2)[3]);
                cv::line(image, pt1, pt2, color,2);
                ++it2;
        }
        }
};

int main(int argc,char** argv){
    int houghVote = 100;
    Mat src1;
    //cout<<"linenumber="<<linenumber;
      float rho_values[linenumber];
      float theta_values[linenumber];
            Mat src,contours,contoursInv,ortho,H;
    float theta_max = 1000000;
    float theta_min = -1000000;
    float rho_min,rho_max;
//VideoCapture capture(1);   
VideoCapture capture(1);
   namedWindow("ortho", CV_WINDOW_AUTOSIZE);
double dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

   cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

   Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

 VideoWriter oVideoWriter ("wierd.avi", CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true); //initialize the VideoWriter object 
 if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
   {
cout << "ERROR: Failed to write the video" << endl;
return -1;
   } int count=0;
    while(true){

        vector<vector<Point> > cnt;
        vector<Vec4i> hierarchy;  
        capture >> src;
src.copyTo(src1);
      //  src = imread(argv[1]);
        imshow("Input image",src1);
       // imwrite("input.jpg",src1);
        vector<Point2f> source_points;
	vector<Point2f> dest_points;
	source_points.push_back(cv::Point2f(169,386));
source_points.push_back(cv::Point2f(449,313));
source_points.push_back(cv::Point2f(212,111));
source_points.push_back(cv::Point2f(429,98));
	
dest_points.push_back(cv::Point2f(120,347));
dest_points.push_back(cv::Point2f(448,276));
dest_points.push_back(cv::Point2f(217,177));
dest_points.push_back(cv::Point2f(419,154));
H = getPerspectiveTransform( source_points, dest_points);
        warpPerspective(src, src, H, src.size(), INTER_CUBIC | WARP_INVERSE_MAP);
        imshow("ortho",src);
       // imwrite("ortho.jpg",src);
      // imwrite("input1.jpg",src);
        cvtColor(src,src,CV_RGB2HSV);
        inRange(src,  Scalar(0,0,200), Scalar(140,255,255), src);
        //imshow("image",src);
        erode(src,src,cv::Mat());
        imshow("erode",src);
        Canny(src,contours,50,150,3);
        //equalizeHist(contours,contours);
        imshow("Canny",contours);
        //imwrite("canny.jpg",contours);
        //threshold(contours,contoursInv,128,255,THRESH_BINARY_INV);
        //imshow("threshold",contoursInv);
        std::vector<Vec2f> lines;
       if (houghVote < 1 or lines.size() > 2){ 
                houghVote = 100; 
        }
        else{ houghVote += 25;} 
        while(lines.size() < 5 && houghVote > 0){
            HoughLines(contours,lines,1,CV_PI/180, houghVote);
                houghVote -= 5;
        }
        //std::cout << houghVote << "\n";
        Mat hough(contours.rows,contours.cols,CV_8U,Scalar(0));
        Mat result1(contours.rows,contours.cols,CV_8U,Scalar(0));
        //src.copyTo(hough);
        std::vector<Vec2f>::const_iterator it= lines.begin();
        //Mat hough(src.size(),CV_8U,Scalar(0));
        //if(count==0)
    //   cout<<"no. of lines="<<lines.end()-lines.begin()<<endl;
      // int val=0;
        while (it!=lines.end()) {
            float rho= (*it)[0];   
            float theta= (*it)[1]; 
            /*if (theta < theta_min)
            {
                theta_min = theta;
                rho_min = rho;
            }
prathyusha.shine@gmail.com
            else if (theta > theta_max)
            {
                theta_max = theta;
                rho_max = rho;
            }*/
            rho_values[it-lines.begin()]=rho;
            theta_values[it-lines.begin()]=theta;
          // cout<<"rho="<<rho_values[it-lines.begin()]<<"theta="<<theta_values[it-lines.begin()]<<endl;
       Point pt1(rho/cos(theta),0);        
        Point pt2((rho-hough.rows*sin(theta))/cos(theta),hough.rows);
      //  if(count==0)
        //cout<<"rho="<<rho<<", theta="<<theta<<endl;
       // line( result, pt1, pt2, Scalar(255), 2); 
        line( hough, pt1, pt2, Scalar(255), 2);
       // cout<<"point 1="<<pt1.x<<","<<pt1.y<<endl;
     //   cout<<"point2="<<pt2.x<<", "<<pt2.y<<endl;
        //cout<<endl;//if(count==0)
       // {
        //for(int k=0; k<lines.end()-lines.begin();k++)
        //cout<<rho_values[it-lines.begin()]<<endl;//}
       // cout<<pt1.x<<" "<<pt1.y<<endl;
        //std::cout << "line: (" << rho << "," << theta << ")\n"; 
        ++it;
        }
        //removing extra lines in hough
         float rho_final[lines.end()-lines.begin()];
      float theta_final[lines.end()-lines.begin()];
        std::vector<Vec2f>::const_iterator it1= lines.begin();
        Mat result(src.size(),CV_8U,Scalar(0));
       line(result,Point(rho_values[0]/cos(theta_values[0]),0),Point((rho_values[0]-result.rows*sin(theta_values[0]))/cos(theta_values[0]),result.rows),Scalar(255),2);
       int b=1;
       rho_final[0]=rho_values[0],theta_final[0]=theta_values[0];
       int line_result=1;
        while(it1!=lines.end()){
                std::vector<Vec2f>::const_iterator it2= lines.begin();
                
                while(it2<it1)
                {
        if((abs(rho_values[it1-lines.begin()]-rho_values[it2-lines.begin()])<5)&&(abs(theta_values[it1-lines.begin()]-theta_values[it2-lines.begin()])<0.5))
        break;
        else
        {
        Point pt3(rho_values[it2-lines.begin()]/(cos(theta_values[it2-lines.begin()])),0);
        Point pt4((rho_values[it2-lines.begin()]-result.rows*sin(theta_values[it2-lines.begin()]))/cos(theta_values[it2-lines.begin()]),result.rows);
        //cout<<"rho val of line="<<rho_values[it2-lines.begin()]<<" theta val of line= "<<theta_values[it2-lines.begin()]<<endl;
                //cout<<"rho val of pt4="<<rho_valuesit2-lines.begin()]<<" theta val of pt3="<<theta_values[it2-lines.begin()];
        //cout<<"point3="<<pt3.x<<","<<pt3.y<<endl;
        //cout<<"point4="<<pt4.x<<","<<pt4.y<<endl;
        //cout<<endl;
       //cv::circle(result,pt3,13,cvScalar(255,0,0));
       //cv::circle(result,pt4,16,cvScalar(125,0,0));
        line(result,pt3,pt4,Scalar(255),2);
        rho_final[b]=rho_values[it2-lines.begin()];
        theta_final[b]=theta_values[it2-lines.begin()];
       // cout<<"rho_final ="<<rho_final[b]<<" theta_final= "<<theta_final[b]<<endl;
        b++;
        line_result++;
        }
        ++it2;}
        ++it1;}
        //cout<<"b ="<<b;
        
        //finding all possible distances
       float dist_max=0;
       float dist_cmp=0;
              for(int c=0;c<b;c++)
              {
             // cout<<"rho= "<<rho_final[c]<<" theta= "<<theta_final[c]<<endl;   
              for(int d=0;d<c;d++)
              {
              dist_cmp=(rho_final[c]-rho_final[d])*0.28285;
              if(dist_cmp>=dist_max)
              dist_max=dist_cmp;
              }
              }
              cout<<"the maximum distance is "<<dist_max;
              cout<<endl;          
       // cout<<"lines drawn in result="<<line_result<<endl;
        //imshow("result1",result1);
        imshow("result_b",result);
        addWeighted(result1,1,result,1,0., result);
        if(count%1==0)
        imshow("result_a",result);
              /*  std::vector<Vec2f>::const_iterator it1= lines.begin();
        for(it1=lines.begin();it1<lines.end();it1++)
        {
        }
        //Mat output(contours.rows,contours.cols,CV_8U,Scalar(255));
        // removing two similar lines
       /* for(int k=0;k<lines.end()-lines.begin()-1;k++)
        {
        if((rho_values[k]-rho_values[k+1]<=1)&&(theta_values[k]-theta_values[k+1]<=0.1))
        cout<<"do nothing"<<endl;
    	else
    	// line(( output, (rho_values[k]/cos(theta_values[k]),0), (rho_values[k]-output.rows*sin(theta_values[k]))/cos(theta_values[k]),output.rows), Scalar(255), 2); 
    	}*/
        imshow("Hough",hough);
        //imwrite("hough.jpg",hough);
       // imshow("output",output);
      /*  for(int i=0; i<hough.rows;i++)
        {
        for(int j=0; j<hough.cols;j++)
        { if(hough.at<uchar>(i,j))
        {
       // cout<<"white"<<endl;
       //if(count==0)
       //cout<<"The white point is ("<<j<<","<<i<<")"<<endl;
        }}}*/
            oVideoWriter.write(ortho); //writer the frame into the file
       // imwrite("hough1.jpg",hough);
        //imshow("result",result);*/
      
      
        int k;
        //if((k = waitKey() & 255)==27)
          //  return 0;
        cvWaitKey(30);
        src.release();
        ortho.release();
        hough.release();
        //houghP.release();
       // result.release();
        contours.release();
        contoursInv.release();
        lines.clear();
        count++;
        result.copyTo(result1);
        //lines1.clear();
        //li.clear();
  }
    return 0;
}	
