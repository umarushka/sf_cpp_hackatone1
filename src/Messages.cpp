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

bool Messages::operator==(Messages & source) {
    return this->msg == source.getMsg();
}

Messages & Messages::operator=(const Messages & source) {
	return const_cast<Messages &>(source);
}

 ostream & operator<<(ostream & os, const Messages & x) {
	 os << x.msg.c_str();
	 return os;
}

const string &Messages::getMsg() const {
    return msg;
}

void Messages::setMsg(const string &msg) {
    this->msg = msg;
}

string &Messages::getMsg() {
    return msg;
}
