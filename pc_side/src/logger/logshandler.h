#ifndef LOGSHANDLER_H
#define LOGSHANDLER_H

#include <time.h>
#include <string>
#include <iostream>
#include <fstream>

#include "exception.h"


class LogsHandler
{
public:
    LogsHandler();
    virtual void saveLog(const std::string, Exception *exception) = 0;
    std::string formatMessage(const std::string module, const std::string message);
};

#endif // LOGSHANDLER_H
