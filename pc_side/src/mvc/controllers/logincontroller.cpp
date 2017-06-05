#include "logincontroller.h"

LogInController::LogInController()
{

}

void LogInController::generateWindow()
{
    LoginWindow *login=new LoginWindow();
    login->show();
}
