
#include "EchoUser.h"
#include "Users.h"
#include "Messages.h"

EchoUser::EchoUser() {
}

EchoUser::EchoUser(Channel<Users> *_userSendReceive)
    : userSendReceive(_userSendReceive) {

}

EchoUser::~EchoUser() {
    delete userSendReceive;
}

EchoUser::EchoUser(EchoUser & source) {
}

EchoUser::EchoUser(const EchoUser & source) {
    
}

EchoUser & EchoUser::operator=(EchoUser & source) {
    return source;
}

EchoUser & EchoUser::operator=(const EchoUser & source) {
    return const_cast<EchoUser&>(source);
}

 ostream & operator<<(ostream & os, const EchoUser & x) {
    return os;
}

bool EchoUser::hasPacket() {
        return true;
}

void EchoUser::sendPacket() {
    /*
    if (hasPacket()) {
        Messages msg;
        msg.setMsg("User message was received ...");
//        userSendReceive->attach(handleStateChange, "stateHandle");
        Users users = userSendReceive->getState();
        users.setMsg(msg);
        userSendReceive->setState(users);
//        userSendReceive->detach("stateHandle");
    }
    */
}

