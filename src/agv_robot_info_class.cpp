#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"



AGVRobotInfo::AGVRobotInfo(ros::NodeHandle node_handle, std::string rd, std::string sn, std::string ia, std::string fv, int mp) : RobotInfo(node_handle, rd, sn, ia, fv)
{

maximum_payload = mp;


}

AGVRobotInfo::~AGVRobotInfo()
{

}
void AGVRobotInfo::setpayload(int i)
{

maximum_payload = i;

}

void AGVRobotInfo::publish_data()
{

    // Create and fill the message
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number:" + serial_number;
    msg.data_field_03 = "ip address: " + ip_address;
    msg.data_field_04 = "firmware_version" + firmware_version;
    msg.data_field_05 = "payload " + std::to_string(maximum_payload);

    // Publish the message
    robot_info_pub.publish(msg);
}