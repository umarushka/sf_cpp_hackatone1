#ifndef _USERS_H
#define _USERS_H

#include <iostream>

using namespace std;

class Users {
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
