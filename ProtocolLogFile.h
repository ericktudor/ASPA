#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>
#include <fstream>

using namespace std;

class ProtocolLogFile : public Protocoale
{
private:
	ifstream fin;
	string filename;
	//string msg;
public:
	ProtocolLogFile() {
		this->msg = " /";
	}
	string handleMessage(string msg);
};

