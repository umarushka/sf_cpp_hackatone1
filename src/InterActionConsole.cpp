/*
	Модуль\класс интерфейса пользователя
 */

#include "InterActionConsole.h"

InterActionConsole::InterActionConsole() {
}

InterActionConsole::~InterActionConsole() {
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

 ostream & operator<<(ostream & os, const InterActionConsole & x) {
	 return os;
}

