#include "errorslog.h"
#include <QApplication>
ErrorsLog::ErrorsLog()
{

}

void ErrorsLog::saveLog(const char* module, Exception *exception)
{
   std::ofstream logFile;
   logFile.open("logs\\errors.log", std::ios::app);
   logFile << this->formatMessage(module, exception->getMessage()) << std::endl;
   logFile.close();
}
