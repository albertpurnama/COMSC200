//Programmer: Albert Putra Purnama
//Student ID: 1559220

#ifndef Rider_h
#define Rider_h

#include<iostream>
using namespace std;

#include<cstring>

struct Rider
{
  int to;
  int from;
  Rider(int, int);
  Rider& operator=(const Rider&);

public:
  const bool goingUp;
  const bool goingDown;
};

#endif
