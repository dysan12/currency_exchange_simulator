#ifndef LOGSCREATOR_H
#define LOGSCREATOR_H

#include <string>

#include "logshandler.h"


class LogsCreator
{
public:
    LogsCreator();
    LogsHandler * create(const std::string logType);
};

#endif // LOGSCREATOR_H
