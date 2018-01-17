

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
    SocketCanPort p1("can0");

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(6,&p1);

    ///Check the status of the device
    j1.PrintStatus();
    j1.StartNode();
    j1.PrintStatus();
    j1.SwitchOn();
    j1.PrintStatus();
    j1.OperationMode(od::positionmode);
    j1.PrintStatus();



    return 0;
}
