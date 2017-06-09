#include "investment.h"

Investment::Investment(std::string user_login, std::string found_date,
                         std::string name, double pln, double usd, double eur,
                         double jpy, double gbp, double czk, double aud, double brl,
                         double dkk, double nok, double rub)
    : user_login(user_login), found_date(found_date), name(name), pln(pln), usd(usd),
eur(eur), jpy(jpy), gbp(gbp), czk(czk), aud(aud), brl(brl), dkk(dkk), nok(nok),
rub(rub){}

void Investment::setUserLogin(std::string user_login){
    this->user_login=user_login;
}

void Investment::setFoundDate(std::string found_date){
     this->found_date=found_date;
}

void Investment::setName(std::string name){
     this->name=name;
}

void Investment::setPln(double pln){
    this->pln=pln;
}

void Investment::setUsd(double usd){
    this->usd=usd;
}

void Investment::setEur(double eur){
    this->eur=eur;
}

void Investment::setJpy(double jpy){
    this->jpy=jpy;
}

void Investment::setGbp(double gbp){
    this->gbp=gbp;
}

void Investment::setCzk(double czk){
    this->czk=czk;
}

void Investment::setAud(double aud){
    this->aud=aud;
}

void Investment::setBrl(double brl){
    this->brl=brl;
}

void Investment::setDkk(double dkk){
    this->dkk=dkk;
}

void Investment::setNok(double nok){
    this->nok=nok;
}

void Investment::setRub(double rub){
    this->rub=rub;
}



std::string Investment::getUserLogin(){
    return user_login;
}

std::string Investment::getFoundDate(){
    return found_date;
}

std::string Investment::getName(){
    return name;
}

double Investment::getPln(){
    return pln;
}

double Investment::getUsd(){
    return usd;
}

double Investment::getEur(){
    return eur;
}

double Investment::getJpy(){
    return jpy;
}

double Investment::getGbp(){
    return gbp;
}

double Investment::getCzk(){
    return czk;
}

double Investment::getAud(){
    return aud;
}

double Investment::getBrl(){
    return brl;
}

double Investment::getDkk(){
    return dkk;
}

double Investment::getNok(){
    return nok;
}

double Investment::getRub(){
    return rub;
}
