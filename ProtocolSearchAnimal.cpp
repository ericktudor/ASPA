#include "ProtocolSearchAnimal.h"

string ProtocolSearchAnimal::handleMessage(string msg)
{
	// 11/age/sex/location/size/species/

	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->age = msg.substr(x + 1, y - x - 1);
	cout << this->age << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->sex = msg.substr(x + 1, y - x - 1);
	cout << this->sex << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->location = msg.substr(x + 1, y - x - 1);
	cout << this->location << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->size = msg.substr(x + 1, y - x - 1);
	cout << this->size << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->species = msg.substr(x + 1, y - x - 1);
	cout << this->species << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);


	//select ul din baza de date

	//de calculat numarul de inregistrari gasite

	//de creat mesajul inapoi la client sub forma
	//nr_animale / ID_animal / age / sex / location / size / species /
	// ex: 2/1/<2/Mascul/Palady/Mica/Caine/2/<1Mascul/Palady/Medie/Pisica/

	if (this->sex=="Mascul")
	{
		cout << "A fost gasit un animal cu caracteristicile dorite!";
		this->msg = "2/1/2/Mascul/Palady/Mica/Caine/2/1/Mascul/Palady/Medie/Pisica/";
	}
	else
	{
		cout << "Nu a fost gasit un animal cu caracteristicile dorite!";
		this->msg = "*0*";
	}

	//La final eu am de bagat tot mesajul in this->msg!!!
	return this->msg;
}


//trebuie de trimis numarul de animale gasite
//  nr_animale/ID_animal/age/sex/location/size/species/