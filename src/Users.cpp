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

const string &Users::getName() const {
    return name;
}

void Users::setName(const string &name) {
    Users::name = name;
}

int Users::getId() const {
    return id;
}

void Users::setId(int id) {
    Users::id = id;
}

int Users::getLevel() const {
    return level;
}

void Users::setLevel(int level) {
    Users::level = level;
}

const Messages &Users::getMsg() const {
    return msg;
}

void Users::setMsg(const Messages &msg) {
    Users::msg = msg;
}

