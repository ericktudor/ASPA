#include "ProtocolSearchAnimal.h"

string ProtocolSearchAnimal::handleMessage(string msg)
{
	// 11/age/sex/location/size/species/

	int x = msg.find("/");
	int y = msg.find("/", x + 1);

	this->age = msg.substr(x + 1, y - x - 1);
	cout << this->age << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->sex = msg.substr(x + 1, y - x - 1);
	cout << this->sex << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->location = msg.substr(x + 1, y - x - 1);
	cout << this->location << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->size = msg.substr(x + 1, y - x - 1);
	cout << this->size << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);

	this->species = msg.substr(x + 1, y - x - 1);
	cout << this->species << endl;
	cout << x << " " << y << endl;

	x = y;

	y = msg.find("/", x + 1);


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
        strcpy(newvar1, this->age.c_str());
        char* newvar2 = new char[50];
        strcpy(newvar2, this->sex.c_str());*/
        SQLCHAR newquery[100];


        sprintf((char*)newquery, "SELECT * from Animals");
        std::string str((const char*)newquery);
        std::wstring instr(str.begin(), str.end()); //str to wstr.

        if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)instr.c_str(), SQL_NTS))
        {
            cout << "Error querying SQL Server";
            cout << "\n";
        }
        else 
        {
            // 11/age/sex/location/size/species/
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
                int ok_age = 0;
                int ok_sex = 0;
                int ok_location = 0;
                int ok_size = 0;
                int ok_species = 0;

                SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                string str_ID_animal((const char*)sqlVersion);    //convert sqlstring to string
                

                SQLGetData(SQLStatementHandle, 2, SQL_CHAR, sqlVersion1, SQL_RESULT_LEN, &ptrSqlVersion1);
                string str_age((const char*)sqlVersion1);    //convert sqlstring to string
                if (this->age== str_age || this->age == "Any")
                {
                    ok_age = 1;
                }

                SQLGetData(SQLStatementHandle, 3, SQL_CHAR, sqlVersion2, SQL_RESULT_LEN, &ptrSqlVersion2);
                string str_sex((const char*)sqlVersion2);    //convert sqlstring to string
                if (this->sex == str_sex || this->sex == "Any")
                {
                    ok_sex = 1;
                }

                SQLGetData(SQLStatementHandle, 4, SQL_CHAR, sqlVersion3, SQL_RESULT_LEN, &ptrSqlVersion3);
                string str_location((const char*)sqlVersion3);    //convert sqlstring to string
                if (this->location == str_location || this->location == "Any")
                {
                    ok_location = 1;
                }

                SQLGetData(SQLStatementHandle, 5, SQL_CHAR, sqlVersion4, SQL_RESULT_LEN, &ptrSqlVersion4);
                string str_size((const char*)sqlVersion4);    //convert sqlstring to string
                if (this->size == str_size || this->size == "Any")
                {
                    ok_size = 1;
                }

                SQLGetData(SQLStatementHandle, 6, SQL_CHAR, sqlVersion5, SQL_RESULT_LEN, &ptrSqlVersion5);
                string str_species((const char*)sqlVersion5);    //convert sqlstring to string
                if (this->species == str_species || this->species == "Any")
                {
                    ok_species = 1;
                }

                if (ok_age == 1 && ok_location == 1 && ok_sex == 1 && ok_size == 1 && ok_species == 1)
                {
                    nr++;
                    cout << "A fost gasit un animal cu caracteristicile dorite!";
                    this->msg.append("/");
                    this->msg.append(str_ID_animal);
                    this->msg.append("/");
                    this->msg.append(str_age);
                    this->msg.append("/");
                    this->msg.append(str_sex);
                    this->msg.append("/");
                    this->msg.append(str_location);
                    this->msg.append("/");
                    this->msg.append(str_size);
                    this->msg.append("/");
                    this->msg.append(str_species);
                }

                cout << "\n";
            }
            
            string nr_animale; 
            nr_animale = to_string(nr);
            this->msg = nr_animale + this->msg;
            this->msg.append("/");
        }
    } while (FALSE);

    if (this->msg == "")
    {
        cout << "Nu a fost gasit un animal cu caracteristicile dorite!";
        this->msg = "*0*";
    }

    SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);


	LOG::getInstance().logSearchAnimal();

	
	return this->msg;
}