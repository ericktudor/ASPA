#include "ProtocolLogAdmin.h"

string ProtocolLogAdmin::handleMessage(string msg)
{
	string user;
	string pass;

	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	user = msg.substr(x + 1, y - x - 1);
	cout << user << endl;
	cout << x << " " << y << endl;

	x = y;
	y = msg.rfind("/");

	cout << x << " " << y << endl;
	pass = msg.substr(x + 1, y - x - 1);
	cout << pass << endl;

	if (user == "admin" && pass == "admin")
	{
		cout << "Admin conectat cu succes!\n";
		this->msg = "*1*";
	}
	else
	{
		cout << "Admin neconectat!\n";
		this->msg = "*0*";
	}
		
	return this->msg; 
}