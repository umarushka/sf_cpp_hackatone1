#include "Users.h"

UsersDBMapping::UsersDBMapping(std::string userBDName) :
    _nameDB(userBDName) 
{
}

void UsersDBMapping::readUsersData() noexcept(false)
{
    std::string readStr;
    _BDStream.open(_nameDB, std::ios::in);
    if (!_BDStream.is_open())  // исключение 
    {
    }
    _usersData.clear();//Лучше куда-то сохранять данные, на случай если с новыми что-то не так (транзакция)
    while (!_BDStream.eof())
    {
        getline(_BDStream, readStr);
        if (readStr == "<User>")
        {
            User user;
            getline(_BDStream, readStr);
            user.id = stoi(readStr);
            getline(_BDStream, user.nickName);
            getline(_BDStream, user.password); // Хранение паролей в открытом виде!!! Убрать при первой возможности. 
            getline(_BDStream, readStr);
            user.onlineStatus = stoi(readStr); // исключение если там нет числа
            getline(_BDStream, readStr);
            user.rating = stoi(readStr); // исключение если там нет числа
            _usersData.push_back(user);
        }
        else
        {// исключение

        }
    }
    _BDStream.close(); // аккуратно с исключениями, можно его вызвать и забыть закрыть файл
}


std::vector<User> UsersDBMapping::getUsersData() noexcept(false)
{
    return _usersData;
}

void UsersDBMapping::saveUsersData()
{
    _BDStream.open(_nameDB, std::ios::out);
    if (!_BDStream.is_open())  // исключение 
    {
    }

    for (User newUser : _usersData)
    {
        _BDStream << "<User>" << std::endl;
        _BDStream << newUser.id << std::endl;
        _BDStream << newUser.nickName << std::endl;
        _BDStream << newUser.password << std::endl;
        _BDStream << newUser.onlineStatus << std::endl;
        _BDStream << newUser.rating << std::endl;
    }
    _BDStream.close();
}

void  UsersDBMapping::setUsersData(std::vector<User> usersData)
{
    _usersData = usersData;
}

int UsersDBMapping::findUser(std::string nickName)
{
    for (User user : _usersData)
    {
        if (nickName == user.nickName)
        {
            return user.id;
        }
    }
    return -1;
}

std::string UsersDBMapping::getUserPassFromId(int id)
{
    for (User user : _usersData)
    {
        if (id == user.id)
        {
            return user.password;
        }
    }
    return "";
}

std::string UsersDBMapping::getUserNickNameFromId(int id)
{
    for (User user : _usersData)
    {
        if (id == user.id)
        {
            return user.nickName;
        }
    }
    return "";
}
