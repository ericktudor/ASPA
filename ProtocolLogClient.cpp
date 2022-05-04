#include "ProtocolLogClient.h"

string ProtocolLogClient::handleMessage(string msg)
{
	string user;
	string pass;

	int x = msg.find("/");			//retine pozitia la care gaseste delimitatorul
	int y = msg.find("/", x + 1);	//la fel, doar ca o sa caute dupa ce gaseste prima aparitie

	user = msg.substr(x + 1, y - x - 1);
	cout << user << endl;
	cout << x << " " << y << endl;
	x = y;
	y = msg.rfind("/");
	cout << x << " " << y << endl;
	pass = msg.substr(x + 1, y - x - 1);
	cout << pass << endl;
	int ok = 0;



	if ((user == "test" && pass == "test") || (user == "11" && pass == "11"))
	{
		cout << "Client conectat cu succes!";
		this->msg = "*1*";
	}
	else
	{
		cout << "Client neconectat!";
		this->msg = "*0*";
	}
	return this->msg;
}