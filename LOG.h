#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#include <ctime>
#include <iomanip>

using namespace std;

class LOG
{
private:
	
	static LOG* instance;
	LOG();
	LOG(const LOG&) {}
	~LOG() {}
public:
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