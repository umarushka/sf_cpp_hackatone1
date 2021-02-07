#ifndef _USERS_H
#define _USERS_H

#include <iostream>

using namespace std;

class Users {

    string name;
    int id;
    int level;
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
