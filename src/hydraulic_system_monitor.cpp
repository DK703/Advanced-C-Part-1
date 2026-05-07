#include "robot_info/hydraulic_system_monitor.h"
#include <ros/ros.h>
#include <iostream>
#include <string>

HydraulicSystemMonitor::HydraulicSystemMonitor(std::string hot, std::string hotfl, std::string hop)
{

    hydraulic_oil_temperature = hot;
    hydraulic_oil_tank_fill_level = hotfl;
    hydraulic_oil_pressure = hop;


}

HydraulicSystemMonitor::~HydraulicSystemMonitor()
{

}

std::string HydraulicSystemMonitor::getTemperature()
{
   return hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::getFillLevel()
{
    return hydraulic_oil_tank_fill_level;

}
std::string HydraulicSystemMonitor::getOilPressure()
{

    return hydraulic_oil_pressure;
}