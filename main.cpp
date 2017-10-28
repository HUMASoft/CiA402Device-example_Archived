

#include <iostream>


#include "TestPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"

using namespace std;

int main(int argc, char *argv[])
{


    TestPort port;
    CiA301CommPort coms(port.getPortFileDescriptor());


    CiA402Device j1(2);
    j1.SetCommunications(&coms);


    j1.CheckStatus();



    return 0;
}
