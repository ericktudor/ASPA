#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <WinSock2.h>


#include "TCPListener.h"

using namespace std;


void Listener_MessageReceived(TCPListener* listener, int client, string msg);


//void showSQLError(unsigned int handleType, const SQLHANDLE & handle)
//{
//    SQLWCHAR sqlState[256],
//        errorMsg[256];
//    SDWORD    nativeError = 0L;
//    SWORD    pcbErrorMsg = 0;
//    SQLSMALLINT  recordNumber = 1;
//    if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, sqlState, NULL, errorMsg, 1024, NULL))
//        wcout << "SQL driver message: " << errorMsg << "\nSQL state: " << sqlState << "." << endl;
//}

int main()
{ 

     TCPListener server("127.0.0.1", 54010, Listener_MessageReceived); // 127.0.0.1   172.16.7.23


     if (server.Init())
     {
         server.Run();
     }
}


void Listener_MessageReceived(TCPListener* listener, int client, string msg)
{
	listener->Send(client, msg);
}
