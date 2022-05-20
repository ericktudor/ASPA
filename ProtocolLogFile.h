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
public:
	ProtocolLogFile() {	}
	string handleMessage(string msg);
};

