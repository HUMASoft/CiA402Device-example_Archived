

#include <iostream>
#include <math.h>

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
    //CanBusPort port;
    SocketCanPort p1("can0");
    SocketCanPort p2("can0");

    uint16_t status;

    ///Then instantiate a 301 communications object for that address
    //CiA301CommPort coms(port.getPortFileDescriptor());

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device m1(2,&p1);

    CiA402Device j2(2,&p2);


    //m1.Setup_Velocity_Mode(0,360);

     double old = 0;
     double nueva = m1.GetPosition();
     double pv =0;
     double dts=0.01;
double vel=2.5;
double err=0,serr=0;


m1.Setup_Torque_Mode();
//m1.SetVelocity(15);

for (int i=0;i<500;i++)
{
    old=nueva;
    usleep(dts*1000000);


    nueva=m1.GetPosition();
    pv= ((nueva-old)/dts)*60/360;
    cout<<"pv en rpm";
    cout<<pv<<" , ";
    cout<<m1.GetVelocity()<<endl;
    cout<<"pos actual en rpm"<<nueva<<endl;

    err = (vel-pv);
    serr = err + serr;

    m1.SetTorque(5*serr+3*err);

    cout<<"Torque: " << (serr+err) <<endl;


}
    //j2.PrintStatus();




    m1.SetTorque(00);



    return 0;

}
