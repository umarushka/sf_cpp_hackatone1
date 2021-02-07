/*
	Модуль\класс посылки сообщения
 */

#include "Sender.h"

Sender::Sender() {
}

Sender::Sender(Channel<Users> *_someSender) : someSender(_someSender) {
}

Sender::~Sender() {
    delete someSender;
}

Sender::Sender(Sender & source) {
}

Sender::Sender(const Sender & source) {
}

Sender & Sender::operator=(Sender & source) {
	return source;
}

Sender & Sender::operator=(const Sender & source) {
	return const_cast<Sender &>(source);
}

 ostream & operator<<(ostream & os, const Sender & x) {
    os << x;
	 return os;
}

bool Sender::send(Messages &msg) {
    Users users = someSender->getState();
    users.setMsg(msg);
    someSender->setState(users);
    return false;
}

Channel<Users> *Sender::getSomeSender() const {
    return someSender;
}

void Sender::setSomeSender(Channel<Users> *someSender) {
    Sender::someSender = someSender;
}

