#ifndef _RECEIVER_H
#define _RECEIVER_H

#include <iostream>
#include "Messages.h"

using namespace std;

class Receiver {

    Messages *msg;

  public:
    Receiver();

    virtual ~Receiver();

    Receiver(Receiver & source);

    Receiver(const Receiver & source);

    Receiver & operator=(Receiver & source);

    Receiver & operator=(const Receiver & source);

    friend  ostream & operator<<(ostream & os, const Receiver & x);

	Messages & receive();

};
#endif
