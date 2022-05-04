#pragma once
#include <iostream>
#include <string>
#include "IProtocol.h"

using namespace std;

class Protocoale : public IProtocol
{
protected:
	string msg;
public:
	void rcv_message(string message);
};

