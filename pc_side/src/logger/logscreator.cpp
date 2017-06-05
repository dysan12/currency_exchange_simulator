#include "logscreator.h"
#include "errorslog.h"
#include "warningslog.h"

LogsCreator::LogsCreator()
{

}

LogsHandler * LogsCreator::create(const std::string logType)
{
   if(logType == "error")
       return new ErrorsLog();
   else if (logType == "warning")
       return new WarningsLog();
   else
       return new ErrorsLog();
    /*
    switch(atoi(logType)) {
     case atoi("errors"):
        return new ErrorsLog();
        break;
    default:
        return new ErrorsLog();
        break;
    }
*/
    //return new (logType)();
   // ErrorsLog *handler = new ErrorsLog();
    //return new ErrorsLog();
    //return new {"ErrorsLog"}();
}
