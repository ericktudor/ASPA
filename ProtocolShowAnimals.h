#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolShowAnimals : public Protocoale
{
private:
	string ID_animal;
	string age;
	string sex;
	string location;
	string size;
	string species;
	//string msg;
public:
	ProtocolShowAnimals() {}
	string handleMessage(string msg);

};

