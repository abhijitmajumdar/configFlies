#ifndef _CONFIGLOADER_H
#define _CONFIGLOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class qConfig{
	public:
		static void readConfigFile(std::string configFileName,int* kp,float* ki, double* kd);
	private:
		static void store_line(std::string key,std::string val,int* kp,float* ki, double* kd);
};

#endif //_CONFIGLOADER_H
