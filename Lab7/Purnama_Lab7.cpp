//Programmer: Albert Putra Purnama
//Student ID: 1559220

#include<iostream>
#include<vector>
#include<string>
#include<set>
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
  friend class ShortestRoute;

public:
  Leg(const char* const, const char* const, int);
  void outputDistance(ostream&) const;
  int getDistance() const;
  Leg& operator= (const Leg&);
};

class Routes{
  vector<const Leg*> legs; // bag of legs
  const int dist;
  friend class ShortestRoute;

public:
  //constructors
  Routes(const Leg&);
  Routes(const Routes&, const Leg&);

  //getters
  int getDistance() const;
  void outputDistance(ostream&) const;

  //operators
  Routes& operator=(const Routes&);
  friend bool operator<(const Routes&, const Routes&);
};

class ShortestRoute
{
  public:
  //leg declaration
  static const Leg legs[];
  static Routes anyRoute(const char* const, const char* const);
  static const Routes shortestRoute(const char* const, const char* const);
};

const Leg ShortestRoute::legs[] =
{
  Leg("Denver", "Kansas City", 395),
  Leg("Philadelphia", "New York", 96),
  Leg("Oklahoma City", "Kansas City", 347),
  Leg("San Jose", "Las Vegas", 382),
  Leg("San Fransisco", "San Jose", 42),
  Leg("San Jose", "Los Angeles", 306),
  Leg("Albuquerque", "Dallas", 646),
  Leg("Pittsburgh", "New York", 371),
  Leg("Los Angeles", "Phoenix", 372),
  Leg("Phoenix", "Albuquerque", 421),
  Leg("Las Vegas", "Albuquerque", 573),
  Leg("Sacramento", "Reno", 138),
  Leg("Memphis", "Atlanta", 383),
  Leg("Albuquerque", "Kansas City", 617),
  Leg("Albuquerque", "Oklahoma City", 541),
  Leg("Oklahoma City", "St Louis", 498),
  Leg("Cincinnati", "Columbus", 102),
  Leg("Cincinnati", "Cleveland", 217),
  Leg("Oklahoma City", "Memphis", 467),
  Leg("Dallas", "Memphis", 451),
  Leg("Richmond", "Washington", 109),
  Leg("Chicago", "Indianapolis", 183),
  Leg("Indianapolis", "Cincinnati", 115),
  Leg("Los Angeles", "Las Vegas", 263),
  Leg("Los Angeles", "Albuquerque", 789),
  Leg("Louisville", "Cincinnati", 100),
  Leg("St Louis", "Indianapolis", 243),
  Leg("Washington", "Baltimore", 39),
  Leg("Baltimore", "Philadelphia", 105),
  Leg("Las Vegas", "Denver", 754),
  Leg("Las Vegas", "Salt Lake City", 420),
  Leg("Reno", "Salt Lake City", 518),
  Leg("Salt Lake City", "Denver", 519),
  Leg("Kansas City", "Chicago", 510),
  Leg("Memphis", "Louisville", 383),
  Leg("San Fransisco", "Sacramento", 90),
  Leg("Memphis", "Nashville", 210),
  Leg("Kansas City", "St Louis", 249),
  Leg("Nashville", "Charlotte", 409),
  Leg("Atlanta", "Charlotte", 226),
  Leg("Detroit", "Cleveland", 169),
  Leg("Cleveland", "Pittsburgh", 134),
  Leg("Louisville", "Richmond", 563),
  Leg("Pittsburgh", "Washington", 241),
  Leg("Pittsburgh", "Philadelphia", 304),
  Leg("Chicago", "Detroit", 283),
  Leg("Columbus", "Pittsburgh", 142),
  Leg("Charlotte", "Richmond", 291),
  Leg("San Fransisco", "New York", 21000) // new SuperHighway
};

int main(){
  // identification output code block
  cout << endl << "Programmer: Albert Putra Purnama" << endl;
  cout << "Programmer's ID: 1559220" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  const Routes route1 = ShortestRoute::anyRoute("San Fransisco", "New York");
  route1.outputDistance(cout);

  const Routes route2 = ShortestRoute::shortestRoute("San Fransisco", "New York");
  route2.outputDistance(cout);

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

bool operator<(const Routes& a, const Routes& b)
{
  return a.dist < b.dist;
}

Routes ShortestRoute::anyRoute(const char* const start, const char* const finish) {
  int SIZE = sizeof(ShortestRoute::legs)/sizeof(ShortestRoute::legs[0]);

  //for loop to search for all possible routes
  for (int i = 0; i < SIZE; i++)
  {
    if (strcmp(ShortestRoute::legs[i].endCity, finish) == 0)
    {
      if (strcmp(ShortestRoute::legs[i].startCity, start) == 0)
      {
        Routes x(legs[i]);
        return x;
      }
      else
      {
        Routes y(ShortestRoute::anyRoute(start, ShortestRoute::legs[i].startCity),legs[i]);
        return y;
      }//if
    }//if
  }//for

  throw "Not linked!"; //exception
}

const Routes ShortestRoute::shortestRoute(const char* const start, const char* const finish)
{
  int SIZE = sizeof(ShortestRoute::legs)/sizeof(ShortestRoute::legs[0]);
  set<Routes> r;
  bool Match = 0;

  //for loop to search for all possible routes
  for (int j = 0; j < SIZE; j++)
  {
    for (int i = 0; i < SIZE; i++)
    {
      if (strcmp(ShortestRoute::legs[i].endCity, finish) == 0)
      {
        if (strcmp(ShortestRoute::legs[i].startCity, start) == 0)
        {
          Routes x(ShortestRoute::legs[i]);
          r.insert(x);
          Match = true;
        }
        else
        {
          Routes y(ShortestRoute::anyRoute(start, ShortestRoute::legs[i].startCity), ShortestRoute::legs[i]);
          r.insert(y);
          Match = true;
        }//else
      }//if
    }//for
  }//for
  if(Match != true) throw "Not linked"; // throw exception
  else return *(r.begin());
}
