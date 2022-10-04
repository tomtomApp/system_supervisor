/*
 * ********************************************************************************
 * SYSTEM            | obstacle aboidance
 * Publisher         | cmd_vel_pub
 * Subscriber        | state_sub
 *                   | cmd_vel_move_base_sub
 *                   | cmd_vel_obstacle_avoidance_sub
 * ********************************************************************************
*/
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/transform_datatypes.h>
#include <std_msgs/Int8.h>
#include <std_msgs/String.h>

ros::Publisher cmd_vel_pub;
ros::Publisher state_pub;

ros::Subscriber cmd_vel_joystick_sub;
ros::Subscriber cmd_vel_keyboard_sub;
ros::Subscriber cmd_vel_automatic_sub;

geometry_msgs::Twist cmd_vel;
geometry_msgs::Twist cmd_vel_joystick;
geometry_msgs::Twist cmd_vel_keyboard;
geometry_msgs::Twist cmd_vel_automatic;

void cmd_vel_joystick_callback(const geometry_msgs::Twist::ConstPtr &cmd_vel)
{
    cmd_vel_joystick = *cmd_vel;
}

void cmd_vel_keyboard_callback(const geometry_msgs::Twist::ConstPtr &cmd_vel)
{
    cmd_vel_keyboard = *cmd_vel;
}

void cmd_vel_automatic_callback(const geometry_msgs::Twist::ConstPtr &cmd_vel)
{
    cmd_vel_automatic = *cmd_vel;
}

/*
void state_obstacle_avoidance_callback(const std_msgs::Int8::ConstPtr &state)
{
    
       state = 0 right obstacle
       state = 1 left obstracle
       state = 2 no obstracle detection
    
    if (state->data == 0) {
        cmd_vel.linear.x  = cmd_vel_obstacle_avoidance.linear.x;
		cmd_vel.angular.z = cmd_vel_obstacle_avoidance.angular.z;
    } else if (state->data == 1) {
        cmd_vel.linear.x  = cmd_vel_obstacle_avoidance.linear.x;
		cmd_vel.angular.z = cmd_vel_obstacle_avoidance.angular.z;
    } else if (state->data == 2) {
        cmd_vel.linear.x  = cmd_vel_move_base.linear.x;
		cmd_vel.angular.z = cmd_vel_move_base.angular.z;
    }

    cmd_vel_pub.publish(cmd_vel);
}
*/

int main(int argc, char** argv)
{
    ros::init(argc, argv, "supervisor");

    ros::NodeHandle nh;

    cmd_vel_joystick_sub = nh.subscribe("/cmd_vel_joystick", 10, cmd_vel_joystick_callback);
    cmd_vel_keyboard_sub = nh.subscribe("/cmd_vel_keyboard", 10, cmd_vel_keyboard_callback);
    cmd_vel_automatic_sub = nh.subscribe("/cmd_vel_automatic", 10, cmd_vel_automatic_callback);

    state_pub = nh.advertise<std_msgs::Int8>("/state", 10);
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::Rate loop_rate(50);

    while (ros::ok())
    {
        std_msgs::Int8 state_msg;
        //geometry_msgs::Twist cmd_vel_msg;
        
        int state_data;
        if (cmd_vel_joystick.linear.x != 0 || cmd_vel_joystick.angular.z != 0) {
            state_msg.data = 1;
            state_data = 1;
        } else if (cmd_vel_keyboard.linear.x != 0 || cmd_vel_keyboard.angular.z != 0) {
            state_msg.data = 2;
            state_data = 2;
        } else if (cmd_vel_automatic.linear.x != 0 || cmd_vel_automatic.angular.z != 0) {
            state_msg.data = 3;
            state_data = 3;
        } else {
            state_msg.data = 4;
            state_data = 4;
        }

        state_pub.publish(state_msg);

        if (state_data == 1) {
            cmd_vel.linear.x  = cmd_vel_joystick.linear.x;
            cmd_vel.angular.z = cmd_vel_joystick.angular.z;
        } else if (state_data == 2) {
            cmd_vel.linear.x  = cmd_vel_keyboard.linear.x;
            cmd_vel.angular.z = cmd_vel_keyboard.angular.z;
        } else if (state_data == 3) {
            cmd_vel.linear.x  = cmd_vel_automatic.linear.x;
            cmd_vel.angular.z = cmd_vel_automatic.angular.z;
        } else if (state_data == 4) {
            cmd_vel.linear.x  = 0.0;
            cmd_vel.angular.z = 0.0;
        }

        // saturation
        if (cmd_vel.linear.x > 0.3) {
            cmd_vel.linear.x = 0.3;
        } else if (cmd_vel.linear.x < -0.3) {
            cmd_vel.linear.x = -0.3;
        }
        if (cmd_vel.angular.z > 2.0) {
            cmd_vel.angular.z = 2.0;
        } else if (cmd_vel.angular.z < -2.0) {
            cmd_vel.angular.z = -2.0;
        }
        
        cmd_vel_pub.publish(cmd_vel);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}