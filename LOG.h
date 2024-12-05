#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

class LOG
{
private:
	
	static LOG* instance;
	LOG();
	LOG(const LOG&) {}
	~LOG() {}
public:
	//ofstream f;
	static LOG & getInstance();
	static void  destroyInstance();
	void logAddAnimal();
	void logAddCampaign();
	void logADRequests();
	void logChangeParameters();
	void logDeleteAnimal();
	void logDeleteCampaign();
	void logFormAdoption();
	void logLogAdmin();
	void logLogClient();
	void logRegister();
	void logReportEvent();
	void logSearchAnimal();
	void logSendCampaign();
	void logShowAnimals();
	void logShowRequests();
};

//auto ts = std::time(0);
//_log._out << "[" << std::localtime(&ts) << "] " << str();
//if (_log._console) std::cout << str();