#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolLogClient : public Protocoale
{
private:
	string username;
	string password;
	string msg;
public:
	ProtocolLogClient() {}
	string handleMessage(string msg);
};

