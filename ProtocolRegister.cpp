#include "ProtocolRegister.h"

string ProtocolRegister::handleMessage(string msg)
{
	Client user_client;
	vector<Client> vect_clienti;
	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->name = msg.substr(x + 1, y - x - 1);
	//cout << nume << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->surname = msg.substr(x + 1, y - x - 1);
	//cout << prenume << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->username = msg.substr(x + 1, y - x - 1);
	//cout << user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->password = msg.substr(x + 1, y - x - 1);
	//cout << pass << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->mail = msg.substr(x + 1, y - x - 1);
	//cout << mail << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->tel = msg.substr(x + 1, y - x - 1);
	//cout << telefon << endl;
	cout << x << " " << y << endl;

	//cout << nume << " " << prenume << " " << user << " " << pass << " " << email << " " << telefon << endl;

	user_client.setUsername(this->username);
	user_client.setPassword(this->password);
	user_client.setNume(this->name);
	user_client.setPrenume(this->surname);
	user_client.setEmail(this->mail);
	user_client.setTelefon(this->tel);

	Client z(this->username, this->password, this->name, this->surname, this->mail, this->tel);
	vect_clienti.push_back(z);
	vect_clienti.push_back(user_client);

	if (user_client.getTelefon() == "123")
	{
		cout << "Inregistrarea s-a realizat cu succes!";
		this->msg = "*1*";
	}
	else
	{
		cout << "Inregistrarea nu s-a realizat cu succes!";
		this->msg = "*0*";
	}
	return this->msg;
}
