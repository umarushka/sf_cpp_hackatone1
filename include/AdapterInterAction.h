#ifndef _ADAPTERINTERACTION_H
#define _ADAPTERINTERACTION_H

#include <iostream>

#include "InterActionConsole.h"
#include "Sender.h"
#include "Users.h"

class AdapterInterAction 
{
  public:
    AdapterInterAction() = default;
    AdapterInterAction(InterActionConsole& UI, Sender& chatChannel, UsersDBMapping& usersMapper );
    void run();

private:
    InterActionConsole& _UI;
    Sender& _chatChannel;
    UsersDBMapping& _usersMapper;
};
#endif
