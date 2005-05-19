
#include "OSDMonitor.h"

#include "msg/Message.h"
#include "messages/MPing.h"

#include "common/Timer.h"
#include "common/Clock.h"

/* to send a message,

Message *messageptr = ......;
mds->messenger->send_message(messageptr,
                             MSG_ADDR_OSD(osdnum), 0, MSG_PORT_OSDMON);


timer example:

class C_Test : public Context {
public:
  void finish(int r) {
	cout << "C_Test->finish(" << r << ")" << endl;
  }
};

g_timer.add_event_after(10, new C_Test);

*/


void OSDMonitor::proc_message(Message *m)
{
  switch (m->get_type()) {
  case MSG_PING:
	handle_ping((MPing*)m);
	break;
  }
}


void OSDMonitor::handle_ping(MPing *m)
{

}


