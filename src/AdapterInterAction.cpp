#include "AdapterInterAction.h"

#include "Messages.h"

AdapterInterAction::AdapterInterAction(InterActionConsole& UI, Sender& chatChannel, UsersDBMapping& usersMapper) :
    _UI(UI), _chatChannel(chatChannel), _usersMapper(usersMapper)
{  
}

void AdapterInterAction::run()
{
    _usersMapper.readUsersData();
    std::vector<User> usersData = _usersMapper.getUsersData();
    greetingAnswers stAnswer = greetingAnswers::NOTANSWER;
    while (stAnswer == NOTANSWER)
    {
        stAnswer = _UI.start();
        if (stAnswer == greetingAnswers::REGISTRARION)
        {
            LoginData inputLogin = _UI.registration();
            stAnswer = greetingAnswers::LOGIN;
        }
        if (stAnswer == greetingAnswers::LOGIN)
        {
            LoginData inputLogin = _UI.login();
            int loginedId = _usersMapper.findUser(inputLogin.getLogin());
            if ((loginedId != -1) && (inputLogin.getPassword() == _usersMapper.getUserPassFromId(loginedId)))
            {
                std::vector<Message> log = _chatChannel.getLog();
                for (Message msg : log)
                {
                    _UI.addStrToChat("<" + _usersMapper.getUserNickNameFromId(msg.fromUserId) + ">: " + msg.str);
                }
                _UI.enter(inputLogin.getLogin());
                userInput input;
                input = _UI.getInput();
                //Основной цикл работы чата
                while (input.type != COMMAND)
                {
                    input = _UI.getInput();
                    _UI.addStrToChat("<" + inputLogin.getLogin() + ">: " + input.str);
                    Message sendMsg;
                    sendMsg.type = messageType::ECHO;
                    sendMsg.fromUserId = loginedId;
                    sendMsg.str = input.str;
                    _chatChannel.addMessage(sendMsg);
                }
                if (input.str == "/exit")
                {
                    return;
                }
            }
            else
            {
                _UI.addStrToChat("<System>: Login is not correct. Try agin.");
                stAnswer = greetingAnswers::NOTANSWER; // Если логин не подошел, то снова запрашиваем.
            }
        }
        if (stAnswer == greetingAnswers::EXIT)
        {
            return;
        }
    }
}

