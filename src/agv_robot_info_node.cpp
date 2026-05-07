#include "robot_info/robot_info_class.h"
#include "robot_info/agv_robot_info_class.h"
#include <ros/ros.h>
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
ros::init(argc, argv, "robot_manager");
ros::NodeHandle nh;
AGVRobotInfo robot1 = AGVRobotInfo(nh, "description", "id167", "fakeipaddress", "ver 1", 22);

ros::Rate loop_rate(1);

    while (ros::ok())
    {
        robot1.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

return 0;

}