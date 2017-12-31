

#include <iostream>


#include "TestPort.h"
#include "CanBusPort.h"
#include "SocketCanPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"

using namespace std;

int main(int argc, char *argv[])
{


    ///prepare ports
    /// Open a port address with a PortBase Object
    SocketCanPort port("vcan0");

    can_frame m1;

    m1.can_id=0x123;
    m1.can_dlc=1;
    m1.data[0]=0x55;

    port.PutMsg(m1.can_id,m1.data,m1.can_dlc);
    port.GetMsg(m1.can_id,m1.data,m1.can_dlc);



    return 0;
}
