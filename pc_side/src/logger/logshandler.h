#include <time.h>
#include <string>
#include <iostream>
#include <fstream>

#include "exception.h"


#ifndef LOGSHANDLER_H
#define LOGSHANDLER_H


class LogsHandler
{
public:
    LogsHandler();
    virtual void saveLog(const char* module, Exception *exception) = 0;
    std::string formatMessage(const char* module, const char* message);
};

#endif // LOGSHANDLER_H
