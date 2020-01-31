

#include <iostream>
#include <math.h>
#include <bitset>

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


    //--Can port communications--
    SocketCanPort pm1("can1");

    CiA402SetupData sd1(2*2048,3.7,0.001, 1.1); //max amp 10.1


    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(31,&pm1, &sd1);

    ///Check the status of the device
    j1.PrintStatus();


    j1.Reset();
    j1.PrintStatus();

    j1.SwitchOn();
    j1.PrintStatus();


  j1.SetupPositionMode(1,1);

  j1.SetPosition(1);


return 0;

}
