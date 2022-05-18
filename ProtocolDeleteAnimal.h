#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

//38/id/

class ProtocolDeleteAnimal : public Protocoale
{
private:
	string ID_animal;
	//string msg;
public:
	ProtocolDeleteAnimal() {}
	string handleMessage(string msg);
	
};

