/*
	Модуль\класс канала связи между пользователями или посылки сообщений
 */

#include "Channel.h"

template <typename StateType>
Channel<StateType>::Channel(Channel<StateType> & source) {
}

template <typename StateType>
Channel<StateType>::Channel(const Channel<StateType> & source) {
}

template <typename StateType>
Channel<StateType> & Channel<StateType>::operator=(Channel<StateType> & source) {
	return source;
}

template <typename StateType>
Channel<StateType> & Channel<StateType>::operator=(const Channel<StateType> & source) {
	return const_cast<Channel<StateType> &>(source);
}

template <typename StateType>
 ostream & operator<<(ostream & os, const Channel<StateType> & x) {
	 return os;
}

