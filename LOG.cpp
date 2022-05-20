#include "LOG.h"

LOG* LOG::instance = nullptr;

LOG::LOG()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	//ofstream f;
	//f.open("Log.txt");
	if (f.is_open())
	{
		cout << "Fisierul log a fost deschis cu succes!\n";
	}
	else
		cout << "Fisierul log nu a fost deschis cu succes!\n";
}

LOG& LOG::getInstance()
{
	if (!LOG::instance)
	{
		LOG::instance = new LOG();
	}
	return *LOG::instance;
}

void LOG::destroyInstance()
{
	if (LOG::instance)
	{
		delete LOG::instance;
		LOG::instance = nullptr;
	}
}

void LOG::logAddAnimal()
{	
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost adaugat un animal!\n";
	
}

void LOG::logAddCampaign()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost adaugata o campanie!\n";

}

void LOG::logADRequests()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "S-a procesat o cerere!\n";

}

void LOG::logChangeParameters()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "Au fost modificati parametrii unui animal!\n";
}

void LOG::logDeleteAnimal()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost eliminat un animal din baza de date!\n";
}

void LOG::logDeleteCampaign()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost eliminata o campanie din baza de date!\n";
}

void LOG::logFormAdoption()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost completat un formular de adoptie!\n";

}

void LOG::logLogAdmin()
{
	ofstream f;
	f.open("Log.txt",ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "S-a efectuat logarea unui utilizator cu drepturi de administrator!\n";

}

void LOG::logLogClient()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "S-a efectuat logarea unui utilizator cu drepturi de client!\n";
}

void LOG::logRegister()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "S-a efectuat o noua inregistrare in sistem!\n";
}

void LOG::logReportEvent()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost raportat un nou eveniment!\n";
}

void LOG::logSearchAnimal()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "Au fost cautate informatii despre un animal!\n";
}

void LOG::logSendCampaign()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "Au fost trimise toate campaniile disponibile in baza de date!\n";
}

void LOG::logShowAnimals()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost trimisa o lista cu toate animalele!\n";
}

void LOG::logShowRequests()
{
	ofstream f;
	f.open("Log.txt", ios_base::app);
	time_t now = time(nullptr);
	f << "[" << put_time(localtime(&now), "%T") << "] \t" << "A fost trimisa o lista cu toate cererile existente in baza de date!\n";
}
