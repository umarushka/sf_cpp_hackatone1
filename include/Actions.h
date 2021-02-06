#ifndef _ACTIONS_H
#define _ACTIONS_H

#include <iostream>

using namespace std;

class Actions {
  public:
    Actions();

    virtual ~Actions();

    Actions(Actions & source);

    Actions(const Actions & source);

    Actions & operator=(Actions & source);

    Actions & operator=(const Actions & source);

    friend  ostream & operator<<(ostream & os, const Actions & x);

};
#endif
