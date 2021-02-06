#ifndef _MESSAGES_H
#define _MESSAGES_H

#include <iostream>

using namespace std;

class Messages {
  public:
    Messages();

    virtual ~Messages();

    Messages(Messages & source);

    Messages(const Messages & source);

    Messages & operator=(Messages & source);

    Messages & operator=(const Messages & source);

    friend  ostream & operator<<(ostream & os, const Messages & x);

};
#endif
