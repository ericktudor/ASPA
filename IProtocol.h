#pragma once

#include <iostream>
#include <string>


using namespace std;

class IProtocol
{
public:
	virtual string handleMessage(string msg) = 0;
};

