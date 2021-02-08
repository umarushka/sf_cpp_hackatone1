/*
	Модуль\класс адаптера к интерфейсу пользователя
 */

#include "AdapterInterAction.h"
#include "InterActionConsole.h"

AdapterInterAction::AdapterInterAction()
{
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
            if ((inputLogin.getLogin() == "Test") &&
                (inputLogin.getPassword() == "123"))
            {
                UI.enter(inputLogin.getLogin());
                userInput input = UI.getInput();
                while (input.type != COMMAND)
                {
                    UI.addMessageToChat("<" + inputLogin.getLogin() + ">" + input.str);
                    input = UI.getInput();
                }
                if (input.str == "/exit")
                {
                    return;
                }
            }
            else 
            {
                UI.addMessageToChat("<System>: Login is not correct. Try agin.");
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

