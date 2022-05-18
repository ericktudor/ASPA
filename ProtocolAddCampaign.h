#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

//39/zi/luna/an/denumire/locatie/

class ProtocolAddCampaign : public Protocoale
{
private:
	string day;
	string month;
	string year;
	string name;
	string location;
	//string msg;
public:
	ProtocolAddCampaign() {}
	string handleMessage(string msg);
};

