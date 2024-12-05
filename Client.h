#pragma once

#include <iostream>
#include <string>
#include"Utilizator.h"

using namespace std;

class Client : public Utilizator
{
private:
	string nume;
	string prenume;
	string email;
	string telefon;

public:
	Client() {
	
		this->username = "test";
		this->password = "test";
	}
	Client(string username, string password)
	{
		this->username = username;
		this->password = password;
	}
	Client(string username, string password, string nume, string prenume, string email, string telefon)
	{
		this->username = username;
		this->password = password;
		this->nume = nume;
		this->prenume = prenume;
		this->email = email;
		this->telefon = telefon;
	}
	void setUsername(string username);
	void setPassword(string password);
	void setNume(string nume);
	void setPrenume(string prenume);
	void setEmail(string email);
	void setTelefon(string telefon);

	string getTelefon();

	~Client() {}
};

