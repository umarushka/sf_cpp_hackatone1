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

void InterActionConsole::addStrToChat(std::string message) // тут скорре всего будут исключения типа out_of_range
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
    std::string answer{};
    greetingAnswers retAnswer = NOTANSWER;
    addStrToChat("CHAT FOR DEVELOPERS DEMO Version 0.1");
    addStrToChat("Created By: ");
    addStrToChat("1. Login");
    addStrToChat("2. Registration");
    addStrToChat("3. Exit");
    addStrToChat("<System>: Enter Your Choice :=> ");
    std::getline(std::cin, answer);
    if (answer[0] == '1')
    {
        addStrToChat("<System>: You select Login.");
        retAnswer = LOGIN;
    }
    else if (answer[0] == '2')
    {
        addStrToChat("<System>: You select Registration.");
        retAnswer = REGISTRARION;
    }
    else if (answer[0] == '3')
    {
        addStrToChat("<System>: You select Exit.");
        retAnswer = EXIT;
    }
    else
    {
        addStrToChat("<System>: You select its not valid.");
    }
    return retAnswer;
}

LoginData InterActionConsole::login()
{
    std::string answer{};
    LoginData data;
    addStrToChat("<System>: Enter Your Login :=> ");
    std::cin >> answer;
    while(!data.setLogin(answer))
    {
        addStrToChat("<System>: Login is not correct, input only English letters or numbers.");
        addStrToChat("<System>: Repeat enter Your Login :=> ");
        std::cin >> answer;
    }
    addStrToChat("<System>: Enter Your Password :=> ");
    std::cin >> answer;
    while(!data.setPassword(answer))
    {
        addStrToChat("<System>: Password is not correct, input only English letters or numbers.");
        addStrToChat("<System>: Repeat enter Your Password :=> ");
        std::cin >> answer;
    }
    return data;
}

LoginData InterActionConsole::registration()
{
    std::string answer{};
    std::string rAnswer{ ":" }; // строка для записи повторного ввода пароля, инициализиуерся символом который не может быть в ответе, для дальнешего сравнения
    LoginData data;
    addStrToChat("<System>: Enter new Login :=> ");
    std::cin >> answer;
    while (!data.setLogin(answer))
    {
        addStrToChat("<System>: Login is not correct, input only English letters or numbers.");
        addStrToChat("<System>: Repeat enter Your Login :=> ");
        std::cin >> answer;
    }
    while (answer != rAnswer)
    {
        addStrToChat("<System>: Enter new Password :=> ");
        std::cin >> answer;
        while (!data.setPassword(answer))
        {
            addStrToChat("<System>: Password is not correct, input only English letters or numbers.");
            addStrToChat("<System>: Repeat enter Your Password :=> ");
            std::cin >> answer;
        }
        addStrToChat("<System>: ReEnter new Password :=> ");
        std::cin >> rAnswer;
        if (answer != rAnswer)
        {
            addStrToChat("<System>: Passwords do not match. ");
        }
    }
    addStrToChat("<System>: Registration completed. ");
    return data;
}

void InterActionConsole::enter(std::string userName)
{
    _userName = userName;
    addStrToChat("<System>: Welcom to the chat.");
}

userInput InterActionConsole::getInput()
{
    userInput getedInput;
    std::getline(std::cin, getedInput.str);
    if (getedInput.str[0] == '/')
    {
        getedInput.type = messageType::COMMAND;
    }
    else if (getedInput.str[0] == '@')
    {
        getedInput.type = messageType::PRIVATE;
    }
    else
    {
        getedInput.type = messageType::ECHO;
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

