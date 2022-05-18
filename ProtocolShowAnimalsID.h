#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolShowAnimalsID : public Protocoale
{
private:
	string ID_animal;
	//string msg;
public:
	ProtocolShowAnimalsID() {}
	string handleMessage(string msg);
};
