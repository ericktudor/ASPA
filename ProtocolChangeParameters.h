#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

// 36/ID_animal/param/value

class ProtocolChangeParameters : public Protocoale
{
private:
	string ID_animal;
	string param;
	string value;
	//string msg;
public:
	ProtocolChangeParameters() {}
	string handleMessage(string msg);

};

