#include "robot_info/robot_info_class.h"
#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include <ros/ros.h>
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
ros::init(argc, argv, "robot_manager");
ros::NodeHandle nh;
HydraulicSystemMonitor HSM = HydraulicSystemMonitor("45C", "100", "250 bar");
AGVRobotInfo robot1 = AGVRobotInfo(nh, "Cooper100", "567A359", "169.254.5.180", "3.5.8", "100 Kg", HSM);

ros::Rate loop_rate(1);

    while (ros::ok())
    {
        robot1.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

return 0;

}