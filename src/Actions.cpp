/*
	Модуль\класс действий пользователя
 */

#include "Actions.h"

Actions::Actions() {
}

Actions::~Actions() {
}

Actions::Actions(Actions & source) {
}

Actions::Actions(const Actions & source) {
}

Actions & Actions::operator=(Actions & source) {
	return source;
}

Actions & Actions::operator=(const Actions & source) {
	return const_cast<Actions &>(source);
}

 ostream & operator<<(ostream & os, const Actions & x) {
	 return os;
}

