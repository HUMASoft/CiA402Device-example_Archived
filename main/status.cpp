

#include <iostream>


#include "TestPort.h"
//#include "CanBusPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"
#include "SocketCanPort.h"

using namespace std;

int main(int argc, char *argv[])
{


    ///prepare ports
    /// Open a port address with a PortBase Object
    //TestPort port;
    //CanBusPort port("/dev/can0");//("/dev/can0")
    SocketCanPort p1("can0");
    uint16_t status;

    ///Then instantiate a 301 communications object for that address
    //CiA301CommPort coms(port.getPortFileDescriptor());

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(2,&p1);

    ///Check the status of the device
    j1.PrintStatus();



    return 0;
}
