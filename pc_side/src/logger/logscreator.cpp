#include "logscreator.h"
#include "errorslog.h"

LogsCreator::LogsCreator()
{

}

LogsHandler * LogsCreator::create(const char* logType)
{
    //return new (logType)();
    ErrorsLog *handler = new ErrorsLog();
    return handler;
}
