#ifndef _USERS_H
#define _USERS_H

#include <iostream>
#include "Messages.h"

using namespace std;

class Users {
private:
    int _id;
    string _nickname;
    string _password;
    int _rating;
    Messages msg;

public:

    Users();

    Users(string name, int id, int level);

    virtual ~Users();

    Users(Users & source);

    Users(const Users & source);

    Users & operator=(Users & source);

    Users & operator=(const Users & source);

    friend  ostream & operator<<(ostream & os, const Users & x);

    const Messages &getMsg() const;

    void setMsg(const Messages &msg);

    int getId() const;

    void setId(int id);

    const string &getNickname() const;

    void setNickname(const string &nickname);

    const string &getPassword() const;

    void setPassword(const string &password);

    double getRating() const;

    void setRating(double rating);

};
#endif
