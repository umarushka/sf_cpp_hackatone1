#ifndef _ECHOUSER_H
#define _ECHOUSER_H

#include <iostream>
#include "Channel.h"
#include "Users.h"

using namespace std;

class EchoUser {

    Channel<Users> *userSendReceive;

  public:
    EchoUser();

    EchoUser(Channel<Users> *userSendReceive);

    virtual ~EchoUser();

    EchoUser(EchoUser & source);

    EchoUser(const EchoUser & source);

    EchoUser & operator=(EchoUser & source);

    EchoUser & operator=(const EchoUser & source);

    friend  ostream & operator<<(ostream & os, const EchoUser & x);

    bool hasPacket();

    void sendPacket();

};
#endif
