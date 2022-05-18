#pragma once

#include <iostream>
#include <string>
#include "Protocoale.h"
#include "Client.h"
#include <vector>

using namespace std;

class ProtocolShowRequests : public Protocoale
{
private:
	string ID_request;
	string name;
	string surname;
	string tel;
	string mail;
	string ID_user;
	string ID_animal;
	string R1;
	string R2;
	string R3;
	string R4;
	string R5;
	string R6;
	//string msg;
public:
	ProtocolShowRequests() {}
	string handleMessage(string msg);
};

