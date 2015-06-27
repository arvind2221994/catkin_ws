#include <iostream>
#include <math.h>
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <geometry_msgs/TwistStamped.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#define PI 3.14159265358979323846
#define EARTHRADIUS 63781370
#define WAYPOINTNO 1

double latprsnt,longprsnt;
double theta=0,phi=0;
double gps[WAYPOINTNO][2]={{12.98973,80.229167}};
//{{12.9918,80.2334}};//GC READINGS
//{{12.9856,80.235278}};//narmad 
//{{12.9867,80.23278}};//gymkana 
double firstpoint[1][2];
double firscompassdata=0;
double distprsnt=0;
int waypointno=0;
int flag=0;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

using namespace sensor_msgs;
using namespace geometry_msgs;
using namespace message_filters;
using namespace std_msgs;
using namespace std;

double deg2rad(double deg) {
    return (deg * PI / 180);
}

double rad2deg(double rad) {
    return (rad * 180 / PI);
}

//distance between gps coordinates
double dist(double lat2,double lat1,double lon2,double lon1){
    double theta, dist,dist1,dist2;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);

    cout<<"                 dist in rad "<<dist<<endl;
    
    dist2 = rad2deg(dist);
    cout<<"                 input is    "<<lat1<<" "<<lon1<<" "<<lat2<<" "<<lon2<<endl; 
    dist1 = dist2 * 60 * 1.1515 * 1.609344 * 1000;
    cout<<"                 dist btwn points "<<dist1<<endl<<endl;
    return (dist);
}

double distm(double lat2,double lat1,double lon2,double lon1){
    double theta, dist,dist1,dist2;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);

    cout<<"                 dist in rad "<<dist<<endl;
    
    dist2 = rad2deg(dist);
    cout<<"                 input is    "<<lat1<<" "<<lon1<<" "<<lat2<<" "<<lon2<<endl; 
    dist1 = dist2 * 60 * 1.1515 * 1.609344 * 1000;
    cout<<"                 dist btwn points "<<dist1<<endl<<endl;
    return (dist1);
}

//angle between three gps points (our theata c here)(lat1-lat2 is the horizontal line)
double angle(double lat3,double lat2,double lat1,double long3,double long2,double long1){
    double a=dist(lat3,lat2,long3,long2);
    double b=dist(lat1,lat2,long1,long2);
    double c=dist(lat3,lat1,long3,long1);
    
    double return_cos=((cos(c)-(cos(a)*cos(b)))/(sin(a)*sin(b)));  //formula of cosines on spheres
    
    double return_angle;
    return_angle=acos(return_cos);
    return_angle=rad2deg(return_angle);
    return return_angle;
}

void callback(const NavSatFixConstPtr& gpsmsg, const TwistStampedConstPtr& compassmsg){
    // Solve all of perception here...
    cout<<"in callback"<<endl;

    //Gps calculations 
    cout<<"     new -lat-long "<<latprsnt<<" "<<longprsnt<<endl;
    
    if(flag == 0){
        latprsnt= gpsmsg->latitude;
        longprsnt= gpsmsg->longitude;

        if(waypointno == 0){
            firstpoint[0][0]=latprsnt;
            firstpoint[0][1]=longprsnt;
            
            //Compass calculations
            phi=compassmsg->twist.angular.x;
            phi=360 - phi;
            firscompassdata=phi;
        }
        
        //keeping longitude const and calculating angle phi (done for gps point and prev gps point
        double testlat=latprsnt+0.1;
        double testlong=longprsnt+0.1;
        double thetaN,thetaE;

        thetaN=angle(gps[waypointno][0],latprsnt,testlat,gps[waypointno][1],longprsnt,longprsnt);
        thetaE=angle(gps[waypointno][0],latprsnt,latprsnt,gps[waypointno][1],longprsnt,testlong);
        distprsnt=distm(gps[waypointno][0],latprsnt,gps[waypointno][1],longprsnt);

        if(thetaN <= 90){
            if(thetaE <= 90){
                //quadrant 1
                theta=thetaN;
            }else if(thetaE > 90){
                //quadrant 2
                theta=360 - thetaN;
            }
        }else if(thetaN > 90){
            if(thetaE <=90){
                //quadrant 4
                theta=thetaN;
            }else if(thetaE > 90){
                //quadrant 3
                theta=360 - thetaN;
            }
        }
        waypointno++;
        flag++;
    }


    //sending goal to navigation stack
    //tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    //wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    //we'll send a goal to the robot to move 1 meter forward
    goal.target_pose.header.frame_id = "base_link";
    goal.target_pose.header.stamp = ros::Time::now();
    
    //sending goal in terms of base_link coordinates
    goal.target_pose.pose.position.x = distprsnt*sin(theta-firscompassdata);//direction of movement and compass maybe y
    goal.target_pose.pose.position.y = distprsnt*cos(theta-firscompassdata);//direction perpendicular to above maybe x

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        ROS_INFO("Hooray, the base moved 10 meter forward");
        flag=0;
    }
    else{
        ROS_INFO("The base failed to move forward 10 meter for some reason");
    }
}
    

int main(int argc, char** argv){
    ros::init(argc, argv, "gps_com_filter_node");
    ros::NodeHandle nh;
    message_filters::Subscriber<NavSatFix> gps_sub(nh, "/fix", 1);
    message_filters::Subscriber<TwistStamped> compass_sub(nh, "/compass_data", 1);

    typedef sync_policies::ApproximateTime<NavSatFix,TwistStamped> MySyncPolicy;
    // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
    message_filters::Synchronizer<MySyncPolicy> sync(MySyncPolicy(10),gps_sub,compass_sub);
    sync.registerCallback(boost::bind(&callback, _1, _2));
    
    cout<<"trying something"<<endl;
    ros::spin();

    return 0;
}
