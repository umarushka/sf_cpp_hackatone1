/*
	Модуль\класс канала связи между пользователями или посылки сообщений
 */

#include "Channel.h"

Channel::Channel() {
}

Channel::~Channel() {
}

Channel::Channel(Channel & source) {
}

Channel::Channel(const Channel & source) {
}

Channel & Channel::operator=(Channel & source) {
	return source;
}

Channel & Channel::operator=(const Channel & source) {
	return const_cast<Channel &>(source);
}

 ostream & operator<<(ostream & os, const Channel & x) {
	 return os;
}

