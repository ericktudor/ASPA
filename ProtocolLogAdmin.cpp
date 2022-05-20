#include "ProtocolLogAdmin.h"

string ProtocolLogAdmin::handleMessage(string msg)
{
	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->username = msg.substr(x + 1, y - x - 1);
	cout << this->username << endl;
	cout << x << " " << y << endl;

	x = y;
	y = msg.rfind("/");

	cout << x << " " << y << endl;

	this->password = msg.substr(x + 1, y - x - 1);
	cout << this->password << endl;

	if (this->username == "admin" && this->password == "admin")
	{
		cout << "Admin conectat cu succes!\n";
		this->msg = "*1*";
	}
	else
	{
		cout << "Admin neconectat!\n";
		this->msg = "*0*";
	}
		
	LOG::getInstance().logLogAdmin();

	return this->msg; 
}