/*
	Модуль\класс работы с пользователем
 */

#include "Users.h"

/*Users::Users(string name,int id,int level): _name(name), _id(id), _level(level) {
}

Users::~Users() {
}

void Users::setnickname(string nickname) {
	_nickname = nickname;
}

string Users::getnickname() {
	return _nickname;
}

void Users::setpassword(string password) {
	_password = password;
}

string Users::getpassword() {
	return _password;
}

void Users::setrating(double rating) {
	_rating = rating;
}

double Users::getrating() {
	return _rating;
}


Users::Users(Users & source) {
	this->_nickname = source._nickname;
	this->_password = source._password;
	this->_rating = source._rating;
}

/*Users::Users(const Users & source) {
}

Users & Users::operator=(Users & source) {
	return source;
}

Users & Users::operator=(const Users & source) {
	return const_cast<Users &>(source);
}

 ostream & operator<<(ostream & os, const Users & x) {
	 return os;
}*/

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

