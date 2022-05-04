#pragma once

#include <iostream>
#include <string>
#include <WS2tcpip.h>				// header file for winsock functions
#include "DB.h"
#include "ProtocolLogClient.h"
#include "ProtocolLogAdmin.h"
#include "ProtocolRegister.h"
#include "ProtocolSearchAnimal.h"
#include "ProtocolFormAdoption.h"
#include "ProtocolSendCampaign.h"

#pragma comment(lib, "ws2_32.lib")	// winsock library file

#define MAX_BUFFER_SIZE (49152)

using namespace std;

// forward declaration of claass
class TCPListener;

// TODO: callback to data received
typedef void (*MessageReceivedHandler)(TCPListener* listener, int socketID, string msg);

class TCPListener
{
public:

	TCPListener(string IPAddress, int port, MessageReceivedHandler handler);

	~TCPListener();

	// Send a message to the specified client
	void Send(int ClientSocket, string msg);

	// Initialize winsock
	bool Init();

	// The main  processing loop
	void Run();

	// Cleanup after using the service
	void Cleanup();

private:
	// Create a socket
	SOCKET CreateSocket();

	// Wait for a connection
	SOCKET WaitForConnection(SOCKET listening);

	string IPAddress;
	int port;
	MessageReceivedHandler MessageReceived;
};
