#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolSearchAnimal
{
private:
	string age;
	string sex;
	string location;
	string size;
	string species;
	string msg;
public:
	ProtocolSearchAnimal() {}
	string handleMessage(string msg);
	//string sendMessage(string msg);
};

