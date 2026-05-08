#include "robot_info_class.h"
#include "hydraulic_system_monitor.h"

class AGVRobotInfo: public RobotInfo 
{
public:
    AGVRobotInfo(ros::NodeHandle node_handle, std::string rd, std::string sn, std::string ia, std::string fv, std::string mp, HydraulicSystemMonitor h);
    ~AGVRobotInfo(); 
    virtual void publish_data();
    void setpayload(int i);
protected: 
    std::string maximum_payload;
    HydraulicSystemMonitor system;
};