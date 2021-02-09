#include "Sender.h"
#include "AdapterInterAction.h"
#include "InterActionConsole.h"
#include "Users.h"

int main()
{
    Sender chatChannel("chatData"); // это и UsersDBMapping требуется перенести в RequestsToServer и инициализировать там. 
    UsersDBMapping usersMapper("userData");
    AdapterInterAction controller(InterActionConsole::getInstance(), chatChannel, usersMapper);
    controller.run();
    return 0;	
}
