#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

RobotInfo::RobotInfo(ros::NodeHandle node_handle, std::string rd, std::string sn, std::string ia, std::string fv)
{

nh = node_handle;
robot_description = rd;
serial_number = sn;
ip_address = ia;
firmware_version = fv;
robot_info_pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
}

RobotInfo::~RobotInfo()
{
}

void RobotInfo::publish_data()
{

ROS_INFO("Robot Description: %s", robot_description.c_str());
ROS_INFO("Serial_Number: %s", serial_number.c_str());
ROS_INFO("Ip_Address: %s", ip_address.c_str());
ROS_INFO("Firmware Version: %s", firmware_version.c_str());

    // Create and fill the message
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number:" + serial_number;
    msg.data_field_03 = "ip address: " + ip_address;
    msg.data_field_04 = "firmware_version" + firmware_version;

    // Publish the message
    robot_info_pub.publish(msg);
}


