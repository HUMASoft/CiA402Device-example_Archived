

#include <iostream>


#include "TestPort.h"
#include "CanBusPort.h"
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
    SocketCanPort p2("can0");
    SocketCanPort p3("can0");

    uint16_t status;


    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(1,&p1);
    CiA402Device j2(2,&p2);
    CiA402Device j3(3,&p3);

    ///Check the status of the device
    //j1.PrintStatus();

    j1.ForceSwitchOff();
    j2.ForceSwitchOff();
    j3.ForceSwitchOff();
    sleep(1);
    j1.PrintStatus();
    j2.PrintStatus();
    j3.PrintStatus();

    return 0;
}
