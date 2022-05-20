#include "Protocoale.h"

Protocoale::Protocoale()
{
   /* this->SQLEnvHandle = NULL;
    this->SQLConnectionHandle = NULL;
    this->SQLStatementHandle = NULL;
    this->retCode = 0; */  
}


//void Protocoale::init()
//{
//    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
//        return;
//
//    if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
//        return;
//
//    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
//        return;
//
//    if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
//        return;
//
//    SQLCHAR retConString[1024];
//    switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server}; SERVER=localhost, 1434; DATABASE=ASPAserver; Trusted=true;", SQL_NTS, (SQLWCHAR*)retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
//    case SQL_SUCCESS:
//        std::cout << "Baza de date ASPAserver conectata cu succes!" << std::endl;
//        break;
//    case SQL_SUCCESS_WITH_INFO:
//        std::cout << "Baza de date ASPAserver conectata cu succes!" << std::endl;
//        break;
//    case SQL_NO_DATA_FOUND:
//        //showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//        retCode = -1;
//        break;
//    case SQL_INVALID_HANDLE:
//        // showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//        retCode = -1;
//        break;
//    case SQL_ERROR:
//        cout << "Here" << endl; // it is failing here <<<<<<
//        //showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//        retCode = -1;
//        break;
//    default:
//        break;
//    }
//
//    if (retCode == -1)
//        return;
//
//    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
//        return;
//}
