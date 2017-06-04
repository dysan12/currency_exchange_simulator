#include <string>

#include "logshandler.h"

#ifndef ERRORSLOG_H
#define ERRORSLOG_H


class ErrorsLog : public LogsHandler
{
public:
    ErrorsLog();
    void saveLog(const char* module, Exception *exception);
};

#endif // ERRORSLOG_H
