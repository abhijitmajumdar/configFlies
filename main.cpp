#include <iostream>
#include "configLoader.h"

using namespace std;

enum{
	TIME_TO_UPDATE_TARGETANGLE = 0,
	TIME_TO_COMPUTE,
	TIME_TO_UPDATEMOTOR,
	TIME_TO_ROS_PUBLISH,
	TIME_TO_ROS_SPIN,
	TIME_TO_ARM,
	TIME_TO_DEBUG_DISPLAY,
	QuadID,
	NUM_LONG_CFG_VARIABLES
};
std::map<int,lConst> longConstants = {
	{TIME_TO_UPDATE_TARGETANGLE,{"TIME_TO_UPDATE_TARGETANGLE",100000}},
	{TIME_TO_COMPUTE,{"TIME_TO_COMPUTE",5000}},
	{TIME_TO_UPDATEMOTOR,{"TIME_TO_UPDATEMOTOR",10000}},
	{TIME_TO_ROS_PUBLISH,{"TIME_TO_ROS_PUBLISH",200000}},
	{TIME_TO_ROS_SPIN,{"TIME_TO_ROS_SPIN",200000}},
	{TIME_TO_ARM,{"TIME_TO_ARM",3000000}},
	{TIME_TO_DEBUG_DISPLAY,{"TIME_TO_DEBUG_DISPLAY",1000000}},
	{QuadID,{"QuadID",4745}}
};

enum{
	ANGLE_UPDATE_STEP = 0,
	I_THROTTLE_TRIGGER,
	YAW_P,
	YAW_I,
	I_YAW_TRIGGER,
	CH_THROTTLE_CALIBRATE,
	CH_PITCH_CALIBRATE,
	CH_ROLL_CALIBRATE,
	CH_YAW_CALIBRATE,
	CH_SWC_CALIBRATE,
	CH_SWB_CALIBRATE,
	YAW_PA,
	NUM_FLOAT_CFG_VARIABLES
};
std::map<int,fConst> floatConstants = {
	{ANGLE_UPDATE_STEP,{"ANGLE_UPDATE_STEP",0.314}},
	{I_THROTTLE_TRIGGER,{"I_THROTTLE_TRIGGER",1.5}},
	{YAW_P,{"YAW_P",0.5}},
	{YAW_I,{"YAW_I",0.0000001}},
	{I_YAW_TRIGGER,{"I_YAW_TRIGGER",1.4}},
	{CH_THROTTLE_CALIBRATE,{"CH_THROTTLE_CALIBRATE",1.0}},
	{CH_PITCH_CALIBRATE,{"CH_PITCH_CALIBRATE",1.5}},
	{CH_ROLL_CALIBRATE,{"CH_ROLL_CALIBRATE",1.5}},
	{CH_YAW_CALIBRATE,{"CH_YAW_CALIBRATE",1.5}},
	{CH_SWC_CALIBRATE,{"CH_SWC_CALIBRATE",1.0}},
	{CH_SWB_CALIBRATE,{"CH_SWB_CALIBRATE",1.0}},
	{YAW_PA,{"YAW_PA",4.0}}
};

enum{
	doTargetAngleUpdate = 0,
	debugDisplay,
	NUM_BOOL_CFG_VARIABLES
};
std::map<int,bConst> boolConstants = {
	{doTargetAngleUpdate,{"doTargetAngleUpdate",false}},
	{debugDisplay,{"debugDisplay",false}}
};

int main(int argc, char* argv[])
{
	char file[] = "config.txt";
	cout<<argc<<" argument(s)\n";
	while(argc--)
		cout<<argc<<" : "<<argv[argc]<<'\n';
	cout<<"\nBegin\n\n";
	qConfig::readConfigFile(file,longConstants,NUM_LONG_CFG_VARIABLES,floatConstants,NUM_FLOAT_CFG_VARIABLES,boolConstants,NUM_BOOL_CFG_VARIABLES);
	cout<<"Parameters set are\n";
	for(int i=0;i<NUM_LONG_CFG_VARIABLES;i++)
		cout<< longConstants[i].name<<"->"<<longConstants[i].value <<"\n";
	for(int i=0;i<NUM_FLOAT_CFG_VARIABLES;i++)
		cout<< floatConstants[i].name<<"->"<<floatConstants[i].value <<"\n";
	for(int i=0;i<NUM_BOOL_CFG_VARIABLES;i++)
		cout<< boolConstants[i].name<<"->"<<boolConstants[i].value <<"\n";
	return 0;
}
