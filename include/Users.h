#ifndef _USERS_H
#define _USERS_H

#include <iostream>

using namespace std;

class Users {

public:
    Users(string nickname, string password,double rating);

    virtual ~Users();

    void setnickname(string);
    string getnickname();

    void setpassword(string);
    string getpassword();

    void setrating(double);
    double getrating();

    Users(Users & source);

    /*Users(const Users & source);

    Users & operator=(Users & source);

    Users & operator=(const Users & source);

    friend  ostream & operator<<(ostream & os, const Users & x);*/

private:
    string _nickname;
    string _password;
    double _rating;

};
#endif
