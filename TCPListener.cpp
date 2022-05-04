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
						cout << "Receptionat!" << endl;

						string recpt = string(buf, 0, bytesReceived);
						//cout << "Mesajul primit este : " << recpt << endl;


						// ZONA DECLARARI

						ProtocolLogClient log_client;
						ProtocolLogAdmin log_admin;
						ProtocolRegister register_client;
						ProtocolSearchAnimal search_animal;
						ProtocolFormAdoption form_adoption;
						ProtocolSendCampaign send_campaign;
						Client user_client;


						//conectare client

						if (recpt[0] == '1' && recpt[1] == '0')
						{
							cout << "Logare_client" << endl;
							Send(client, log_client.handleMessage(recpt));
						}

						cout << "\n\n";

						//conectare admin	//10
						
						if (recpt[0] == '3' && recpt[1] == '0')
						{
							cout << "Logare_admin" << endl;
							Send(client, log_admin.handleMessage(recpt));
						}
						cout << "\n\n";

						//register_client	//20
						
						if (recpt[0] == '2' && recpt[1] == '0')
						{
							cout << "Register_client" << endl;
							Send(client, register_client.handleMessage(recpt));

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

						//send_campaign

						if (recpt[0] == '1' && recpt[1] == '4')
						{
							cout << "Send_campaign" << endl;
							Send(client, send_campaign.handleMessage(recpt));
						}

						//request_form		//32

						if (recpt[0] == '3' && recpt[1] == '2')
						{
							cout << "Form_adoption" << endl;
							Send(client, "1/ID_request/Nume/Prenume/Telefon/Email/ID_user/1/1/0/0/1/0/");

						}


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