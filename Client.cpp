#include "Messages.h"
#include "Sender.h"
#include "Channel.h"
#include "Users.h"
#include "EchoUser.h"

void handleStateChange(const Users& newState)
{
    cout << "State changed to: " << newState.getNickname() << endl;
}

int main()
{
    Messages msg;
    msg.setMsg("Message for receive ...");

    Users users;

    users.setId(1);
    users.setNickname("User");
    users.setPassword("");
    users.setRating(10);
    users.setMsg(msg);

    Channel<Users> *channel = new Channel<Users>(users);
    Sender *sn = new Sender(channel);
    EchoUser *echo = new EchoUser(channel);

    channel->attach(handleStateChange, "stateHandle");
    channel->setState(users);

	cout << "Client running ..." << endl;
	getchar();
	return 0;	
}
