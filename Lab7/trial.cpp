//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include<iostream>
#include<vector>
#include<string>

using namespace std;

#include<cstring>

class Leg{
  const char* const startCity;
  const char* const endCity;
  const int distanceBetween;
  friend class Routes; //giving Routes authorization to access
                       //Leg's private data members
  friend class ShortestRoute;

public:
  Leg(const char* const, const char* const, int);
  void outputDistance(ostream&) const;
  int getDistance() const;
  Leg& operator= (const Leg&);
};

class phi
{
  const double PIPI = 3.14;
};

struct Math
{
  static const double PI;
  static const Leg legs[];
};

const Leg math::legs[]
{

}
const double Math::PI = 3.14;


int main(){
  // identification output code block
  cout << endl << "Programmer: Albert Putra Purnama" << endl;
  cout << "Programmer's ID: 1559220" << endl;
  cout << "File: " << __FILE__ << endl << endl;


  return 0;
}
