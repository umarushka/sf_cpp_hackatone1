/*
	Модуль\класс адаптера к интерфейсу пользователя
 */

#include "AdapterInterAction.h"
#include "InterActionConsole.h"
#include "Sender.h"
#include "Messages.h"
#include "Receiver.h"

AdapterInterAction::AdapterInterAction()
{
    Sender chatChannel("chatData"); // создание канала приема сообщений
    InterActionConsole& UI = InterActionConsole::getInstance();
    greetingAnswers stAnswer = greetingAnswers::NOTANSWER;
    while (stAnswer == NOTANSWER)
    {
        stAnswer = UI.start();
        if (stAnswer == greetingAnswers::REGISTRARION)
        {
            LoginData inputLogin = UI.registration();
            stAnswer = greetingAnswers::LOGIN;
        }
        if (stAnswer == greetingAnswers::LOGIN)
        {   
            
            LoginData inputLogin = UI.login();
            if ((inputLogin.getLogin() == "123") &&
                (inputLogin.getPassword() == "123"))
            {
                std::vector<Message> log = chatChannel.getLog();
                for (Message msg : log)
                {
                    UI.addStrToChat("<TestUser>: " + msg.str);
                }
                UI.enter(inputLogin.getLogin());
                userInput input;
                input = UI.getInput();
                //Основной цикл работы чата
                while (input.type != COMMAND)
                {
                    input = UI.getInput();
                    UI.addStrToChat("<" + inputLogin.getLogin() + ">: "+ input.str );
                    Message sendMsg;
                    sendMsg.type = messageType::ECHO;
                    sendMsg.fromUserId = 2; // Заглушка пока нет пользователей
                    sendMsg.str = input.str;
                    // id = 2;
                    chatChannel.addMessage(sendMsg);    
                }
                if (input.str == "/exit")
                {
                    return;
                }
            }
            else 
            {
                UI.addStrToChat("<System>: Login is not correct. Try agin.");
                stAnswer = greetingAnswers::NOTANSWER; // Если логин не подошел, то снова запрашиваем.
            }
        }
        if (stAnswer == greetingAnswers::EXIT)
        {
            return;
        }
    }
}

AdapterInterAction::~AdapterInterAction() {
}

AdapterInterAction::AdapterInterAction(AdapterInterAction & source) {
}

AdapterInterAction::AdapterInterAction(const AdapterInterAction & source) {
}

AdapterInterAction & AdapterInterAction::operator=(AdapterInterAction & source) {
	return source;
}

AdapterInterAction & AdapterInterAction::operator=(const AdapterInterAction & source) {
	return const_cast<AdapterInterAction &>(source);
}

 ostream & operator<<(ostream & os, const AdapterInterAction & x) {
	 return os;
}

