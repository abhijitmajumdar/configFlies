#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static int kP=0,kI=0,kD=0;

int main(int argc, char* argv[])
{
	string line;
	cout<<argc<<" arguments\n";
	while(argc--)
		cout<<argc<<" : "<<argv[argc]<<'\n';
	cout<<"Begin\n";
	fstream configFile;
	configFile.open("config.txt",ios::out | ios::in);
	if(configFile.is_open())
	{
		//Load the configurations
		while(getline(configFile,line))
		{
			cout<<line<<'\n';
		}
		configFile.clear();
		configFile>>line;
		configFile>>line;
		configFile>>line;
		
		configFile.clear();
		
		//Write the configurations
		configFile<<"kP="<<kP+1<<"\n";
		configFile<<"kI="<<kI+2<<"\n";
		configFile<<"kD="<<kD+3<<"\n";
		
		//Close file at the end
		configFile.close();
	}
	else
	{
		cout<<"Error reading config file. Loading deafult values";
	}
	return 0;
}
