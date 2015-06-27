#include <sstream>

#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

using namespace std;

class InitialStatusSender {
    public:
        InitialStatusSender()
        {
            _pub = _nh.advertise < geometry_msgs::PoseWithCovarianceStamped > ("initialpose", 1, true);
        }

        void publishInitialPose()
        {
            stringstream param_basename;

            param_basename << "initialpose";

            geometry_msgs::PoseWithCovarianceStamped initialpose;

            double x, y, th, cov_x, cov_y, cov_th;

            _nh.getParam(param_basename.str() + "/x", x);
            _nh.getParam(param_basename.str() + "/y", y);
            _nh.getParam(param_basename.str() + "/th", th);
            _nh.getParam(param_basename.str() + "/cov_x", cov_x);
            _nh.getParam(param_basename.str() + "/cov_y", cov_y);
            _nh.getParam(param_basename.str() + "/cov_th", cov_th);

            initialpose.header.frame_id = "/map";

            initialpose.pose.pose.position.x = (float) x;
            initialpose.pose.pose.position.y = (float) y;
            initialpose.pose.pose.position.z = 0.0;

            initialpose.pose.covariance[0] = cov_x;
            initialpose.pose.covariance[7] = cov_y;
            initialpose.pose.covariance[35] = cov_th;

            initialpose.pose.pose.orientation.w = cos(th / 2.0);
            initialpose.pose.pose.orientation.z = sin(th / 2.0);
            initialpose.pose.pose.orientation.x = 0.0;
            initialpose.pose.pose.orientation.y = 0.0;

            _pub.publish(initialpose);
        }

    private:
        // nodes
        ros::NodeHandle _nh;

        // publishers and subscribers
        ros::Publisher _pub;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "initial_pose_sender");

    InitialStatusSender ips;

    ips.publishInitialPose();

    ros::spinOnce();

    return 0;
}
