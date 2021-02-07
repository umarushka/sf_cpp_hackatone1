/*
	Модуль\класс посылки сообщения
 */

#include "Sender.h"

Sender::Sender() {
    someSender = new Subject<Users>();
    sS = new Channel<Users>();
}

Sender::~Sender() {
    delete someSender;
    delete sS;
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
    cout << msg << endl;
    Users users = someSender->getState();
    users.setMsg(msg);
    someSender->setState(users);
    return false;
}

Subject<Users> *Sender::getSomeSender() const {
    return someSender;
}

void Sender::setSomeSender(Subject<Users> *someSender) {
    Sender::someSender = someSender;
}

