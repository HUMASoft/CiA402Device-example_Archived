#include <iostream>


#include "TestPort.h"
#include "CanBusPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"

using namespace std;

int main(int argc, char *argv[])
{
 CanBusPort port;
 CiA402Device j1(22,port.getPortId());
// j1.OperationMode(od::positionmode);
// sleep(1);
// j1.FlushBuffer();
 //j1.SwitchOn();
 j1.PrintStatus();










    return 0;
}
