#ifndef WARNINGSLOG_H
#define WARNINGSLOG_H

#include <string>

#include "logshandler.h"


class WarningsLog : public LogsHandler
{
public:
    WarningsLog();
    void saveLog(const std::string, Exception *exception);
};

#endif // WARNINGSLOG_H
