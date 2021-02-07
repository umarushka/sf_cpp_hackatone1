#ifndef _SENDER_H
#define _SENDER_H

#include <iostream>
#include "Messages.h"
#include "Users.h"
#include "Subject.h"
#include "Channel.h"

using namespace std;

class Sender {

    Channel<Users> *someSender;

public:
    Channel<Users> *getSomeSender() const;

    void setSomeSender(Channel<Users> *someSender);

public:
    Sender();

    Sender(Channel<Users> *someSender);

    virtual ~Sender();

    Sender(Sender & source);

    Sender(const Sender & source);

    Sender & operator=(Sender & source);

    Sender & operator=(const Sender & source);

    friend  ostream & operator<<(ostream & os, const Sender & x);

	bool send(Messages &msg);

};
#endif
