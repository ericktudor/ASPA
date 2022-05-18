#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolFormAdoption : public Protocoale
{
private:
	string ID_user;
	string username;
	string R1;
	string R2;
	string R3;
	string R4;
	string R5;
	string R6;
	//string msg;
public:
	ProtocolFormAdoption() {}
	string handleMessage(string msg);
};

