#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

//37/age/sex/location/size/species/

class ProtocolAddAnimal : public Protocoale
{
private:
	string age;
	string sex;
	string location;
	string size;
	string species;
	//string msg;
public:
	ProtocolAddAnimal() {}
	string handleMessage(string msg);

};

