#ifndef _USERS_H
#define _USERS_H

#include <iostream>
#include "Messages.h"

using namespace std;

class Users {
public:
    const Messages &getMsg() const;

    void setMsg(const Messages &msg);

private:
    string _name;
    string _nickname;
    int _id;
    int _level;
    string _password;
    double _rating;
    Messages msg;

public:
    const string &getName() const;

    void setName(const string &name);

    int getId() const;

    void setId(int id);

    int getLevel() const;

    void setLevel(int level);

    const string &getNickname() const;

    void setNickname(const string &nickname);

    const string &getPassword() const;

    void setPassword(const string &password);

    double getRating() const;

    void setRating(double rating);

public:
    Users();

    Users(string name, int id, int level);

    virtual ~Users();

    Users(Users & source);

    Users(const Users & source);

    Users & operator=(Users & source);

    Users & operator=(const Users & source);

    friend  ostream & operator<<(ostream & os, const Users & x);


};
#endif
