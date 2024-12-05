#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Protocoale.h"
#include "Admin.h"


using namespace std;
class ProtocolLogAdmin : public Protocoale
{
private:
	string username;
	string password;
	//string msg;
public:
	ProtocolLogAdmin() {}
	string handleMessage(string msg);
};

