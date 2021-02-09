#ifndef _SENDER_H
#define _SENDER_H

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

#include "Messages.h"

class Sender 
{
public:
    Sender() noexcept(false);
    Sender::Sender(std::string url) noexcept(false);
    std::vector<Message> getLog();
    void addMessage(Message msg) noexcept(false);

    ~Sender();

    Sender(Sender & source);

    Sender(const Sender & source);

    Sender & operator=(Sender & source);

    Sender& operator=(const Sender& source);

	// bool send(Messages &msg);

private:
    std::string _url;
    std::fstream _fileStr;
};
#endif
