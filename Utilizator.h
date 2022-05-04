#pragma once
#include <iostream>
#include <string>

using namespace std;


class Utilizator
{
protected:
	string username;
	string password;

public:
	Utilizator() {}
	Utilizator(string username, string password)
	{
		this->username = username;
		this->password = password;
	}

	string getUsername();
	string getPassword();

	~Utilizator() {}

};

