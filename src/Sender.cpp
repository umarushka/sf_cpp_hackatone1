#include "Sender.h"

Sender::Sender(std::string url) : 
    _url(url)
{
}

std::vector<Message> Sender::getLog() noexcept(false)
{
    std::vector<Message> msgs;
    std::string readStr;
    _fileStream.open(_url, std::ios::in);
    if (!_fileStream.is_open())  // исключение 
    {
    }
    while (!_fileStream.eof())
    {
        getline(_fileStream, readStr);
        if (readStr == "<Message>")
        {
            Message msg;
            getline(_fileStream, readStr);
            if (readStr == "<Echo>") //считывание типа строки
            {
                getline(_fileStream, readStr);
                msg.fromUserId = stoi(readStr);
                msg.type = messageType::ECHO;
            }
            else if (readStr == "<Private>")
            {
                msg.type = messageType::PRIVATE;
            }
            else // исключение
            {

            }
            getline(_fileStream, msg.str);
            msgs.push_back(msg);
        }
        else
        {// исключение

        }
    }
    _fileStream.close(); // аккуратно с исключениями, можно его вызвать и забыть закрыть файл
    return msgs;
}

void Sender::addMessage(Message msg) noexcept(false)
{
    _fileStream.open(_url, std::ios::app);
    if (!_fileStream.is_open()) // исключение 
    {
    }
    _fileStream << "<Message>" << std::endl;
    if (msg.type == messageType::ECHO)
    {
        _fileStream << "<Echo>" << std::endl;
    }
    else if (msg.type == messageType::PRIVATE)
    {
        _fileStream << "<Private>" << std::endl;
    }
    _fileStream << msg.fromUserId << std::endl;
    _fileStream << msg.str << std::endl;
    _fileStream.close();
}
