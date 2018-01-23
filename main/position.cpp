

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
  j1.SetupPositionMode(360,100000); //(Max velocity in degrees/s, acceleration)
  //sleep(2);

  ///new positions here!!
  uint32_t posdegree=0; //Write the position in degrees here
 j1.SetPosition(j1.DegreeConv(posdegree));
//   j1.SetPosition(4092);


   j1.FlushBuffer();
   //sleep(2);
   j1.PrintStatus();
   sleep(1+posdegree/360);
   double pos = j1.GetPosition()*360/(4*1024);
    cout<< "actual pos: " << pos << " [deg]" <<endl;





    return 0;

}
