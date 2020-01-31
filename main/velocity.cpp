

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
    j1.PrintStatus();
    ///Start the node (allow sdo, pdo)
//    j1.StartNode();
//    ///Change the state machine to switched on
//    j1.SwitchOn();
//    ///Set velocity operation mode
    j1.OperationMode(od::velocitymode);
    ///Set velocity
    j1.SetVelocity(0.05);
    ///Check the status of the device
    j1.PrintStatus();
    double old = 0;
    double nueva = j1.GetPosition();
    double pv =0;
    double dts=0.01;
    double vel=60,actvel=0;
    double err=0,serr=0;
    while(true){
        old=nueva;
        usleep(dts*1000000);

        nueva=j1.GetPosition();
        pv= ((nueva-old)/dts)*60/360;
        actvel=j1.GetVelocity()-2;
        cout<<"pv en rpm: ";
        cout<<pv<<" , "<<actvel<<endl;
        cout<<"pos actual"<<nueva<<endl;
        sleep(1);

    }


    SocketCanPort p2("can0");

 CiA402Device j2(1,&p2);
 //j2.PrintStatus();


    return 0;
}

