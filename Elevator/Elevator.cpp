//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include "Elevator.h"
#include "Panel.h"

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start)
:atFloorIndex(start), speed(speed), CAPACITY(capacity)
{
  direction = IDLE;
  timer = 0;
}

ostream& operator<<(ostream& out, const Elevator& e)
{
  out << "Elevator at " << setw(3) << int(e);

  if(e.goingUp()) out << setw(10) << "going UP ";
  else if(e.goingDown()) out << setw(10) << "going DOWN ";
  else out << setw(10) << "IDLE";

  out << setw(3) << e.getNumberOfRiders() << " Riders";

  //setting timer and outputting it below
  out << setw(14);

  //next, the output the panel which is empty now
  out << e.panel;

  return out;
}
