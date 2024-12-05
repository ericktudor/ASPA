#include "ProtocolShowRequests.h"


// 1/ID_request/Nume/Prenume/Telefon/Email/ID_user/Id_animal/1/1/0/0/1/0/

string ProtocolShowRequests::handleMessage(string msg)
{
	/*int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->ID_request = msg.substr(x + 1, y - x - 1);
	cout << this->ID_request << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

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

	this->tel = msg.substr(x + 1, y - x - 1);
	cout << this->tel << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->mail = msg.substr(x + 1, y - x - 1);
	cout << this->mail << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->ID_user = msg.substr(x + 1, y - x - 1);
	cout << this->ID_user << endl;
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
	cout << x << " " << y << endl;*/

	//de cautat in baza de date toate cererile

	//ce primesc, split uiesc in mesaje de genul

	//mesaje de genul ok!!!


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

        /*char* newvar1 = new char[50];
        strcpy(newvar1, this->username.c_str());
        char* newvar2 = new char[50];
        strcpy(newvar2, this->password.c_str());*/
        SQLCHAR newquery[100];

        // SELECT COUNT(*) FROM Requests
        sprintf((char*)newquery, "SELECT * FROM Requests");
        std::string str((const char*)newquery);
        std::wstring instr(str.begin(), str.end()); //str to wstr.

        if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
        {
                cout << "Error querying SQL Server";
                cout << "\n";
        }
        else {

            /*SQLCHAR sqlVersion[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion;
            cout << "\nQuery Result:\n\n";*/

            //while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) 
            //{
            //SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
            //string aux((const char*)sqlVersion);
            //int nr_inreg = stoi(aux);
            //SQLCHAR newquery1[100];

            //sprintf((char*)newquery1, "SELECT * FROM Requests");
            //std::string str1((const char*)newquery1);
            //std::wstring instr1(str1.begin(), str1.end()); //str to wstr.

            /*if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr1.c_str(), SQL_NTS))
            {
                cout << "Error querying SQL Server";
                cout << "\n";
            }
            else
            {*/
                SQLCHAR sqlVersion1[SQL_RESULT_LEN];    //ID_request
                SQLINTEGER ptrSqlVersion1;
                SQLCHAR sqlVersion2[SQL_RESULT_LEN];    //Status
                SQLINTEGER ptrSqlVersion2;
                SQLCHAR sqlVersion3[SQL_RESULT_LEN];    //Nume
                SQLINTEGER ptrSqlVersion3;
                SQLCHAR sqlVersion4[SQL_RESULT_LEN];    //Prenume
                SQLINTEGER ptrSqlVersion4;
                SQLCHAR sqlVersion5[SQL_RESULT_LEN];    //Telefon
                SQLINTEGER ptrSqlVersion5;
                SQLCHAR sqlVersion6[SQL_RESULT_LEN];    //Email
                SQLINTEGER ptrSqlVersion6;
                SQLCHAR sqlVersion7[SQL_RESULT_LEN];    //ID_user
                SQLINTEGER ptrSqlVersion7;
                SQLCHAR sqlVersion8[SQL_RESULT_LEN];    //ID_animal
                SQLINTEGER ptrSqlVersion8;
                SQLCHAR sqlVersion9[SQL_RESULT_LEN];    //R1
                SQLINTEGER ptrSqlVersion9;
                SQLCHAR sqlVersion10[SQL_RESULT_LEN];    //R2
                SQLINTEGER ptrSqlVersion10;
                SQLCHAR sqlVersion11[SQL_RESULT_LEN];    //R3
                SQLINTEGER ptrSqlVersion11;
                SQLCHAR sqlVersion12[SQL_RESULT_LEN];    //R4
                SQLINTEGER ptrSqlVersion12;
                SQLCHAR sqlVersion13[SQL_RESULT_LEN];    //R5
                SQLINTEGER ptrSqlVersion13;
                SQLCHAR sqlVersion14[SQL_RESULT_LEN];    //R6
                SQLINTEGER ptrSqlVersion14;
                cout << "\nQuery Result:\n\n";
                int nr = 0;
                while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
                {
                    SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion1, SQL_RESULT_LEN, &ptrSqlVersion1);
                    string str_ID_request((const char*)sqlVersion1);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion2, SQL_RESULT_LEN, &ptrSqlVersion2);
                    string str_status((const char*)sqlVersion2);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 3, SQL_CHAR, sqlVersion3, SQL_RESULT_LEN, &ptrSqlVersion3);
                    string str_nume((const char*)sqlVersion3);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 4, SQL_CHAR, sqlVersion4, SQL_RESULT_LEN, &ptrSqlVersion4);
                    string str_prenume((const char*)sqlVersion4);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 5, SQL_CHAR, sqlVersion5, SQL_RESULT_LEN, &ptrSqlVersion5);
                    string str_telefon((const char*)sqlVersion5);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 6, SQL_CHAR, sqlVersion6, SQL_RESULT_LEN, &ptrSqlVersion6);
                    string str_email((const char*)sqlVersion6);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 7, SQL_CHAR, sqlVersion7, SQL_RESULT_LEN, &ptrSqlVersion7);
                    string str_ID_user((const char*)sqlVersion7);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 8, SQL_CHAR, sqlVersion8, SQL_RESULT_LEN, &ptrSqlVersion8);
                    string str_ID_animal((const char*)sqlVersion8);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 9, SQL_CHAR, sqlVersion9, SQL_RESULT_LEN, &ptrSqlVersion9);
                    string str_R1((const char*)sqlVersion9);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 10, SQL_CHAR, sqlVersion10, SQL_RESULT_LEN, &ptrSqlVersion10);
                    string str_R2((const char*)sqlVersion10);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 11, SQL_CHAR, sqlVersion11, SQL_RESULT_LEN, &ptrSqlVersion11);
                    string str_R3((const char*)sqlVersion11);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 12, SQL_CHAR, sqlVersion12, SQL_RESULT_LEN, &ptrSqlVersion12);
                    string str_R4((const char*)sqlVersion12);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 13, SQL_CHAR, sqlVersion13, SQL_RESULT_LEN, &ptrSqlVersion13);
                    string str_R5((const char*)sqlVersion13);    //convert sqlstring to string

                    SQLGetData(SQLStatementHandle, 14, SQL_CHAR, sqlVersion14, SQL_RESULT_LEN, &ptrSqlVersion14);
                    string str_R6((const char*)sqlVersion14);    //convert sqlstring to string


                    if (str_status == "0")
                    {
                        //"1/ID_request/status/Nume/Prenume/Telefon/Email/ID_user/Id_animal/1/1/0/0/1/0/"

                        nr++;
                        cout << "A fost gasita o cerere neprocesata!";
                        this->msg.append("/");
                        this->msg.append(str_ID_request);
                        this->msg.append("/");
                        this->msg.append(str_nume);
                        this->msg.append("/");
                        this->msg.append(str_prenume);
                        this->msg.append("/");
                        this->msg.append(str_telefon);
                        this->msg.append("/");
                        this->msg.append(str_email);
                        this->msg.append("/");
                        this->msg.append(str_ID_user);
                        this->msg.append("/");
                        this->msg.append(str_ID_animal);
                        this->msg.append("/");
                        this->msg.append(str_R1);
                        this->msg.append("/");
                        this->msg.append(str_R2);
                        this->msg.append("/");
                        this->msg.append(str_R3);
                        this->msg.append("/");
                        this->msg.append(str_R4);
                        this->msg.append("/");
                        this->msg.append(str_R5);
                        this->msg.append("/");
                        this->msg.append(str_R6);
                        
                    }

                    cout << "\n";
                }
                string nr_animale;
                nr_animale = to_string(nr);
                this->msg = nr_animale + this->msg;
                this->msg.append("/");
            //}
            
        }
        
    } while (FALSE);

    SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

    if (this->msg == "")
    {
        cout << "Nu a fost gasit nicio cerere neprocesata!";
        this->msg = "*0*";
    }

	//this->msg = "1/ID_request/status/Nume/Prenume/Telefon/Email/ID_user/Id_animal/1/1/0/0/1/0/";

	LOG::getInstance().logShowRequests();

	return this->msg;
}