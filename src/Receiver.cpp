/*
	Модуль\класс приёма сообщения
 */

#include "Receiver.h"

Receiver::Receiver() {
    msg = new Messages();
}

Receiver::~Receiver() {
    delete msg;
}

Receiver::Receiver(Receiver & source) {
}

Receiver::Receiver(const Receiver & source) {
}

Receiver & Receiver::operator=(Receiver & source) {
	return source;
}

Receiver & Receiver::operator=(const Receiver & source) {
	return const_cast<Receiver &>(source);
}

 ostream & operator<<(ostream & os, const Receiver & x) {
	 return os;
}

Messages &Receiver::receive() {
    msg->setMsg("Message to receive ...");
    return *msg;
}

