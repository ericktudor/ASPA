#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolSendCampaign : public Protocoale
{
private:
	//string msg;
public:
	ProtocolSendCampaign() {}
	string handleMessage(string msg);
};

