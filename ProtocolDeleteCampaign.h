#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

//40/id

class ProtocolDeleteCampaign : public Protocoale
{
private:
	string ID_campaign;
	//string msg;
public:
	ProtocolDeleteCampaign() {}
	string handleMessage(string msg);
};

