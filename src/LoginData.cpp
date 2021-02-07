#include "LoginData.h"

bool LoginData::setLogin(std::string login)
{
    for(int i = 0; i < login.length(); ++i)
    {
        if (isalpha(login[i]) || isdigit(login[i]))
        {
            continue;
        }
        return false;
    }
    _login = login;
    return true;
}

std::string LoginData::getLogin()
{
    return _login;
}

bool LoginData::setPassword(std::string password)
{
    for(int i = 0; i < password.length(); ++i)
    {
        if (isalpha(password[i]) || isdigit(password[i]))
        {
            continue;
        }
        return false;
    }
    _password = password;
    return true;
}

std::string LoginData::getPassword()
{
    return _password;
}