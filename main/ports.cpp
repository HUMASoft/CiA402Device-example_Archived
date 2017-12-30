

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
    //TestPort port;
    SocketCanPort port("vcan0");
    std::vector<uint8_t> data={0x55};


    port.PutMsg(0x123,data.data(),data.size());



    return 0;
}
