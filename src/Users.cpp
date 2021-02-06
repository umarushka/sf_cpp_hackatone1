/*
	Модуль\класс работы с пользователем
 */

#include "Users.h"

Users::Users() {
}

Users::~Users() {
}

Users::Users(Users & source) {
}

Users::Users(const Users & source) {
}

Users & Users::operator=(Users & source) {
	return source;
}

Users & Users::operator=(const Users & source) {
	return const_cast<Users &>(source);
}

 ostream & operator<<(ostream & os, const Users & x) {
	 return os;
}

