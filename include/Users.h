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
    string name;
    int id;
    int level;
    Messages msg;

public:
    const string &getName() const;

    void setName(const string &name);

    int getId() const;

    void setId(int id);

    int getLevel() const;

    void setLevel(int level);

public:
    Users();

    virtual ~Users();

    Users(Users & source);

    Users(const Users & source);

    Users & operator=(Users & source);

    Users & operator=(const Users & source);

    friend  ostream & operator<<(ostream & os, const Users & x);


};
#endif
