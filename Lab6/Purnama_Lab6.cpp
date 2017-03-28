//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include<iostream>
#include<vector>

using namespace std;

#include<cstring>

//Leg class specified with 2 getters
// 1 constructor and 1 assignment operator
class Leg{
  const char* const startCity;
  const char* const endCity;
  const int distanceBetween;
  friend class Routes; //giving Routes authorization to access
                       //Leg's private data members

public:
  Leg(const char* const, const char* const, int);
  void outputDistance(ostream&) const;
  int getDistance() const;
  Leg& operator= (const Leg&);
};

class Routes{
  vector<const Leg*> legs; // bag of legs
  const int dist;

public:
  //constructors
  Routes(const Leg&);
  Routes(const Routes&, const Leg&);

  //getters
  int getDistance() const;
  void outputDistance(ostream&) const;

  //operators
  Routes& operator=(const Routes&);
};

int main(){
  // identification output code block
  cout << endl << "Programmer: Albert Putra Purnama" << endl;
  cout << "Programmer's ID: 1559220" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  //legs declaration
  Leg legs[] =
  {
    Leg("San Fransisco", "Sacramento", 90),
    Leg("San Fransisco", "San Jose", 42),
    Leg("San Jose", "Los Angeles", 306),
    Leg("San Jose", "Las Vegas", 382),
    Leg("Sacramento", "Reno", 138),
    Leg("Los Angeles", "Las Vegas", 263),
    Leg("Los Angeles", "Albuquerque", 789),
    Leg("Los Angeles", "Phoenix", 372),
    Leg("Phoenix", "Albuquerque", 421),
    Leg("Las Vegas", "Albuquerque", 573),
    Leg("Las Vegas", "Denver", 754),
    Leg("Las Vegas", "Salt Lake City", 420),
    Leg("Reno", "Salt Lake City", 518),
    Leg("Salt Lake City", "Denver", 519),
    Leg("Albuquerque", "Kansas City", 617),
    Leg("Albuquerque", "Oklahoma City", 541),
    Leg("Albuquerque", "Dallas", 646),
    Leg("Denver", "Kansas City", 395),
    Leg("Oklahoma City", "Kansas City", 347),
    Leg("Kansas City", "Chicago", 510),
    Leg("Kansas City", "St Louis", 249),
    Leg("Oklahoma City", "St Louis", 498),
    Leg("Oklahoma City", "Memphis", 467),
    Leg("Dallas", "Memphis", 451),
    Leg("Memphis", "Louisville", 383),
    Leg("Memphis", "Nashville", 210),
    Leg("Memphis", "Atlanta", 383),
    Leg("St Louis", "Indianapolis", 243),
    Leg("Chicago", "Indianapolis", 183),
    Leg("Chicago", "Detroit", 283),
    Leg("Indianapolis", "Cincinnati", 115),
    Leg("Louisville", "Cincinnati", 100),
    Leg("Nashville", "Charlotte", 409),
    Leg("Atlanta", "Charlotte", 226),
    Leg("Detroit", "Cleveland", 169),
    Leg("Cleveland", "Pittsburgh", 134),
    Leg("Louisville", "Richmond", 563),
    Leg("Cincinnati", "Columbus", 102),
    Leg("Cincinnati", "Cleveland", 217),
    Leg("Columbus", "Pittsburgh", 142),
    Leg("Charlotte", "Richmond", 291),
    Leg("Richmond", "Washington", 109),
    Leg("Pittsburgh", "Washington", 241),
    Leg("Pittsburgh", "Philadelphia", 304),
    Leg("Pittsburgh", "New York", 371),
    Leg("Washington", "Baltimore", 39),
    Leg("Baltimore", "Philadelphia", 105),
    Leg("Philadelphia", "New York", 96),
  };

  //declaring the routes object
  Routes r[] =
  {
    Routes(legs[0]),
    Routes(r[0], legs[4]),
    Routes(r[1], legs[12]),
    Routes(r[2], legs[13]),
    Routes(r[3], legs[17])
  };

  //determining the size of legs
  const int legSize = sizeof(legs)/sizeof(Leg);
  const int routeSize = sizeof(r) / sizeof(Routes);

  for(int i = 0 ; i < routeSize; i++)
  {
    for(int j = i+1; j < routeSize ; j++)
    {
      if(r[i].getDistance() < r[j].getDistance())
      {
        swap(r[i], r[j]);
      }
    }
  }

  cout << "Routes: " << endl;

  for (int k = 0; k < routeSize; k++)
  {
    r[k].outputDistance(cout);
  }

  cout << endl << endl;

  //sorting function code block
  for (int i = 0; i < legSize; i++)
  {
    for (int j = i+1 ; j < legSize; j++)
    {
      if (legs[i].getDistance() > legs[j].getDistance())
      {
        swap(legs[i], legs[j]);
      }
    }
  }

  //outputting to console screen code block
  for (int k = 0; k < legSize; k++)
  {
    legs[k].outputDistance(cout);
  }


  return 0;
}

//constructor
Leg::Leg(const char* const start, const char* const end, int d)
:startCity(start), endCity(end), distanceBetween(d)
{
}

//outputting getter
void Leg::outputDistance(ostream& out) const
{
  out << "Leg: " << startCity << " to " << endCity << ", " << distanceBetween << " miles.\n";
}

//integer getter
int Leg::getDistance() const
{
  return distanceBetween;
}

//assignment operator
Leg& Leg::operator=(const Leg& CopyThis)
{
  Leg& host = *this;
  if (this != &CopyThis)
  {
    const_cast<const char*&>(host.startCity) = CopyThis.startCity;
    const_cast<const char*&>(host.endCity) = CopyThis.endCity;
    const_cast<int&>(host.distanceBetween) = CopyThis.distanceBetween;
  }
  return host;
}

Routes::Routes(const Leg& legObject)
: dist(legObject.distanceBetween)
{
  legs.push_back(&legObject);
}

Routes::Routes(const Routes& route, const Leg& legObject)
:legs(route.legs), dist(route.dist + legObject.distanceBetween)
{
  if(strcmp(legs.back()->endCity, legObject.startCity) != 0) throw;
  legs.push_back(&legObject);
}

int Routes::getDistance() const
{
  return dist;
}


void Routes::outputDistance(ostream& out) const
{
  out << endl << "Routes: " << legs[0]->startCity << " to ";
  for(int i = 0 ; i < legs.size() ; i++)
  {
    if (i < (legs.size() - 1)) out << legs[i]->endCity << " to ";
    else
      out << legs[i]->endCity << ", ";
  }

  out << dist << " miles.";
}

//assignment operator
Routes& Routes::operator=(const Routes& CopyThis)
{
  Routes& host = *this;
  if (this != &CopyThis)
  {
    host.legs = CopyThis.legs;
    const_cast<int&>(host.dist) = CopyThis.dist;
  }
  return host;
}
