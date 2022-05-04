#include "Client.h"

void Client::setUsername(string username)
{
	this->username = username;
}

void Client::setPassword(string password)
{
	this->password = password;
}

void Client::setNume(string nume)
{
	this->nume = nume;
}

void Client::setPrenume(string prenume)
{
	this->prenume = prenume;
}

void Client::setEmail(string email)
{
	this->email = email;
}

void Client::setTelefon(string telefon)
{
	this->telefon = telefon;
}

string Client::getTelefon()
{
	return this->telefon;
}
