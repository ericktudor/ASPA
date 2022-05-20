#include "ProtocolLogFile.h"

string ProtocolLogFile::handleMessage(string msg)
{
	ifstream fin;
	fin.open("Log.txt");


	if (fin.is_open())
	{
		cout << "Fisierul log a fost deschis cu succes!\n";
		string line;
		while (getline(fin, line))
		{
			cout << line << '\n';
			this->msg = this->msg + line + "\n";
		}
		fin.close();
	}
	else
		cout << "Fisierul log nu a fost deschis cu succes!\n";

	
	//fin.close();
	return this->msg;
}