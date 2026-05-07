#pragma once
#include <iostream>
#include <string>
#include <ros/ros.h>
#include "robotinfo_msgs/RobotInfo10Fields.h"

class RobotInfo
{
    public:
        RobotInfo(ros::NodeHandle node_handle, std::string rd, std::string sn, std::string ia, std::string fv);
        ~RobotInfo();
        virtual void publish_data();
    protected:
        std::string robot_description;
        std::string serial_number;
        std::string ip_address;
        std::string firmware_version; 
        ros::NodeHandle nh;
        ros::Publisher robot_info_pub;
};