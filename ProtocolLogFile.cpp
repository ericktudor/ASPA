#include "ProtocolLogFile.h"

string ProtocolLogFile::handleMessage(string msg)
{
	
	ifstream fin("Log.txt");
	//FILE* fin;
	//fin = fopen("Log.txt", "r");
	//fin.open("Log.txt");

	fin.open("Log.txt");
	//fin.seekg(0, ios::beg);

	//fin.seekg(0, std::ios_base::beg);
	//rewind(fin);

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