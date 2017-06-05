#ifndef ERRORSLOG_H
#define ERRORSLOG_H

#include <string>

#include "logshandler.h"


class ErrorsLog : public LogsHandler
{
public:
    ErrorsLog();
    void saveLog(const std::string, Exception *exception);
};

#endif // ERRORSLOG_H
