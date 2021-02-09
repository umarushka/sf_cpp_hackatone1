#ifndef _USERS_H
#define _USERS_H

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

#include "Messages.h"

struct User
{
    int id;
    std::string nickName;
    std::string password;
    bool onlineStatus{ false };
    int rating{0};
};

class UsersDBMapping
{
public:
    UsersDBMapping() = default;
    UsersDBMapping(std::string nameDB);
    void UsersDBMapping::readUsersData() noexcept(false);
    void saveUsersData();
    std::vector<User> UsersDBMapping::getUsersData() noexcept(false); // Не хорошо, что эта функция возвращает пользователей вместе с паролями. Желательно отдельная функция получения пароля по id. Т.к. этот вектор может использоваться например для вывода списка пользователей и т.д.
    void setUsersData(std::vector<User> usersData);
    int findUser(std::string nickName) noexcept(false);
    std::string getUserPassFromId(int id);
    std::string getUserNickNameFromId(int id);
    void addUser(User newUser);

private:
    std::string _nameDB;
    std::fstream _BDStream;
    std::vector<User> _usersData;
};
#endif
