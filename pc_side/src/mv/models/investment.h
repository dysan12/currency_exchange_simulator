<<<<<<< HEAD
#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

class Investment
{
    std::string name;
public:
    Investment(std::string name);
=======
#ifndef INVESTMENTS_H
#define INVESTMENTS_H
#include<string>

class Investment
{
    std::string user_login,
                found_date,
                name;
    double pln,
            usd,
            eur,
            jpy,
            gbp,
            czk,
            aud,
            brl,
            dkk,
            nok,
            rub;
public:
    Investment(std::string user_login, std::string found_date, std::string name,
                double pln, double usd, double eur, double jpy, double gbp,
                double czk, double aud, double brl, double dkk, double nok,
                double rub);

    void setUserLogin(std::string user_login);
    void setFoundDate(std::string found_date);
    void setName(std::string name);
    void setPln(double pln);
    void setUsd(double usd);
    void setEur(double eur);
    void setJpy(double jpy);
    void setGbp(double gbp);
    void setCzk(double czk);
    void setAud(double aud);
    void setBrl(double brl);
    void setDkk(double dkk);
    void setNok(double nok);
    void setRub(double rub);

    std::string getUserLogin();
    std::string getFoundDate();
    std::string getName();
    double getPln();
    double getUsd();
    double getEur();
    double getJpy();
    double getGbp();
    double getCzk();
    double getAud();
    double getBrl();
    double getDkk();
    double getNok();
    double getRub();
>>>>>>> 2e48aaf8a4847b0ccc8f8564b37e71d63e4c5514
};

#endif // INVESTMENT_H
