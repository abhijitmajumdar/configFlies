#include "configLoader.h"

using namespace std;

//Make sure to compile with "-std=c++11"
void qConfig::store_line(std::string key,std::string val,int* kp,float* ki, double* kd)
{
	if(key=="kP")
	{
		int i = stoi(val);
		if(i>0)
			*kp = i;
	}
	else if(key=="kD")
	{
		double i = stod(val);
		if(i>0)
			*kd = i;
	}
	else if(key=="kI")
	{
		float i = stof(val);
		if(i>0)
			*ki = i;
	}
	//Can also use stoi,stod,stof,stol etc.
}

void qConfig::readConfigFile(std::string configFileName,int* kp,float* ki, double* kd)
{
	fstream configFile;
	configFile.open(configFileName,ios::out | ios::in);
	if(configFile.is_open())
	{
		//Load the configurations
		string line;
		while(getline(configFile,line))
		{
			istringstream is_line(line);
			string key;
			if( getline(is_line, key, '=') )
			{
				string value;
				if(getline(is_line, value) ) 
				  store_line(key,value,kp,ki,kd);
			}
		}
		
		//Close file at the end
		configFile.close();
	}
	else
	{
		cout<<"Error reading config file. Loading deafult values";
	}
}
