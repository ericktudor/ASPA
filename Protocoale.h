#pragma once

#include <iostream>
#include <string>
#include "IProtocol.h"
#include "LOG.h"

//
#include <windows.h>
#include <stddef.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#pragma comment(lib, "odbc32.lib")

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 2400
//

using namespace std;


class Protocoale : public IProtocol
{
protected:
	string msg;
public:
	Protocoale();

	~Protocoale() {}
};

