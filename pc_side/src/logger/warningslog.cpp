#include "warningslog.h"
#include <QApplication>
WarningsLog::WarningsLog()
{

}

void WarningsLog::saveLog(const std::string module, Exception *exception)
{
   std::ofstream logFile;
   logFile.open("logs\\warnings.log", std::ios::app);
   logFile << this->formatMessage(module, exception->getMessage()) << std::endl;
   logFile.close();
}
