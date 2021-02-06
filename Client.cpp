#include "Actions.h"
#include "AdapterInterAction.h"
#include "Channel.h"
#include "InterActionConsole.h"
#include "Messages.h"
#include "Receiver.h"
#include "Sender.h"
#include "Users.h"

int main()
{
	Sender sn;
	Messages msg;
	Receiver rc;

	msg.setMsg("Message for receive ...");
    sn.send(msg);
	cout << msg << endl;
	cout << rc.receive() << endl;
	cout << "Client running ..." << endl;
	getchar();
	return 0;	
}