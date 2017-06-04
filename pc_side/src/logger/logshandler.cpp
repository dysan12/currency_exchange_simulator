#include "logshandler.h"

LogsHandler::LogsHandler()
{

}

std::string LogsHandler::formatMessage(const char* module, const char* message)
{
    time_t current_time = time(0);
    tm * now = localtime( & current_time );
    std::string stringDate = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" +std::to_string(now->tm_mday) + " " + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
    char buffer [300];//TO CHANGE
    sprintf(buffer, "[%s][%s] %s", stringDate.c_str(), module, message);
    return buffer;
}
