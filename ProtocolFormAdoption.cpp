#include "ProtocolFormAdoption.h"

string ProtocolFormAdoption::handleMessage(string msg)
{
	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->ID_user = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
	cout << x << " " << y << endl;

	this->username = msg.substr(x + 1, y - x - 1);
	cout << this->username << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R1 = msg.substr(x + 1, y - x - 1);
	cout << this->R1 << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R2 = msg.substr(x + 1, y - x - 1);
	cout << this->R2 << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R3 = msg.substr(x + 1, y - x - 1);
	cout << this->R3 << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R4 = msg.substr(x + 1, y - x - 1);
	cout << this->R4 << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R5 = msg.substr(x + 1, y - x - 1);
	cout << this->R5 << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->R6 = msg.substr(x + 1, y - x - 1);
	cout << this->R6 << endl;
	cout << x << " " << y << endl;


	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;

	SQLHANDLE SQLEnvHandle1 = NULL;
	SQLHANDLE SQLConnectionHandle1 = NULL;
	SQLHANDLE SQLStatementHandle1 = NULL;
	SQLRETURN retCode1 = 0;

	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			break;

		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			break;

		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			break;

		SQLCHAR retConString[1024];
		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server}; SERVER=localhost, 1434; DATABASE=ASPAserver; Trusted=true;", SQL_NTS, (SQLWCHAR*)retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
		{
		case SQL_SUCCESS:
			std::cout << "Baza de date ASPAserver conectata cu succes!" << std::endl;
			break;
		case SQL_SUCCESS_WITH_INFO:
			std::cout << "Baza de date ASPAserver conectata cu succes!" << std::endl;
			break;
		case SQL_NO_DATA_FOUND:
			//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			cout << "Here" << endl; // it is failing here <<<<<<
			//showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			break;


		char* newvar1 = new char[50];
		strcpy(newvar1, this->ID_user.c_str());
		char* newvar2 = new char[50];
		strcpy(newvar2, this->R1.c_str());
		char* newvar3 = new char[50];
		strcpy(newvar3, this->R2.c_str());
		char* newvar4 = new char[50];
		strcpy(newvar4, this->R3.c_str());
		char* newvar5 = new char[50];
		strcpy(newvar5, this->R4.c_str());
		char* newvar6 = new char[50];
		strcpy(newvar6, this->R5.c_str());
		char* newvar7 = new char[50];
		strcpy(newvar7, this->R6.c_str());
		char* newvar8 = new char[50];

		SQLCHAR newquery0[1000];

		string ID_BUN;
		
		sprintf((char*)newquery0, "SELECT * from Clients");
		string str0((const char*)newquery0);
		wstring instructiune(str0.begin(), str0.end()); //str to wstr.
		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instructiune.c_str(), SQL_NTS))
		{
			cout << "Error querying SQL Server";
			cout << "\n";
		}
		else
		{
			SQLCHAR sqlVersion[SQL_RESULT_LEN];
			SQLINTEGER ptrSqlVersion;
			SQLCHAR sqlVersion1[SQL_RESULT_LEN];
			SQLINTEGER ptrSqlVersion1;
			cout << "\nQuery Result:\n\n";
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
				string str_ID((const char*)sqlVersion);    //convert sqlstring to string

				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion1, SQL_RESULT_LEN, &ptrSqlVersion1);
				string str_username((const char*)sqlVersion1);    //convert sqlstring to string

				if (this->username == str_username)
				{
					ID_BUN = str_ID;
					strcpy(newvar8, str_ID.c_str());
					break;
				}
				
				//strcpy(newvar8, str_ID.c_str());
			}
		}

		SQLCHAR newquery[1000];

		sprintf((char*)newquery, "INSERT INTO Form(ID_user, R1, R2, R3, R4, R5, R6) VALUES('%s','%s','%s','%s','%s','%s','%s')", newvar8, newvar2, newvar3, newvar4, newvar5, newvar6, newvar7);
		string str((const char*)newquery);
		wstring instr(str.begin(), str.end()); //str to wstr.

		int string1 = SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS);
		cout << "S-a afisat string1\n";
		cout << string1;

		if (SQL_SUCCESS != string1)//SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
		{
			cout << "Error querying SQL Server";
			cout << "\n";
			cout << "Cererea nu a fost inregistrata cu succes!\n";
			this->msg = "*0*";
		}
		else
		{
			//int string1 = SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS);
			//cout << string1;
			cout << "Cererea a fost inregistrata cu succes!\n";
			this->msg = "*1*";
		}
		//string ID_BUN;
		//
		//sprintf((char*)newquery0, "SELECT * from Clients");
		//string str((const char*)newquery0);
		//wstring instructiune(str.begin(), str.end()); //str to wstr.
		//if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instructiune.c_str(), SQL_NTS))
		//{
		//	cout << "Error querying SQL Server";
		//	cout << "\n";
		//}
		//else
		//{
		//	//SQLCHAR sqlVersion[SQL_RESULT_LEN];
		//	//SQLINTEGER ptrSqlVersion;
		//	//SQLCHAR sqlVersion1[SQL_RESULT_LEN];
		//	//SQLINTEGER ptrSqlVersion1;
		//	//cout << "\nQuery Result:\n\n";
		//	//while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
		//	//{
		//	//	SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		//	//	string str_ID((const char*)sqlVersion);    //convert sqlstring to string

		//	//	SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion1, SQL_RESULT_LEN, &ptrSqlVersion1);
		//	//	string str_username((const char*)sqlVersion1);    //convert sqlstring to string

		//	//	if (this->username == str_username)
		//	//	{
		//	//		ID_BUN = str_ID;
		//	//		break;
		//	//	}
		//	//}
		//	//SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
		//	//SQLDisconnect(SQLConnectionHandle);
		//	//SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
		//	//SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

		//	SQLCHAR newquery[1000];

		//	string id1 = string(ID_BUN);
		//	char* newvar8 = new char[50];
		//	strcpy(newvar8, id1.c_str());
		//	//INSERT INTO Form(ID_user, R1, R2, R3, R4, R5, R6) VALUES(%s, '%s', '%s', '%s', '%s', '%s', '%s')
		//	sprintf((char*)newquery, "INSERT INTO Form(ID_user, R1, R2, R3, R4, R5, R6) VALUES('%s','%s','%s','%s','%s','%s','%s')", newvar8, newvar2, newvar3, newvar4, newvar5, newvar6, newvar7);
		//	string str0((const char*)newquery);
		//	wstring instr(str0.begin(), str0.end()); //str to wstr.

		//}
		//SQLCHAR newquery[1000];

		//string id1 = string(ID_BUN);
		//char* newvar8 = new char[50];
		//strcpy(newvar8, id1.c_str());
		////INSERT INTO Form(ID_user, R1, R2, R3, R4, R5, R6) VALUES(%s, '%s', '%s', '%s', '%s', '%s', '%s')
		//sprintf((char*)newquery, "INSERT INTO Form(ID_user, R1, R2, R3, R4, R5, R6) VALUES('%s','%s','%s','%s','%s','%s','%s')", newvar8 , newvar2, newvar3, newvar4, newvar5, newvar6, newvar7);
		//string str0((const char*)newquery);
		//wstring instr(str0.begin(), str0.end()); //str to wstr.

		
		

	} while (FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	/*SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle1);
	SQLDisconnect(SQLConnectionHandle1);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle1);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle1);*/

	LOG::getInstance().logFormAdoption();

	return this->msg;
}