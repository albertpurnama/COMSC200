//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include "Rider.h"
#include "Building.h"

#include<iostream>
using namespace std;

Rider::Rider(int a, int b)
:to(b), from(a), goingUp(Building::floors[to] > Building::floors[from]), goingDown(Building::floors[to] < Building::floors[from])
{
}

Rider& Rider::operator=(const Rider& r)
{
  Rider& host = *this;
  if (this != &r)
  {
    host.from = r.from;
    host.to = r.to;
    const_cast<bool&>(host.goingDown) = r.goingDown;
    const_cast<bool&>(host.goingUp) = r.goingUp;
  }

  return host;
}
