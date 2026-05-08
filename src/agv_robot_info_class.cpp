#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"


AGVRobotInfo::AGVRobotInfo(ros::NodeHandle node_handle, std::string rd, std::string sn, std::string ia, std::string fv, std::string mp, HydraulicSystemMonitor h) : RobotInfo(node_handle, rd, sn, ia, fv),  system(h)
{

maximum_payload = mp;
//system = h;


}

AGVRobotInfo::~AGVRobotInfo()
{

}
void AGVRobotInfo::setpayload(int i)
{



}

void AGVRobotInfo::publish_data()
{

    // Create and fill the message
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number:" + serial_number;
    msg.data_field_03 = "ip address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "maximum_payload: " + maximum_payload;
    msg.data_field_06 = "hydraulic_oil_temperature: " + system.getTemperature();
    msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + system.getFillLevel();
    msg.data_field_08 = "hydraulic_oil_pressure: " + system.getOilPressure();
    
    //ROS_INFO("getTemperature: %s", system.getTemperature());
    // Publish the message
    robot_info_pub.publish(msg);
}