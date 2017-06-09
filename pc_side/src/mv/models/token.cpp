#include "token.h"

Token::Token(std::string id) : id(id)
{

}
std::string Token::getId()
{
    return this->id;
}

void Token::setId(std::string id)
{
    this->id = id;
}

