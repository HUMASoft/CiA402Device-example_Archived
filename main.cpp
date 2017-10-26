

#include <iostream>


#include "TestPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"

using namespace std;

int main(int argc, char *argv[])
{


    TestPort port;
    CiA301CommPort coms(port.getPortFileDescriptor());


    CiA402Device j1;
//    j1.SetCommunications(&coms);

    cout << od::controlword[1] << "  --> " << sizeof(od::controlword) / sizeof(od::controlword[0]) << endl;
    vector<unsigned char> message();


    return 0;
}
