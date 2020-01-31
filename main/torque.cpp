


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
    SocketCanPort p1("can1");

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(32,&p1);

    ///Check the status of the device
//    j1.PrintStatus();
//    ///Start the node (allow sdo, pdo)
//    j1.StartNode();
//    ///Change the state machine to switched on
//    j1.SwitchOn();
    ///Set torque operation mode
    ///
    cout<<"!"<<endl;
    j1.Setup_Torque_Mode();
    ///Set torque
    ///

    j1.SetTorque(0.005);
    ///Check the status of the device
    j1.PrintStatus();
    sleep(1);
//    j1.SetTorque(0);


    return 0;
}

