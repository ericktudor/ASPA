#include "ProtocolFormAdoption.h"

string ProtocolFormAdoption::handleMessage(string msg)
{
	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->ID_user = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R1 = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R2 = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R3 = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R4 = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R5 = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R6 = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;


	//de adaugat in baza de date

	int ok = 1;

	//daca se adauga cu succes, ok=1;

	if (/*ok==1*/ok == 1)
	{
		cout << "Cererea a fost inregistrata cu succes!\n";
		this->msg = "*1*";
	}
	else
	{
		cout << "Cererea nu a fost inregistrata cu succes!\n";
		this->msg = "*0*";
	}

	return this->msg;
}