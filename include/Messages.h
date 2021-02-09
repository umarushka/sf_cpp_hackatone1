#ifndef _MESSAGES_H
#define _MESSAGES_H

#include <string>

enum messageType
{
    ECHO,
    PRIVATE,
    COMMAND
};

struct Message 
{
    messageType type{messageType::ECHO};
    int fromUserId{1}; 
    int toUserId{0};
    std::string str{""};

};
#endif
