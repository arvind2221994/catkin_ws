#include <iostream>
#include <math.h>
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <std_msgs/String.h>
#define PIBY180 0.01745329251 
#define EARTHRADIUS 6378100
#define WAYPOINTNO 1
#define PI 3.14159265358979323846

double gpsway[WAYPOINTNO][2]={{12.99139 , 80.23361 }};

using namespace std;
class GpsTest{
    public:
        // Type for GPS messages
        sensor_msgs::NavSatFix gpsMsgprsnt;
        double theta;

        // Constructor
        GpsTest(ros::NodeHandle nh_){
            // Subscribing to the topic /fix
            n=nh_;
            gps_sub = n.subscribe("/fix", 100, &GpsTest::gpsCallback, this);
        }

        // Callback Function for the GPS
        void gpsCallback(const sensor_msgs::NavSatFixConstPtr &msg){
            //std::cout<<"in gps callbback"<<std::endl;
            gpsMsgprsnt = *msg;
            std::cout<<gpsMsgprsnt<<std::endl;
            latprev=latprsnt;
            longprev=longprsnt;
            
            //keeping latitude const and calculating angle phi (done for gpsway point and prev gps point
            latprsnt= gpsMsgprsnt.latitude ;
                      //12.9917215 ;
            longprsnt= gpsMsgprsnt.longitude ;
                       //80.230916667 ;
            //double testlat=12.988888889;
          //  double testlong=80.233611112;
		  //theta=angle(latprsnt,gpsway[0][0],testlat, longprsnt,gpsway[0][1],testlong);
            theta=angle(latprsnt,gpsway[0][0],latprev,longprsnt,gpsway[0][1],longprev);
            cout<<"theta is given by "<<rad2deg(theta)<<endl;
        }
        
        
        private:
        //distance between gps coordinates
        double dist(double lat2,double lat1,double lon2,double lon1){
            double theta, dist;
            theta = lon1 - lon2;
            dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
            dist = acos(dist);
            cout<<" dist anngle "<<dist<<endl;

            //dist = rad2deg(dist);
            //dist = dist * 60 * 1.1515 * 1.609344 * 1000;
            //cout<<"dist btwn points "<<dist<<endl;
            return (dist);
        }
       
        double deg2rad(double deg) {
            return (deg * PI / 180);
        }
        double rad2deg(double rad) {
            return (rad * 180 / PI);
        }

        //angle between three gps points (our theata c here)(lat1-lat2 is the horizontal line)
        double angle(double lat3,double lat2,double lat1,double long3,double long2,double long1){
            double a=dist(lat3,lat2,long3,long2);
            double b=dist(lat1,lat2,long1,long2);
            double c=dist(lat3,lat1,long3,long1);
            
            double return_angle=acos((cos(c)-(cos(a)*cos(b)))/(sin(a)*sin(b)));  //formula of cosines on spheres
            return return_angle;
        }
        
        //internal variables 
        double latprev,longprev;
        double latprsnt,longprsnt;
        double gps[WAYPOINTNO][2];

        // Nodehandle
        ros::NodeHandle n;
        // Subscriber
        ros::Subscriber gps_sub;
};

int main(int argc, char** argv)
{

    // Initializing the node for the GPS
    ros::init(argc, argv, "gps_compass");
    ros::NodeHandle nhg,nhc;
    GpsTest *gps= new GpsTest(nhg); 
    std::cout<<"reach here"<<std::endl; 
    ros::spin();
    return 0;
}

