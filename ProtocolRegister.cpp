#include "ProtocolRegister.h"

string ProtocolRegister::handleMessage(string msg)
{
	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->name = msg.substr(x + 1, y - x - 1);
	cout << this->name << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->surname = msg.substr(x + 1, y - x - 1);
	cout << this->surname << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->username = msg.substr(x + 1, y - x - 1);
	cout << this->username << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->password = msg.substr(x + 1, y - x - 1);
	cout << this->password << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->mail = msg.substr(x + 1, y - x - 1);
	cout << this->mail << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->tel = msg.substr(x + 1, y - x - 1);
	cout << this->tel << endl;
	cout << x << " " << y << endl;


	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;

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
		strcpy(newvar1, this->username.c_str());
		char* newvar2 = new char[50];
		strcpy(newvar2, this->password.c_str());
		char* newvar3 = new char[50];
		strcpy(newvar3, this->name.c_str());
		char* newvar4 = new char[50];
		strcpy(newvar4, this->surname.c_str());
		char* newvar5 = new char[50];
		strcpy(newvar5, this->mail.c_str());
		char* newvar6 = new char[50];
		strcpy(newvar6, this->tel.c_str());
		SQLCHAR newquery[1000];


		sprintf((char*)newquery, "INSERT INTO Clients(Username, Password, Name, Surname, Email, Telephone) VALUES ('%s','%s','%s','%s','%s','%s')", newvar1, newvar2, newvar3, newvar4, newvar5, newvar6);
		string str((const char*)newquery);
		wstring instr(str.begin(), str.end()); //str to wstr.


		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
		{
			cout << "Error querying SQL Server";
			cout << "\n";
			this->msg = "*0*";
		}
		else
		{
			this->msg = "*1*";
			cout << "Inregistrare realizata cu succes!\n";
		}		
		
	} while (FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	LOG::getInstance().logRegister();

	return this->msg;
}