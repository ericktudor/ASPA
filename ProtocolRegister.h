#pragma once

#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolRegister : public Protocoale
{
private:
	string name;
	string surname;
	string username;
	string password;
	string mail;
	string tel;
	string msg;
public:
	ProtocolRegister() {}
	string handleMessage(string msg);
};

