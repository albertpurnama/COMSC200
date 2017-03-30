//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include "Rider.h"

#include<iostream>
using namespace std;

Rider::Rider(int a, int b)
:to(b), from(a)
{
}

Rider& Rider::operator=(const Rider& r)
{
  Rider& host = *this;
  if (this != &r)
  {
    host.from = r.from;
    host.to = r.to;
  }

  return host;
}
