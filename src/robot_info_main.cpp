#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
#include <iostream>
#include <string>
int main(int argc, char *argv[])
{
ros::init(argc, argv, "robot_manager");
ros::NodeHandle nh;

RobotInfo robot1 = RobotInfo(nh, "description", "id167", "fakeipaddress", "ver 1");
//RobotManager rm = RobotManager("Turty1" ,"TurtleBot3", "/robot1/odom", &nh);
//rm.print_specifications();
//RobotManager rm2 = RobotManager("TurtleBot3", "Turty2", "/robot2/odom", &nh);
//rm2.print_specifications();


//robot1.publish_data();
//ros::spin();

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        robot1.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

return 0;
}
