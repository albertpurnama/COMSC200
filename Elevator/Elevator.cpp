//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include "Elevator.h"
#include "Panel.h"
#include "Building.h"
#include "Floor.h"

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start)
:atFloorIndex(-1), speed(speed), CAPACITY(capacity)
{
  location = Building::floors[start];

  for(int i = 0; i < Building::FLOORS; i++)
  {
    panel.addButton(Building::floors[i].label);
  }

  direction = IDLE;
  timer = 0;
}

ostream& operator<<(ostream& out, const Elevator& e)
{
  out << "Elevator at " << setw(3) << int(e);

  if(e.goingUp()) out << setw(11) << "going UP";
  else if(e.goingDown()) out << setw(11) << "going DOWN";
  else out << setw(11) << "IDLE";

  out << setw(3) << e.getNumberOfRiders() << " Riders";

  //setting timer and outputting it below

  if(e.isOpen())
  {
    out << setw(16) << " door is OPEN |" << e.timer;
  }
  else
  {
    out << setw(15);
    out << " ";
  }
  //next, the output the panel which is empty now
  out << e.panel;

  return out;
}

void Elevator::openDoorTo(int thisFloor)
{
  //this function is for opening door and clearing the specific button on the floor.
  panel.clear(Building::floors[thisFloor].label);
  atFloorIndex = thisFloor;
  resetTimer(); //resetting timer allowing riders to show up and baord
}

void Elevator::board(const Rider& r)
{
  riders.push_back(r);
  panel.press(Building::floors[r.to].label);

  if(r.to > r.from) direction = Elevator::UP;
  else direction = Elevator::DOWN;

  resetTimer(); //resetting timer allowing riders to show up and board
}
