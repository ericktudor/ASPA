#define _CRT_SECURE_NO_WARNINGS
#include "TCPListener.h"
#include "Admin.h"
#include "Client.h"
#include <vector>


TCPListener::TCPListener(string IPAddress, int port, MessageReceivedHandler handler)
	:IPAddress(IPAddress), port(port), MessageReceived(handler)
{

}

TCPListener::~TCPListener()
{
	Cleanup();
}

// Send a message to the specified client
void TCPListener::Send(int ClientSocket, string msg)
{
	send(ClientSocket, msg.c_str(), msg.size() + 1, 0);
}


// Initialize winsock
bool TCPListener::Init()
{
	WSAData data;
	WORD ver = MAKEWORD(2, 2);

	int WSInit = WSAStartup(ver, &data);

	cout << "server is running" << endl;

	return WSInit == 0;
}
//Database db;
//db.open()
// The main  processing loop
void TCPListener::Run()
{
	char buf[MAX_BUFFER_SIZE];

	//DataBase db;

	//db.open();
	//DataBase.h -> DataBase db(membru privat);db.connetDatabase()
	//SQLHANDLE SQLEnvHandle = NULL;
	//SQLHANDLE SQLConnectionHandle = NULL;
	//SQLHANDLE SQLStatementHandle = NULL;
	//SQLRETURN retCode = 0;

	//do {
	//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
	//		break;

	//	if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
	//		break;

	//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
	//		break;

	//	if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
	//		break;

	//	SQLCHAR retConString[1024];
	//	switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server}; SERVER=localhost, 1434; DATABASE=ASPAserver; Trusted=true;", SQL_NTS, (SQLWCHAR*)retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
	//	case SQL_SUCCESS:
	//		std::cout << "Baza de date ASPAserver conectata cu succes!" << std::endl;
	//		break;
	//	case SQL_SUCCESS_WITH_INFO:
	//		std::cout << "Baza de date ASPAserver conectata cu succes!" << std::endl;
	//		break;
	//	case SQL_NO_DATA_FOUND:
	//		//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
	//		retCode = -1;
	//		break;
	//	case SQL_INVALID_HANDLE:
	//		//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
	//		retCode = -1;
	//		break;
	//	case SQL_ERROR:
	//		cout << "Here" << endl; // it is failing here <<<<<<
	//		//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
	//		retCode = -1;
	//		break;
	//	default:
	//		break;
	//	}

	//	if (retCode == -1)
	//		break;

	//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
	//		break;
	//} while (FALSE);

	//string age = "10";
	//string str1="UPDATE Animals SET Age = '"+age+"' WHERE ID_animal=4";

	////INSERT INTO Animals(Age, Sex, Location, Size, Species) VALUES('5', 'Mascul', 'Bragadiru', 'Mica', 'Caine')

	////UPDATE Animals SET Age = '2' WHERE ID_animal=5

	////const char[100]="UPDATE Animals SET "+"Age "+ "'2' WHERE ID_animal=5";

	//if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)L" ", SQL_NTS)) {
	//	cout << "Error querying SQL Server";
	//	cout << "\n";

	//}
	//else {
	//	//declare output variable and pointer

	//	//clasa baza de date
	//	//metoda interogari
	//	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	//	SQLINTEGER ptrSqlVersion;
	//	cout << "\nQuery Result:\n\n";
	//	while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
	//		//for() de parcurs toate coloanele din baza de date
	//		//i coloane

	//		for (int i = 1; i <= 7; i++)
	//		{
	//			SQLGetData(SQLStatementHandle, i, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
	//			//display query result

	//			cout << sqlVersion;
	//			cout << "\n";
	//		}
	//		cout << "\n";
	//		//SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
	//		////display query result
	//		//cout << "\nQuery Result:\n\n";
	//		//cout << sqlVersion << endl;
	//		//cout << "\n";
	//	}
	//}

	while (true)
	{
		//create a listening socket
		SOCKET listening = CreateSocket();
		if (listening == INVALID_SOCKET)
		{
			break;
		}

		SOCKET client = WaitForConnection(listening);

		vector<Client> vect_clienti;

		if (client != INVALID_SOCKET)
		{
			cout << "Conected..." << endl;
			closesocket(listening);

			int bytesReceived = 0;
			/*DB db;
			db.initialization();*/

			do
			{
				ZeroMemory(buf, MAX_BUFFER_SIZE);
				bytesReceived = recv(client, buf, MAX_BUFFER_SIZE, 0);
				if (bytesReceived > 0)
				{
					if (MessageReceived != NULL)
					{
						MessageReceived(this, client, string(buf, 0, bytesReceived));
						cout << string(buf, 0, bytesReceived);
						cout << "\nReceptionat!" << endl;

						string recpt = string(buf, 0, bytesReceived);
						//cout << "Mesajul primit este : " << recpt << endl;


						// ZONA DECLARARI

						ProtocolLogClient log_client;			//10
						ProtocolSearchAnimal search_animal;		//11
						ProtocolFormAdoption form_adoption;		//12
						ProtocolReportEvent report_event;		//13
						ProtocolSendCampaign send_campaign;		//14
						ProtocolRegister register_client;		//20
						ProtocolLogAdmin log_admin;				//30
						ProtocolLogFile log_file;				//31
						ProtocolShowRequests show_requests;		//32
						ProtocolADRequests AD_requests;			//33
						ProtocolShowAnimals show_animals;		//34
						//ProtocolShowAnimalsID show_animals_id;	//35
						ProtocolChangeParameters change_param;	//36
						ProtocolAddAnimal add_animal;			//37
						ProtocolDeleteAnimal delete_animal;		//38
						ProtocolAddCampaign add_campaign;		//39
						ProtocolDeleteCampaign delete_campaign;	//40

						LOG& logare = LOG::getInstance();
						

						Client user_client;


						//conectare client	//10

						if (recpt[0] == '1' && recpt[1] == '0')
						{
							cout << "Logare_client" << endl;
							Send(client, log_client.handleMessage(recpt));
						}

						cout << "\n";

						//search_animal		//11

						if (recpt[0] == '1' && recpt[1] == '1')
						{
							cout << "Search_animal" << endl;
							Send(client, search_animal.handleMessage(recpt));
							
						}

						cout << "\n";

						//form_adoption		//12

						if (recpt[0] == '1' && recpt[1] == '2')
						{
							cout << "Form_adoption" << endl;
							Send(client, form_adoption.handleMessage(recpt));

						}

						cout << "\n";

						//report_event		//13

						if (recpt[0] == '1' && recpt[1] == '3')
						{
							cout << "Report_event" << endl;
							Send(client, report_event.handleMessage(recpt));

						}

						cout << "\n";

						//send_campaign		//14

						if (recpt[0] == '1' && recpt[1] == '4')
						{
							cout << "Send_campaign" << endl;
							Send(client, send_campaign.handleMessage(recpt));
						}

						cout << "\n";

						//register_client	//20

						if (recpt[0] == '2' && recpt[1] == '0')
						{
							cout << "Register_client" << endl;
							Send(client, register_client.handleMessage(recpt));

						}

						cout << "\n";

						//conectare admin	//30

						if (recpt[0] == '3' && recpt[1] == '0')
						{
							cout << "Logare_admin" << endl;
							Send(client, log_admin.handleMessage(recpt));
						}
						cout << "\n";

						//log_file			//31

						if (recpt[0] == '3' && recpt[1] == '1')
						{
							cout << "Log_file" << endl;
							Send(client, log_file.handleMessage(recpt));
						}
						cout << "\n";
						

						//SHOW_request_form		//32

						if (recpt[0] == '3' && recpt[1] == '2')
						{
							cout << "Show_request_form" << endl;
							Send(client, show_requests.handleMessage(recpt));

						}

						cout << "\n";

						//AD_request		//33

						if (recpt[0] == '3' && recpt[1] == '3')
						{
							cout << "AD_request" << endl;
							Send(client, AD_requests.handleMessage(recpt));
						}
						cout << "\n";

						//show_animals		//34

						if (recpt[0] == '3' && recpt[1] == '4')
						{
							cout << "Show_animals" << endl;
							Send(client, show_animals.handleMessage(recpt));
						}
						cout << "\n";

						

						//change_param		//36

						if (recpt[0] == '3' && recpt[1] == '6')
						{
							cout << "change_param" << endl;
							Send(client, change_param.handleMessage(recpt));
						}
						cout << "\n";

						//add_animal		//37

						if (recpt[0] == '3' && recpt[1] == '7')
						{
							cout << "add_animal" << endl;
							Send(client, add_animal.handleMessage(recpt));
						}
						cout << "\n";

						//delete_animal		//38

						if (recpt[0] == '3' && recpt[1] == '8')
						{
							cout << "delete_animal" << endl;
							Send(client, delete_animal.handleMessage(recpt));
						}
						cout << "\n";

						//add_campaign		//39

						if (recpt[0] == '3' && recpt[1] == '9')
						{
							cout << "add_campaign" << endl;
							Send(client, add_campaign.handleMessage(recpt));
						}
						cout << "\n";

						//delete_campaign	//40

						if (recpt[0] == '4' && recpt[1] == '0')
						{
							cout << "delete_campaign" << endl;
							Send(client, delete_campaign.handleMessage(recpt));
						}
						cout << "\n";
					}
				}

			} while (bytesReceived > 0);

			closesocket(client);

			/*SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
			SQLDisconnect(SQLConnectionHandle);
			SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
			SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);*/

			//wait for a connection
			//loop receive/send
		}

	}
}

void TCPListener::Cleanup()
{
	WSACleanup();
	
}

// Create a socket
SOCKET TCPListener::CreateSocket()
{
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cout << "Can't create a socket! Quitting!" << endl;
		return 0;
	}

	if (listening != INVALID_SOCKET)
	{
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);			// htons host to network short
		inet_pton(AF_INET, IPAddress.c_str(), &hint.sin_addr);		// also hint.sin_addr.s_un.s_addr = INADDR_ANY;

		int bindOK = bind(listening, (sockaddr*)&hint, sizeof(hint));
		if (bindOK != SOCKET_ERROR)
		{
			int listenOK = listen(listening, SOMAXCONN);
			if (listenOK == SOCKET_ERROR)
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	return listening;
}

// Wait for a connection
SOCKET TCPListener::WaitForConnection(SOCKET listening)
{
	SOCKET client = accept(listening, NULL, NULL);
	return client;
}