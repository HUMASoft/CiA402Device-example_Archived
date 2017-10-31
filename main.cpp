

#include <iostream>


#include "TestPort.h"
#include "CanBusPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"

using namespace std;

int main(int argc, char *argv[])
{


    //TestPort port;
    CanBusPort port;
    CiA301CommPort coms(port.getPortFileDescriptor());


    CiA402Device j1(2);
    j1.SetCommunications(&coms);


    j1.CheckStatus();
    //j1.Start();



    return 0;
}
