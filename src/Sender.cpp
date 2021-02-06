/*
	Модуль\класс посылки сообщения
 */

#include "Sender.h"

Sender::Sender() {
}

Sender::~Sender() {
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
    return false;
}

