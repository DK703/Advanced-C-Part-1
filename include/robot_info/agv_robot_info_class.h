#include "robot_info_class.h"

class AGVRobotInfo: public RobotInfo 
{
public:
    AGVRobotInfo(ros::NodeHandle node_handle, std::string rd, std::string sn, std::string ia, std::string fv, int mp);
    ~AGVRobotInfo(); 
    virtual void publish_data();
    void setpayload(int i);
protected: 
    int maximum_payload;
};