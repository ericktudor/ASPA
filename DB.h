//#pragma once
//#include <stddef.h>
//#include <sqlext.h>
//#include <sqltypes.h>
//#include <sql.h>
//#include <string>
//#include <iostream>
//#include <wtypes.h>
//
//#define SQL_RESULT_LEN 240
//#define SQL_RETURN_CODE_LEN 2400
//
//using namespace std;
//
//class DB
//{
//private:
//    SQLHANDLE SQLEnvHandle;
//    SQLHANDLE SQLConnectionHandle;
//    SQLHANDLE SQLStatementHandle;
//    SQLRETURN retCode;  
//
//    
//public:
//    DB()
//    {
//        SQLHANDLE SQLEnvHandle = NULL;
//        SQLHANDLE SQLConnectionHandle = NULL;
//        SQLHANDLE SQLStatementHandle = NULL;
//        SQLRETURN retCode = 0;
//    }
//    void initialization();
//    void  showSQLError(unsigned int handleType, const SQLHANDLE& handle);
//    SQLHANDLE getEnvHandle();
//    SQLHANDLE getConnectionHandle();
//    SQLHANDLE getStatementHandle();
//};
//
