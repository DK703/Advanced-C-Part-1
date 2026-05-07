#pragma once
#include <iostream>
#include <string>
#include <ros/ros.h>


class HydraulicSystemMonitor
{



public:
    HydraulicSystemMonitor(std::string hot, std::string hotfl, std::string hop);
    ~HydraulicSystemMonitor();
    std::string getTemperature();
    std::string getFillLevel();
    std::string getOilPressure();
    

protected:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;




};