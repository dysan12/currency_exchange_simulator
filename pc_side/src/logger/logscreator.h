#include <string>

#include "logshandler.h"

#ifndef LOGSCREATOR_H
#define LOGSCREATOR_H


class LogsCreator
{
public:
    LogsCreator();
    LogsHandler * create(const char* logType);
};

#endif // LOGSCREATOR_H
