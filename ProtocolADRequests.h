#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolADRequests : public Protocoale
{
private:
	string ID_request;
	string status;
	//string msg;
public:
	ProtocolADRequests() {}
	string handleMessage(string msg);

};

