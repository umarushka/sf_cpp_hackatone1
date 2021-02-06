/*
	ћодуль\класс формировани¤ сообщений пользовател¤
 */

#include "Messages.h"

Messages::Messages() {
}

Messages::~Messages() {
}

Messages::Messages(Messages & source) {
}

Messages::Messages(const Messages & source) {
}

Messages & Messages::operator=(Messages & source) {
	return source;
}

Messages & Messages::operator=(const Messages & source) {
	return const_cast<Messages &>(source);
}

 ostream & operator<<(ostream & os, const Messages & x) {
	 return os;
}

