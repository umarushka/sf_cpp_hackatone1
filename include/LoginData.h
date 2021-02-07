#ifndef _LOGINDATA_H
#define _LOGINDATA_H

#include <string>

class LoginData
{
public:
    bool setLogin(std::string login);
    std::string getLogin();
    bool setPassword(std::string password);
    std::string getPassword();

private:
    std::string _login{};
    std::string _password{};
};

#endif
