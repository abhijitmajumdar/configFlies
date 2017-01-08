#include <iostream>
#include "configLoader.h"

using namespace std;

static int kP=0;
static float kI=0;
static double kD=0;

int main(int argc, char* argv[])
{
	cout<<argc<<" argument(s)\n";
	while(argc--)
		cout<<argc<<" : "<<argv[argc]<<'\n';
	cout<<"\nBegin\n\n";
	qConfig::readConfigFile("config.txt",&kP,&kI,&kD);
	cout<<"Parameters set are\n";
	cout<<"kP = "<<kP<<"\n";
	cout<<"kI = "<<kI<<"\n";
	cout<<"kD = "<<kD<<"\n";
	return 0;
}
