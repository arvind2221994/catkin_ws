#include "ros/ros.h"

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Bool.h>

class TeleopJoy {
    public:
        TeleopJoy();

    private:
        void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

        ros::NodeHandle _nh;

        int axis_analog_linear, axis_analog_angular;
        int axis_digital_linear, axis_digital_angular;
        double scale_linear, scale_angular;

        // base publisher
        ros::Publisher vel_pub_;

        // arms publishers
        ros::Publisher right_arm_vel_pub_;
        ros::Publisher left_arm_vel_pub_;

        // neck publishers
        ros::Publisher neck_pan_vel_pub_; //movement around the z axis
        ros::Publisher neck_tilt_vel_pub_; // movement around the y axis

        ros::Subscriber joy_sub_;
};

////////////////////////////////////////////////////////////////////////////////

TeleopJoy::TeleopJoy() {
    _nh.param("axis_analog_linear", axis_analog_linear, 3);
    _nh.param("axis_analog_angular", axis_analog_angular, 2);
    _nh.param("axis_digital_linear", axis_digital_linear, 1);
    _nh.param("axis_digital_angular", axis_digital_angular, 0);
    _nh.param("scale_angular", scale_angular, (double) 1);
    _nh.param("scale_linear", scale_linear, (double) 1);

    vel_pub_ = _nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);

    // This topics must be checked to match the subscribers (if already existing)

    right_arm_vel_pub_ = _nh.advertise<geometry_msgs::Twist>("body/right_arm_cmd_vel", 1);
    left_arm_vel_pub_ = _nh.advertise<geometry_msgs::Twist>("body/left_arm_cmd_vel", 1);

    neck_pan_vel_pub_ = _nh.advertise<geometry_msgs::Twist>("body/neck_pan_cmd_vel", 1);
    neck_tilt_vel_pub_ = _nh.advertise<geometry_msgs::Twist>("body/neck_tilt_cmd_vel", 1);

    joy_sub_ = _nh.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopJoy::joyCallback, this);
}

////////////////////////////////////////////////////////////////////////////////

void TeleopJoy::joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {
    // A super nice drawing for the code of the buttons on the Logitech RumblePad 2:
    //   ---------------
    //  |  [6]     [7]  |
    //  |  [4]     [5]  |
    //   ---------------
    //  |   |      (3)  |
    //  | --+--  (0) (2)|
    //  |   |      (1)  |
    //  / /-----------\ \
    // / /             \ \

    geometry_msgs::Twist vel;
    vel.linear.x = scale_linear * (joy->axes[axis_analog_linear] + joy->axes[axis_digital_linear]);
    vel.angular.z = scale_angular * (joy->axes[axis_analog_angular] + joy->axes[axis_digital_angular]);

    /* Buttons 0, 1, 2, 3 corrsponds to 1, 2, 3, 4 in the joypad

        Button 0 + joystick = move right arm
        Button 1 + joystick = move left arm
        Button 2 + joystick = pan head
        Button 3 + joystick = tilt head
    */

    if(joy->buttons[0]){
        ROS_INFO_THROTTLE(1, "Button 0 pushed. Moving right arm. \n Emitting linear: %g, angular: %g",
        vel.linear.x, vel.angular.z);
        right_arm_vel_pub_.publish(vel);
    }
    else if(joy->buttons[1]){
        ROS_INFO_THROTTLE(1, "Button 1 pushed. Moving left arm. \n Emitting linear: %g, angular: %g",
        vel.linear.x, vel.angular.z);
        left_arm_vel_pub_.publish(vel);
    }
    else if(joy->buttons[2]){
        ROS_INFO_THROTTLE(1, "Button 2 pushed. Panning head. \n Emitting linear: %g, angular: %g",
        vel.linear.x, vel.angular.z);
        neck_pan_vel_pub_.publish(vel);
    }
    else if(joy->buttons[3]){
        ROS_INFO_THROTTLE(1, "Button 3 pushed. Tilting head. \n Emitting linear: %g, angular: %g",
        vel.linear.x, vel.angular.z);
        neck_tilt_vel_pub_.publish(vel);
    }
    else{
        ROS_INFO_THROTTLE(1, "Emitting linear: %g, angular: %g", vel.linear.x, vel.angular.z);
        vel_pub_.publish(vel);
    }
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    ros::init(argc, argv, "teleop_joy");

    TeleopJoy teleop_joy;

    ros::spin();
}
