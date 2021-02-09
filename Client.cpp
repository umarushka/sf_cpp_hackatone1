#include "Sender.h"
#include "AdapterInterAction.h"
#include "InterActionConsole.h"
#include "Users.h"

int main()
{
    Sender chatChannel("chatData"); // ��� � UsersDBMapping ��������� ��������� � RequestsToServer � ���������������� ���. 
    UsersDBMapping usersMapper("userData");
    AdapterInterAction controller(InterActionConsole::getInstance(), chatChannel, usersMapper);
    controller.run();
    return 0;	
}
