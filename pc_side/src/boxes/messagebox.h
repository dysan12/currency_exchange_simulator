#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include<QMessageBox>
#include<QString>


class MessageBox
{
    QString title, msg;
    QString titleEmpty="Empty field";
    QString msgFields="Both fields must not be empty!";
    QString titleBadInfo="Bad information provided";
    QString msgLoginNotTrue="Provided login credentials aren't true!";
    QString titleRegSucc="Registering successful";
    QString msgRegSucc="You can now use your new account";
    QString msgRegNotAvail="Provided register credentials aren't avaible!";
public:
    MessageBox(QString, QString);
};

#endif // MESSAGEBOX_H
