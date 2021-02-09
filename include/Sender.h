#ifndef _SENDER_H
#define _SENDER_H

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

#include "Messages.h"

class Sender // нужно переименовать
{
public:
    Sender() = default;
    Sender::Sender(std::string url);
    std::vector<Message> getLog() noexcept(false);
    void addMessage(Message msg) noexcept(false);

private:
    std::string _url;
    std::fstream _fileStream;
};
#endif
