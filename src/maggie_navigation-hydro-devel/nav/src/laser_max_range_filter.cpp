/*!
 \file        laser_max_range_filter.cpp
 \author      Arnaud Ramey <arnaud.a.ramey@gmail.com>
 -- Robotics Lab, University Carlos III of Madrid
 \date        2011/10

 ______________________________________________________________________________

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ______________________________________________________________________________

 laser_max_range_filter:
 This executable subscribes to a laser scan <laser_src_topic>
 and sets all the laser measurements out of range to the max value.
 It then republishes it to <laser_src_topic>

 http://ros-users.122217.n3.nabble.com/Clear-cells-in-costmap-with-max-laser-range-td973150.html

 \section Parameters
 - \b laser_src_topic
 [string] (default: "/base_scan")
 Where to get the unfiltered scans.

 - \b laser_dst_topic
 [string] (default: "/base_scan_filtered")
 Where to republish them.

 \section Subscriptions
 - \b {laser_src_topic}
 [sensor_msgs::LaserScan]


 \section Publications
 - \b {laser_dst_topic}
 [sensor_msgs::LaserScan]
 The filtered scan

 */

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class LaserMaxRangeFilter {
    public:
        LaserMaxRangeFilter(const std::string & laser_src_topic, const std::string & laser_dst_topic)
        {
            ROS_DEBUG("LaserMaxRangeFilter('%s' -> '%s')", laser_src_topic.c_str(), laser_dst_topic.c_str());
            scan_publisher = n.advertise<sensor_msgs::LaserScan>(laser_dst_topic, 1);
            scan_subscriber = n.subscribe(laser_src_topic, 1, &LaserMaxRangeFilter::scan_callback, this);
        }

        //////////////////////////////////////////////////////////////////////////////

        //! the callback where the filtering is done
        void scan_callback(const sensor_msgs::LaserScan::ConstPtr& scan_src)
        {
            // first make a copy of the src scan
            sensor_msgs::LaserScan scan_dst(*scan_src);
            ROS_DEBUG("scan_dst.header.seq:%i, range_min:%g, range_max:%g", scan_dst.header.seq, scan_dst.range_min,
                      scan_dst.range_max);

            float* curr_range = &(scan_dst.ranges[0]);
            for (unsigned int idx = 0; idx < scan_dst.ranges.size(); ++idx) {
                //ROS_DEBUG("idx:%i, curr_range:%g", idx, *curr_range);
                if (*curr_range <= scan_dst.range_min || *curr_range >= scan_dst.range_max) {
                    //ROS_DEBUG("idx:%i -> changing range", idx);
                    *curr_range = scan_dst.range_max - 1;
                } // end if curr_range > range_max
                ++curr_range;
            } // end loop idx

            // emit our filtered scan
            scan_publisher.publish(scan_dst);
        } // end scan_callback();

        //////////////////////////////////////////////////////////////////////////////

    private:
        ros::NodeHandle n;
        ros::Subscriber scan_subscriber;
        ros::Publisher scan_publisher;

};

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
    ROS_DEBUG("main()");
    ros::init(argc, argv, "laser_max_range_filter");
    ros::NodeHandle nh("~");
    std::string laser_src_topic, laser_dst_topic;
    nh.param("laser_src_topic", laser_src_topic, std::string("base_scan"));
    nh.param("laser_dst_topic", laser_dst_topic, std::string("base_scan_filtered"));
    ROS_INFO("laser_max_range_filter:This executable subscribes to a laser scan '%s', "
             "and sets all the laser measurements out of range to the max value. "
             "It then republishes it to '%s'.",
             laser_src_topic.c_str(), laser_dst_topic.c_str());
    LaserMaxRangeFilter filter(laser_src_topic, laser_dst_topic);

    /**
     * ros::spin() will enter a loop, pumping callbacks.  With this version, all
     * callbacks will be called from within this thread (the main one).  ros::spin()
     * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
     */
    ros::spin();
    return 0;
}
