#include "ProtocolSendCampaign.h"

string ProtocolSendCampaign::handleMessage(string msg)
{
	//de extras datele din BD

	//aici mai trebuie doar de luat toate datele din BD
	//nu primesc nimic de la client

	//mesajul va avea forma :

	// nr_evenimente/data/denumire/locatie/

	// data va avea formatul DD.MM.YYYY

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

   
        SQLCHAR newquery[100];


        sprintf((char*)newquery, "SELECT * from Campaigns");
        std::string str((const char*)newquery);
        std::wstring instr(str.begin(), str.end()); //str to wstr.

        if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
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
            SQLCHAR sqlVersion2[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion2;
            SQLCHAR sqlVersion3[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion3;
            SQLCHAR sqlVersion4[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion4;
            SQLCHAR sqlVersion5[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion5;
            cout << "\nQuery Result:\n\n";
            int nr = 0;
            while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
            {
                SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                string str_ID_campaign((const char*)sqlVersion);    //convert sqlstring to string

                SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion1, SQL_RESULT_LEN, &ptrSqlVersion1);
                string str_day((const char*)sqlVersion1);    //convert sqlstring to string
                    

                SQLGetData(SQLStatementHandle, 3, SQL_CHAR, sqlVersion2, SQL_RESULT_LEN, &ptrSqlVersion2);
                string str_month((const char*)sqlVersion2);    //convert sqlstring to string
                    

                SQLGetData(SQLStatementHandle, 4, SQL_CHAR, sqlVersion3, SQL_RESULT_LEN, &ptrSqlVersion3);
                string str_year((const char*)sqlVersion3);    //convert sqlstring to string
                    

                SQLGetData(SQLStatementHandle, 5, SQL_CHAR, sqlVersion4, SQL_RESULT_LEN, &ptrSqlVersion4);
                string str_name((const char*)sqlVersion4);    //convert sqlstring to string
                    

                SQLGetData(SQLStatementHandle, 6, SQL_CHAR, sqlVersion5, SQL_RESULT_LEN, &ptrSqlVersion5);
                string str_location((const char*)sqlVersion5);    //convert sqlstring to string
                    
                    //"1/5.04.2022/Event_Sterilizare/Parcul IOR/";
                nr++;
                cout << "Au fost transmise datele cerute despre animalele existente!\n";
                this->msg.append("/");
                //this->msg.append(str_ID_campaign);
                //this->msg.append("/");
                this->msg.append(str_day);
                this->msg.append(".");
                this->msg.append(str_month);
                this->msg.append(".");
                this->msg.append(str_year);
                this->msg.append("/");
                this->msg.append(str_name);
                this->msg.append("/");
                this->msg.append(str_location);

                cout << "\n";
                         
            }
            string nr_campanii;
            nr_campanii = to_string(nr);
            this->msg = nr_campanii + this->msg;
            this->msg.append("/");
        }
    } while (FALSE);

    SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	//this->msg = "1/5.04.2022/Event_Sterilizare/Parcul IOR/";

	LOG::getInstance().logSendCampaign();

	return this->msg;
}
