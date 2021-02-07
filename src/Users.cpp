/*
	Модуль\класс работы с пользователем
 */

#include "Users.h"

Users::Users() {}

Users::Users(string name, int id, int level): _nickname(name), _id(id), _rating(level) {
}

Users::~Users() {
}

Users::Users(Users & source) {
	this->_nickname = source._nickname;
	this->_password = source._password;
	this->_rating = source._rating;
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

int Users::getId() const {
    return _id;
}

void Users::setId(int id) {
    Users::_id = id;
}

const Messages &Users::getMsg() const {
    return msg;
}

void Users::setMsg(const Messages &msg) {
    Users::msg = msg;
}

const string &Users::getNickname() const {
    return _nickname;
}

void Users::setNickname(const string &nickname) {
    _nickname = nickname;
}

const string &Users::getPassword() const {
    return _password;
}

void Users::setPassword(const string &password) {
    _password = password;
}

double Users::getRating() const {
    return _rating;
}

void Users::setRating(double rating) {
    _rating = rating;
}

