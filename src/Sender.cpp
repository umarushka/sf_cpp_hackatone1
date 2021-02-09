/*
	Модуль\класс посылки сообщения
 */

#include "Sender.h"

Sender::Sender() 
{
    
}

Sender::Sender(std::string url) noexcept(false) : 
    _url(url)
{
}

std::vector<Message> Sender::getLog() noexcept(false)
{
    std::vector<Message> msgs;
    std::string readStr;
    _fileStr.open(_url, std::ios::in);
    if (!_fileStr.is_open()) 
    {
    }
    while (!_fileStr.eof())
    {
        getline(_fileStr, readStr);
        if (readStr == "<Message>")
        {
            Message msg;
            getline(_fileStr, readStr);
            if (readStr == "<Echo>") //считывание типа строки
            {
                msg.type = messageType::ECHO;
            }
            else if (readStr == "<Private>")
            {
                msg.type = messageType::PRIVATE;
            }
            else // исключение
            {

            }
            getline(_fileStr, readStr);
            msg.str = readStr;
            msgs.push_back(msg);
        }
        else
        {// исключение

        }
    }
    _fileStr.close(); // аккуратно с исключениями, можно его вызвать и забыть закрыть файл
    return msgs;
}

void Sender::addMessage(Message msg) noexcept(false)
{
    _fileStr.open(_url, std::ios::app);
    if (!_fileStr.is_open()) // исключение 
    {
    }
    _fileStr << "<Message>" << std::endl;
    if (msg.type == messageType::ECHO)
    {
        _fileStr << "<Echo>" << std::endl;
    }
    else if (msg.type == messageType::PRIVATE)
    {
        _fileStr << "<Private>" << std::endl;
    }
    _fileStr << msg.str << std::endl;
    _fileStr.close();
}


Sender::~Sender() 
{
}

Sender::Sender(Sender & source) 
{
}

Sender::Sender(const Sender & source) 
{
}

Sender & Sender::operator=(Sender & source) 
{
	return source;
}

Sender & Sender::operator=(const Sender & source) 
{
	return const_cast<Sender &>(source);
}
/*
bool Sender::send(Messages &msg) {
    Users users = someSender->getState();
    users.setMsg(msg);
    someSender->setState(users);
    return false;
}

Channel<Users> *Sender::getSomeSender() const {
    return someSender;
}

void Sender::setSomeSender(Channel<Users> *someSender) {
    Sender::someSender = someSender;
}
*/
