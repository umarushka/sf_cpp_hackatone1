/*
	Модуль\класс адаптера к интерфейсу пользователя
 */

#include "AdapterInterAction.h"

AdapterInterAction::AdapterInterAction() {
}

AdapterInterAction::~AdapterInterAction() {
}

AdapterInterAction::AdapterInterAction(AdapterInterAction & source) {
}

AdapterInterAction::AdapterInterAction(const AdapterInterAction & source) {
}

AdapterInterAction & AdapterInterAction::operator=(AdapterInterAction & source) {
	return source;
}

AdapterInterAction & AdapterInterAction::operator=(const AdapterInterAction & source) {
	return const_cast<AdapterInterAction &>(source);
}

 ostream & operator<<(ostream & os, const AdapterInterAction & x) {
	 return os;
}

