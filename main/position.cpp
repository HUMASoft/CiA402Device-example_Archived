

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
    //TestPort port;
    //CanBusPort port;
    SocketCanPort p1("can0");
    uint16_t status;

    ///Then instantiate a 301 communications object for that address
    //CiA301CommPort coms(port.getPortFileDescriptor());

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(1,&p1);

    ///Check the status of the device
    j1.PrintStatus();


    j1.Reset();
    j1.PrintStatus();

    j1.SwitchOn();
    j1.PrintStatus();

////   cout<<j1.GetPosition()<<endl;
////   j1.FlushBuffer();
////   //cout<<posicion<<endl;
// // j1.SetupPositionMode(360*0.47,360); //(Max velocity in degrees/s, acceleration)
//  //sleep(2);
    //j1.Setup_Velocity_Mode(0,360);
//  j1.SetupPositionMode(360,360);
//  ///new positions here!!
  //uint32_t posdegree=120; //Write the position in degrees here
  //j1.SetPosition(posdegree);
    j1.Setup_Torque_Mode();
    j1.SetTorque(300);
//int x=-127;
//uint32_t y=(uint8_t)x;
//cout<<"---------- "<<y<<endl;

//   j1.FlushBuffer();
//   //sleep(2);
//   j1.PrintStatus();
//   sleep(1+posdegree/360);
//   double pos = j1.GetPosition();
//     cout<< "actual pos: " << pos << " [deg]" <<endl;
//j1.SetVelocity(30);

//   sleep(1);
//    double vel=0;
//    int x=0;
//    //for (x=0;x<150;x++){
//        vel = j1.GetVelocity()+vel;
//   // }
//    //vel=vel/150;
//    cout<< "actual vel: " << vel << " [deg]" <<endl;


//int8_t a = -5;
//std::bitset<8> x(a);

//std::cout << x;

return 0;

}
