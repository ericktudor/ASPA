#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolReportEvent : public Protocoale
{
private:
	string name;
	string surname;
	string tel;
	string location;
	string description;
	//string msg;
public:
	ProtocolReportEvent() {}
	string handleMessage(string msg);
};

