#include "ProtocolADRequests.h"

string ProtocolADRequests::handleMessage(string msg)
{
	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->ID_request = msg.substr(x + 1, y - x - 1);
	cout << this->ID_request << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->status = msg.substr(x + 1, y - x - 1);
	cout << this->status << endl;
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
        strcpy(newvar1, this->ID_request.c_str());
        char* newvar2 = new char[50];
        strcpy(newvar2, this->status.c_str());
        SQLCHAR newquery[100];


        sprintf((char*)newquery, "SELECT * from Requests");
        std::string str((const char*)newquery);
        std::wstring instr(str.begin(), str.end()); //str to wstr.
        int ok_ID_request;
        if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
        {
            cout << "Error querying SQL Server";
            cout << "\n";
        }
        else
        {
            SQLCHAR sqlVersion[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion;
            cout << "\nQuery Result:\n\n";
            
            while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
            {
                ok_ID_request = 0;

                SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                string str_ID((const char*)sqlVersion);    //convert sqlstring to string
                if (this->ID_request == str_ID)
                {
                    ok_ID_request = 1;
                    break;
                }
                SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);

                //SQLStatementHandle = NULL;
            }
        }
                if (ok_ID_request==1)
                {
                    cout << "A fost gasita cererea dorita";
                    //char* newvar3 = new char[50];
                    //strcpy(newvar3, str_ID.c_str());
                    SQLCHAR newquery1[100];


                    //sprintf((char*)newquery, "UPDATE Animals SET %s = '%s' where ID_animal = %s", newvar2, newvar3, newvar1);
                    sprintf((char*)newquery1, "UPDATE Requests SET Status = '%s' where ID_request = '%s'", newvar2, newvar1);
                    std::string str1((const char*)newquery1);
                    std::wstring instr1(str1.begin(), str1.end()); //str to wstr.

                    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr1.c_str(), SQL_NTS))
                    {
                        cout << "Error querying SQL Server";
                        cout << "\n";
                        this->msg = "*0*";
                        cout << "Nu s-a putut efectua update-ul!\n";
                    }
                    else
                    {
                        this->msg = "*1*";
                        cout << "UPDATE realizat cu succes!\n";
                    }

                    //break;
                }
                else
                {
                    cout << "Cerere inexistenta!";
                    this->msg = "*0*";
                }

                cout << "\n";
        
        
    } while (FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	LOG::getInstance().logADRequests();

	return this->msg;
}
