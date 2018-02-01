

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
    uint16_t status;

    ///Then instantiate a 301 communications object for that address
    //CiA301CommPort coms(port.getPortFileDescriptor());

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(6,&p1);

    ///Check the status of the device
//    j1.PrintStatus();
//    //j1.SwitchOn();
//   cout<<j1.GetPosition()<<endl;
//   j1.FlushBuffer();
//   //cout<<posicion<<endl;

// La máxima velocidad es 0x00599999 degrees/s, con 0x00600000 deg/s satura
   // comprobar pequeño error



  j1.Setup_Velocity_Mode(360,360); //(Max velocity in degrees/s, acceleration)
  //sleep(2);

  j1.FlushBuffer();

  //uint32_t posdegree=0; //Write the position in degrees here
 j1.SetVelocity(6);//[rad/s]



   //sleep(2);
   j1.PrintStatus();
   //Sleep(1+posdegree/360);
//   double pos = j1.GetPosition();
//      cout<< "actual pos: " << pos << " [deg]" <<endl;

//   sleep(1);
//   double vel = j1.GetVelocity();
//      cout<< "actual vel: " << vel << " [deg/s]" <<endl;





    return 0;

}
