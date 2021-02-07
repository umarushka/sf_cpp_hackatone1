/*
	Модуль\класс интерфейса пользователя
 */

#include "InterActionConsole.h"

InterActionConsole::InterActionConsole() :
    _userName("User")
{
    // Формируем пустое окно чата заполняя его пробелами и добавляя рамку на краях
    _data = new std::string[_chatStrQuantity]{};
    for(int i = 0; i < _chatStrQuantity; ++i)
    {
        _data[i].insert(0, 1, static_cast<char>(179));
        for (int j = 0; j < _dataStrLength - 2; ++j) // - 2 для символов | на краях рамки
        {
            _data[i].push_back(' ');
        }
        _data[i].push_back(static_cast<char>(179));
    }
}

InterActionConsole::~InterActionConsole()
{
    delete[] _data;
}

void InterActionConsole::drawChatFrameTop()
{
    std::string chFrameTopLine{};
    chFrameTopLine.push_back(static_cast<char>(218));
    chFrameTopLine.push_back(static_cast<char>(196));
    chFrameTopLine.append("Chat");
    for (int i = 0; i < _dataStrLength - 7; ++i) // -5 под слово Chat и учитывая и еще - 2 для символов | на краях рамки
    {
        chFrameTopLine.push_back(static_cast<char>(196));
    }
    chFrameTopLine.push_back(static_cast<char>(191));
    std::cout << chFrameTopLine << std::endl;
}

void InterActionConsole::addMessageToChat(std::string message) // тут скорре всего будут исключения типа out_of_range
{
    // сообщение разбиваем на строки
    while ( static_cast<int>(message.length()) / (_dataStrLength - 2) > 0)  // - 2 для символов | на краях рамки
    {
        for (int i = 0; i < _chatStrQuantity - 1; ++i) // все строки до этого сдвигаем
        {
            _data[i] = _data[i+1];
        }
        // std::string chFrameLine{};
        _data[_chatStrQuantity - 1].erase();
        _data[_chatStrQuantity - 1].insert(0, 1, static_cast<char>(179));
        _data[_chatStrQuantity - 1].append(message.substr(0, _dataStrLength - 2));
        message.erase(0, _dataStrLength - 2);
        _data[_chatStrQuantity - 1].push_back(static_cast<char>(179));
    }
    if (message.length() > 0) // Добавляем остаток строки и заполняем пустое место пробелами
    {
        for (int i = 0; i < _chatStrQuantity - 1; ++i) // все строки до этого сдвигаем
        {
            _data[i] = _data[i+1];
        }
        _data[_chatStrQuantity - 1].erase();
        _data[_chatStrQuantity - 1].insert(0, 1, static_cast<char>(179));
        _data[_chatStrQuantity - 1].append(message);
        for(int j = message.length(); j < _dataStrLength - 2; ++j )
        {
            _data[_chatStrQuantity - 1].push_back(' ');
        }
        _data[_chatStrQuantity - 1].push_back(static_cast<char>(179));

    }
    // отрисовка
    system("cls");
    drawChatFrameTop();
    for (int i = 0; i < _chatStrQuantity; ++i)
    {
        std::cout << _data[i] << std::endl;
    }
    drawChatFrameBottom();
}

void InterActionConsole::drawChatFrameBottom()
{
    std::string chFrameBottomLine{};
    chFrameBottomLine.push_back(static_cast<char>(192));
    for (int i = 0; i < _dataStrLength - 2; ++i) // - 2 для символов | на краях рамки
    {
        chFrameBottomLine.push_back(static_cast<char>(196));
    }
    chFrameBottomLine.push_back(static_cast<char>(217));
    std::cout << chFrameBottomLine << std::endl;
    std::cout << "<" << _userName << ">: ";
}


greetingAnswers InterActionConsole::start()
{
    char answer{};
    greetingAnswers retAnswer = NOTANSWER;
    addMessageToChat("CHAT FOR DEVELOPERS DEMO Version 0.1");
    addMessageToChat("Created By: ");
    addMessageToChat("1. Login");
    addMessageToChat("2. Registration");
    addMessageToChat("3. Exit");
    addMessageToChat("<System>: Enter Your Choice :=> ");
    std::cin >> answer;
    if (answer == '1')
    {
        addMessageToChat("<System>: You select Login ");
        retAnswer = LOGIN;
    }
    else if (answer == '2')
    {
        std::cout << "<System>: You select Registration ";
        retAnswer = REGISTRARION;
    }
    else if (answer == '3')
    {
        std::cout << "<System>: You select Exit ";
        retAnswer = EXIT;
    }
    else
    {
        addMessageToChat(" ");
        addMessageToChat(" ");
        std::cout << "<System>: You select its not valid ";
    }
    return retAnswer;
}

LoginData InterActionConsole::login()
{
    std::string answer{};
    LoginData data;
    addMessageToChat("<System>: Enter Your Login :=> ");
    std::cin >> answer;
    while(!data.setLogin(answer))
    {
        addMessageToChat("<System>: Login is not correct, input only English letters or numbers.");
        addMessageToChat("<System>: Repeat enter Your Login :=> ");
        std::cin >> answer;
    }
    addMessageToChat("<System>: Enter Your Password :=> ");
    std::cin >> answer;
    while(!data.setPassword(answer))
    {
        addMessageToChat("<System>: Password is not correct, input only English letters or numbers.");
        addMessageToChat("<System>: Repeat enter Your Password :=> ");
        std::cin >> answer;
    }
    return data;
}

void InterActionConsole::enter(std::string userName)
{
    _userName = userName;
    addMessageToChat("<System>: Welcom to the chat.");
}

userInput InterActionConsole::getInput()
{
    userInput getedInput;
    std::getline(std::cin, getedInput.str);
    if (getedInput.str[0] == '/')
    {
        getedInput.type = InputType::COMMAND;
    }
    else if (getedInput.str[0] == '@')
    {
        getedInput.type = InputType::PRIVATE_MESSAGE;
    }
    else
    {
        getedInput.type = InputType::ECHO_MESSAGE;
    }
    return getedInput;
}

InterActionConsole::InterActionConsole(InterActionConsole & source) {
}

InterActionConsole::InterActionConsole(const InterActionConsole & source) {
}

InterActionConsole & InterActionConsole::operator=(InterActionConsole & source) {
	return source;
}

InterActionConsole & InterActionConsole::operator=(const InterActionConsole & source) {
	return const_cast<InterActionConsole &>(source);
}

 std::ostream & operator<<(std::ostream & os, const InterActionConsole & x) {
	 return os;
}

