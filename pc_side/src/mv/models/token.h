#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
    std::string id;
public:
    Token(std::string id);
    std::string getId();
    void setId(std::string id);
};

#endif // TOKEN_H
