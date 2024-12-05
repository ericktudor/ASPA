#include "ProtocolLogClient.h"

string ProtocolLogClient::handleMessage(string msg)
{
    // 10/user/pass/

	int x = msg.find("/");			//retine pozitia la care gaseste delimitatorul
	int y = msg.find("/", x + 1);	//la fel, doar ca o sa caute dupa ce gaseste prima aparitie

	this->username = msg.substr(x + 1, y - x - 1);
	cout << this->username << endl;
	cout << x << " " << y << endl;

	x = y;
	y = msg.rfind("/");

	cout << x << " " << y << endl;

	this->password = msg.substr(x + 1, y - x - 1);
	cout << this->password << endl;
	int ok = 0;

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
        SQLCHAR newquery[100];


        sprintf((char*)newquery, "SELECT * from Clients");
        std::string str((const char*)newquery);
        std::wstring instr(str.begin(), str.end()); //str to wstr.

        if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
        {
                cout << "Error querying SQL Server";
                cout << "\n";
        }
        else {
            //declare output variable and pointer

            //clasa baza de date
            //metoda interogari
            SQLCHAR sqlVersion[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion;
            cout << "\nQuery Result:\n\n";
            while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) 
            {
                int ok_user = 0;
                int ok_pass = 0;
                //int j = 1;
                //while (j!=4)
                //{

                SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                string str_ID((const char*)sqlVersion);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                    string str_user((const char*)sqlVersion);    //convert sqlstring to string
                    if (this->username == str_user)
                    {
                        ok_user = 1;
                        //break;
                    }
                    SQLGetData(SQLStatementHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                    string str_pass((const char*)sqlVersion);    //convert sqlstring to string
                    if (this->password == str_pass)
                    {
                        ok_pass = 1;
                        //break;
                    }
                    if (ok_user == 1 && ok_pass == 1)
                    {
                        cout << "Client conectat cu succes!";
                        this->msg = "*1*";
                        /*this->msg.append(str_ID);
                        this->msg.append("/");*/
                        break;
                    }
                    else
                    {
                        //cout << "Client neconectat!";
                        this->msg = "*0*";
                    }
                    //j++;
                //}
                cout << "\n";
            }
        }
    } while (FALSE);

    SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	LOG::getInstance().logLogClient();

	return this->msg;
}