//#include "DB.h"
//
//void DB::initialization()
//{
//    
//    do
//    {
//
//        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
//            break;
//
//        if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
//            break;
//
//        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
//            break;
//
//        if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
//            break;
//
//        SQLCHAR retConString[1024];
//
//        switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server}; SERVER=localhost, 1434; DATABASE=Northwind; Trusted=true;", SQL_NTS, (SQLWCHAR*)retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
//        case SQL_SUCCESS:
//            std::cout << "Baza de date conectata cu succes!" << std::endl;
//            break;
//        case SQL_SUCCESS_WITH_INFO:
//            std::cout << "Baza de date conectata cu succes!" << std::endl;
//            break;
//        case SQL_NO_DATA_FOUND:
//            //showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//            retCode = -1;
//            break;
//        case SQL_INVALID_HANDLE:
//            // showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//            retCode = -1;
//            break;
//        case SQL_ERROR:
//            cout << "Here" << endl; // it is failing here <<<<<<
//           // showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
//            retCode = -1;
//            break;
//        default:
//            break;
//        }
//
//        if (retCode == -1)
//            break;
//
//        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
//            break;
//
//
//        //if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLWCHAR*)L"SELECT * from users", SQL_NTS)) {
//        //    cout << "Error querying SQL Server";
//        //    cout << "\n";
//        //}
//        //else {
//        //    //declare output variable and pointer
//
//        //    //clasa baza de date
//        //    //metoda interogari
//        //    SQLCHAR sqlVersion[SQL_RESULT_LEN];
//        //    SQLINTEGER ptrSqlVersion;
//        //    while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
//        //        //for() de parcurs toate coloanele din baza de date
//        //        //i coloane
//        //        SQLGetData(SQLStatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
//        //        //display query result
//        //        cout << "\nQuery Result:\n\n";
//        //        cout << sqlVersion << endl;
//        //    }
//        //}
//        //} while (false);
//
//        
//
//    } while (false);
//
//    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
//    {
//        SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
//        SQLDisconnect(SQLConnectionHandle);
//        SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
//        SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
//    }
//   
//}
//
////void DB::showSQLError(unsigned int handleType, const SQLHANDLE& handle)
////{
////    SQLWCHAR sqlState[256],
////        errorMsg[256];
////    SDWORD    nativeError = 0L;
////    SWORD    pcbErrorMsg = 0;
////    SQLSMALLINT  recordNumber = 1;
////    if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, sqlState, NULL, errorMsg, 1024, NULL))
////        wcout << "SQL driver message: " << errorMsg << "\nSQL state: " << sqlState << "." << endl;
////}
//
//SQLHANDLE DB::getEnvHandle()
//{
//    return this->SQLEnvHandle;
//}
//
//SQLHANDLE DB::getConnectionHandle()
//{
//    return this->SQLConnectionHandle;
//}
//
//SQLHANDLE DB::getStatementHandle()
//{
//    return this->SQLStatementHandle;
//}