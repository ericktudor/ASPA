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

// The main  processing loop
void TCPListener::Run()
{
	char buf[MAX_BUFFER_SIZE];

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
						ProtocolChangeParameters change_param;	//36
						ProtocolAddAnimal add_animal;			//37
						ProtocolDeleteAnimal delete_animal;		//38
						ProtocolAddCampaign add_campaign;		//39
						ProtocolDeleteCampaign delete_campaign;	//40

						LOG& logare = LOG::getInstance();

						//conectare client	//10

						if (recpt[0] == '1' && recpt[1] == '0')
						{
							cout << "Logare_client" << endl;
							Send(client, log_client.handleMessage(recpt));
						}

						//search_animal		//11

						if (recpt[0] == '1' && recpt[1] == '1')
						{
							cout << "Search_animal" << endl;
							Send(client, search_animal.handleMessage(recpt));
							
						}

						//form_adoption		//12

						if (recpt[0] == '1' && recpt[1] == '2')
						{
							cout << "Form_adoption" << endl;
							Send(client, form_adoption.handleMessage(recpt));

						}

						//report_event		//13

						if (recpt[0] == '1' && recpt[1] == '3')
						{
							cout << "Report_event" << endl;
							Send(client, report_event.handleMessage(recpt));

						}

						//send_campaign		//14

						if (recpt[0] == '1' && recpt[1] == '4')
						{
							cout << "Send_campaign" << endl;
							Send(client, send_campaign.handleMessage(recpt));
						}

						//register_client	//20

						if (recpt[0] == '2' && recpt[1] == '0')
						{
							cout << "Register_client" << endl;
							Send(client, register_client.handleMessage(recpt));

						}

						//conectare admin	//30

						if (recpt[0] == '3' && recpt[1] == '0')
						{
							cout << "Logare_admin" << endl;
							Send(client, log_admin.handleMessage(recpt));
						}

						//log_file			//31

						if (recpt[0] == '3' && recpt[1] == '1')
						{
							cout << "Log_file" << endl;
							Send(client, log_file.handleMessage(recpt));
						}

						//SHOW_request_form		//32

						if (recpt[0] == '3' && recpt[1] == '2')
						{
							cout << "Show_request_form" << endl;
							Send(client, show_requests.handleMessage(recpt));

						}

						//AD_request		//33

						if (recpt[0] == '3' && recpt[1] == '3')
						{
							cout << "AD_request" << endl;
							Send(client, AD_requests.handleMessage(recpt));
						}

						//show_animals		//34

						if (recpt[0] == '3' && recpt[1] == '4')
						{
							cout << "Show_animals" << endl;
							Send(client, show_animals.handleMessage(recpt));
						}						

						//change_param		//36

						if (recpt[0] == '3' && recpt[1] == '6')
						{
							cout << "change_param" << endl;
							Send(client, change_param.handleMessage(recpt));
						}

						//add_animal		//37

						if (recpt[0] == '3' && recpt[1] == '7')
						{
							cout << "add_animal" << endl;
							Send(client, add_animal.handleMessage(recpt));
						}

						//delete_animal		//38

						if (recpt[0] == '3' && recpt[1] == '8')
						{
							cout << "delete_animal" << endl;
							Send(client, delete_animal.handleMessage(recpt));
						}

						//add_campaign		//39

						if (recpt[0] == '3' && recpt[1] == '9')
						{
							cout << "add_campaign" << endl;
							Send(client, add_campaign.handleMessage(recpt));
						}

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