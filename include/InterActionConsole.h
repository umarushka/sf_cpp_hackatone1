#ifndef _INTERACTIONCONSOLE_H
#define _INTERACTIONCONSOLE_H

#include <iostream>
#include <string>

#include "LoginData.h"

enum greetingAnswers
{
    LOGIN,
    REGISTRARION,
    EXIT,
    NOTANSWER
};

enum InputType
{
    ECHO_MESSAGE,
    PRIVATE_MESSAGE,
    COMMAND
};

struct userInput
{
    InputType type;
    std::string str;
};


class InterActionConsole final
{
public:
    // Интерфейс может быть только один, поэтому реализация через патерн Singleton Мэйерса
    static InterActionConsole& getInstance()
    {
        static InterActionConsole  instance;
        return instance;
    }
    greetingAnswers start();
    void addMessageToChat(std::string message); // тут подумать как лучше передавать строку копированием или еще как...
    LoginData login();
    void enter(std::string userName);
    userInput getInput();
    ~InterActionConsole();
    friend  std::ostream & operator<<(std::ostream & os, const InterActionConsole & x);

private:
    // Приватные конструкторы обеспечивают патерн Singleton Мэйерса
    InterActionConsole();
    InterActionConsole(InterActionConsole & source);
    InterActionConsole(const InterActionConsole & source);
    InterActionConsole & operator=(InterActionConsole & source);
    InterActionConsole & operator=(const InterActionConsole & source);
    void drawChatFrameTop();
    void drawChatFrameBottom();

private:
    const int _chatStrQuantity = 25;
    const int _dataStrLength = 70;
    std::string _userName;
    std::string *_data; // пожалуй не лучшее название, стоит оттолкнуться от _chatStrQuantity
};
#endif
