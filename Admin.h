#pragma once

#include <iostream>
#include <string>
#include"Utilizator.h"

using namespace std;


class Admin : public Utilizator
{
public:
	Admin() {
		this->username = "admin";
		this->password = "admin";
	}
	Admin(string username,string password)
	{
		this->username = username;
		this->password = password;
	}

	~Admin() {}
};

