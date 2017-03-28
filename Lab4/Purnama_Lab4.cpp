//Programmer: Albert Putra Purnama
//Student ID: 1559220

// C++ library code block
#include<fstream>
#include<iostream>
#include<iterator>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// C library code block
#include<cstdlib>
#include<cmath>

//the following are the struct definitions
class Square
{
  const double sides;

public:
  Square(const vector<string>&);
  void calcAndOutSQUARE(ostream&) const;
  Square& operator=(const Square&);
};

class Rectangle
{
  const double length;
  const double width;

public:
  Rectangle(const vector<string>&);
  void calcAndOutRECTANGLE(ostream&) const;
  Rectangle& operator=(const Rectangle&);
};

class Circle
{
  const double radius;

public:
  Circle(const vector<string>&); //setter
  void calcAndOutCIRCLE(ostream&) const; //getter
  Circle& operator=(const Circle&);
};

class Triangle
{
  const double sides;

public:
  Triangle(const vector<string>&); //setter
  void calcAndOutTRIANGLE(ostream&) const; //getter
  Triangle& operator=(const Triangle&);
};

class Cube
{
  const double sides;

public:
  Cube(const vector<string>&); //setter
  void calcAndOutCUBE(ostream&) const; //getter
  Cube& operator=(const Cube&);
};

class Box
{
  const double length;
  const double width;
  const double height;

public:
  Box(const vector<string>&); //setter
  void calcAndOutBOX(ostream&) const; //getter
  Box& operator=(const Box&);
};

class Cylinder
{
  const double radius;
  const double height;

public:
  Cylinder(const vector<string>&); //setter
  void calcAndOutCYLINDER(ostream&) const; //getter
  Cylinder& operator=(const Cylinder&);
};

class Prism
{
  const double sides;
  const double height;

public:
  Prism(const vector<string>&); //setter
  void calcAndOutPRISM(ostream&) const; //getter
  Prism& operator=(const Prism&);
};

const vector<string> parseString(string);
ostream& roundingOn(ostream&);
ostream& roundingOff(ostream&);

const double PI = atan(1.0) * 4; // global CONSTANT!

int main()
{
  // identification output code block
  cout << endl << "Programmer: Albert Putra Purnama" << endl;
  cout << "Programmer's ID: 1559220" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  string finput;

  //opening input file
  ifstream fin;
  fin.open("Shapes.input.txt");

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt");

  //creating the bag
  vector<const void*> myBag;
  vector<char> myBagType; // companion array for tracking

  while (fin.good())
  {
    //getting input from file and testing input files
    getline(fin, finput);
    const vector<string> tokens = parseString(finput); //parsing input file

    //checking inputs
    if(tokens.size() == 0) continue; //continue if blank line

    if(tokens[0] == "EOF") break; //break if it is the end of file

    //SQUARE
    else if(tokens[0] == "SQUARE")
    {
      //creating the object and adding it to the bag
      const Square* const s1 = new Square(tokens);
      myBag.push_back(s1);
      myBagType.push_back('1');
    }//elseSQUARE

    //RECTANGLE
    else if(tokens[0] == "RECTANGLE")
    {
      //creating the object and adding it to the bag
      const Rectangle* const rect = new Rectangle(tokens);
      myBag.push_back(rect);
      myBagType.push_back('2');
    }//elseRECTANGLE

    //CIRCLE
    else if(tokens[0] == "CIRCLE")
    {
      //creating the object and adding it to the bag
      const Circle* const circ = new Circle(tokens);
      myBag.push_back(circ);
      myBagType.push_back('5');
    }//CIRCLE

    //TRIANGLE
    else if(tokens[0] == "TRIANGLE")
    {
      //creating the object and adding it to the bag
      const Triangle* const tri = new Triangle(tokens);
      myBag.push_back(tri);
      myBagType.push_back('7');
    }//TRIANGLE

    //CUBE
    else if(tokens[0] == "CUBE")
    {
      //creating the object and adding it to the bag
      const Cube* const cub = new Cube(tokens);
      myBag.push_back(cub);
      myBagType.push_back('3'); // since there are duplicate 'c' I use integers for the other c's
    }//elseCUBE

    //BOX
    else if(tokens[0] == "BOX")
    {
      //creating the object and adding it to the bag
      const Box* const boxx = new Box(tokens);
      myBag.push_back(boxx);
      myBagType.push_back('4');
    }//elseBOX

    //CYLINDER
    else if(tokens[0] == "CYLINDER")
    {
      //creating the object and adding it to the bag
      const Cylinder* const Cyl = new Cylinder(tokens);
      myBag.push_back(Cyl);
      myBagType.push_back('6');// since there are duplicate 'c' I use integers for the other c's
    }//elseCYLINDER

    //PRISM
    else if(tokens[0] == "PRISM")
    {
      //creating the object and adding it to the bag
      const Prism* const pris = new Prism(tokens);
      myBag.push_back(pris);
      myBagType.push_back('8');
    }//elsePRISM

    else cout << tokens[0] << " Invalid Object.\n";
  }//while

  fin.close();

  //sorting the bag based on types.
  for (int i = 0; i < myBag.size(); i++)
  {
    for (int j = i + 1; j < myBag.size(); j++)
    {
      if (myBagType[j] < myBagType[i])
        {
          swap(myBag[i], myBag[j]);
          swap(myBagType[i], myBagType[j]);
        }
    }
  }


  for(unsigned int i = 0 ; i < myBag.size() ; i++)
  {
    //the following conditionals are for determining the type of objects
    //and calculating the data members then output it to the console output
    if(myBagType[i] == '1')
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      (*pSquare).calcAndOutSQUARE(cout);
    }
    else if(myBagType[i] == '2')
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      (*pRectangle).calcAndOutRECTANGLE(cout);
    }
    else if(myBagType[i] == '5')
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      (*pCircle).calcAndOutCIRCLE(cout);
    }
    else if(myBagType[i] == '7')
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      (*pTriangle).calcAndOutTRIANGLE(cout);
    }
    else if(myBagType[i] == '3')
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
      (*pCube).calcAndOutCUBE(cout);
    }
    else if(myBagType[i] == '4')
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      (*pBox).calcAndOutBOX(cout);
    }
    else if(myBagType[i] == '6')
    {
      const Cylinder* const pCyl = reinterpret_cast<const Cylinder*>(myBag[i]);
      (*pCyl).calcAndOutCYLINDER(cout);
    }
    else if(myBagType[i] == '8')
    {
      const Prism* const pPris = reinterpret_cast<const Prism*>(myBag[i]);
      (*pPris).calcAndOutPRISM(cout);
    }
  }//for

  for(unsigned int j = 0 ; j < myBag.size() ; j++)
  {
    //the following conditionals are for determining the type of objects
    //and calculating the data members then output it to the file
    if(myBagType[j] == '1')
    {
      const Square* const psquare = reinterpret_cast<const Square*>(myBag[j]);
      (*psquare).calcAndOutSQUARE(fout);
    }
    else if(myBagType[j] == '2')
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[j]);
      (*pRectangle).calcAndOutRECTANGLE(fout);
    }
    else if(myBagType[j] == '5')
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[j]);
      (*pCircle).calcAndOutCIRCLE(fout);
    }
    else if(myBagType[j] == '7')
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[j]);
      (*pTriangle).calcAndOutTRIANGLE(fout);
    }
    else if(myBagType[j] == '3')
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[j]);
      (*pCube).calcAndOutCUBE(fout);
    }
    else if(myBagType[j] == '4')
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[j]);
      (*pBox).calcAndOutBOX(fout);
    }
    else if(myBagType[j] == '6')
    {
      const Cylinder* const pCyl = reinterpret_cast<const Cylinder*>(myBag[j]);
      (*pCyl).calcAndOutCYLINDER(fout);
    }
    else if(myBagType[j] == '8')
    {
      const Prism* const pPris = reinterpret_cast<const Prism*>(myBag[j]);
      (*pPris).calcAndOutPRISM(fout);
    }
  }//for

  for(unsigned int j = 0 ; j < myBag.size() ; j++)
  {

    if(myBagType[j] == '1')
    {
      const Square* const psquare = reinterpret_cast<const Square*>(myBag[j]);
      delete psquare;
    }
    else if(myBagType[j] == '2')
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[j]);
      delete pRectangle;
    }
    else if(myBagType[j] == '5')
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[j]);
      delete pCircle;
    }
    else if(myBagType[j] == '7')
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[j]);
      delete pTriangle;
    }
    else if(myBagType[j] == '2')
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[j]);
      delete pCube;
    }
    else if(myBagType[j] == '3')
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[j]);
      delete pBox;
    }
    else if(myBagType[j] == '6')
    {
      const Cylinder* const pCyl = reinterpret_cast<const Cylinder*>(myBag[j]);
      delete pCyl;
    }
    else if(myBagType[j] == '8')
    {
      const Prism* const pPris = reinterpret_cast<const Prism*>(myBag[j]);
      delete pPris;
    }
  }//for

  fout.close();
}//main

ostream& roundingOn(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

Square& Square::operator=(const Square& copyThis)
{
  Square& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.sides) = copyThis.sides;
  }
  return host;
}

Rectangle& Rectangle::operator=(const Rectangle& copyThis)
{
  Rectangle& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host;
}

Circle& Circle::operator=(const Circle& copyThis)
{
  Circle& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host;
}

Triangle& Triangle::operator=(const Triangle& copyThis)
{
  Triangle& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.sides) = copyThis.sides;
  }
  return host;
}

Cube& Cube::operator=(const Cube& copyThis)
{
  Cube& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.sides) = copyThis.sides;
  }
  return host;
}

Box& Box::operator=(const Box& copyThis)
{
  Box& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis)
{
  Cylinder& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

Prism& Prism::operator=(const Prism& copyThis)
{
  Prism& host = *this;
  if (this != &copyThis)
  {
    const_cast<double&>(host.sides) = copyThis.sides;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

Square::Square(const vector<string>& tokens)
:sides(tokens.size() < 2 ? 0 : atof(tokens[1].c_str())) //determining the values of dimensions
{
}

Rectangle::Rectangle(const vector<string>& tokens)
:length(tokens.size() < 2 ? 0 : atof(tokens[1].c_str())),
 width(tokens.size() < 3 ? 0 : atof(tokens[2].c_str()))//determining the values of dimensions
{
}

Circle::Circle(const vector<string>& tokens)
:radius(tokens.size() < 2 ? 0 : atof(tokens[1].c_str())) //initializer list
{
}

Triangle::Triangle(const vector<string>& tokens)
:sides(tokens.size() < 2 ? 0 : atof(tokens[1].c_str()))//determining the values of dimensions initializer list
{
}

Cube::Cube(const vector<string>& tokens)
:sides(tokens.size() < 2 ? 0 : atof(tokens[1].c_str()))
{
}

Box::Box(const vector<string>& tokens)
:height(tokens.size() < 4 ? 0 : atof(tokens[3].c_str())),
width(tokens.size() < 3 ? 0 : atof(tokens[2].c_str())),
length(tokens.size() < 2 ? 0 : atof(tokens[1].c_str()))//determining the values of dimensions
{
}

Cylinder::Cylinder(const vector<string>& tokens)
:height(tokens.size() < 3 ? 0 : atof(tokens[2].c_str())),
radius(tokens.size() < 2 ? 0 : atof(tokens[1].c_str()))//determining the values of dimensions
{
}

Prism::Prism(const vector<string>& tokens)
:height(tokens.size() < 3 ? 0 : atof(tokens[2].c_str())),
sides(tokens.size() < 2 ? 0 : atof(tokens[1].c_str()))//determining the values of dimensions
{
}

void Square::calcAndOutSQUARE(ostream& out) const
{
  // geometry calculation
  double area = sides * sides;
  double peri = 4 * sides;

  //writing on the file and console screen
  out << roundingOff << "SQUARE sides=" << sides;
  out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//SQUARE

void Rectangle::calcAndOutRECTANGLE(ostream& out) const
{
  // geometry calculation
  double area = length * width;
  double peri = (2 * length) + (2 * width);

  //writing on the file
  out << roundingOff << "RECTANGLE length=" << length << " width=" << width;
  out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//RECTANGLE

void Circle::calcAndOutCIRCLE(ostream& out) const
{
  // geometry calculation
  double area = PI * radius * radius;
  double peri = PI * 2 * radius;

  //writing on the file and console screen
  out << roundingOff << "CIRCLE sides=" << radius;
  out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//CIRCLE

void Triangle::calcAndOutTRIANGLE(ostream& out) const
{
  // geometry calculation
  double area = (sqrt(3)/4) * sides * sides;
  double peri = 3 * sides;

  //writing on the file and console screen
  out << roundingOff << "TRIANGLE sides=" << sides;
  out << roundingOn << " area=" << area << " perimeter=" << peri << endl;
}//TRIANGLE

void Cube::calcAndOutCUBE(ostream& out) const
{
  // geometry calculation
  double vol = sides * sides * sides;
  double sa = 6 * sides* sides;

  //writing on the file
  out << roundingOff << "CUBE sides=" << sides;
  out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}//cube

void Box::calcAndOutBOX(ostream& out) const
{
  // geometry calculation
  double vol = length * width * height;
  double sa = (2 * length * width) + (2 * length * height) + (2 * width * height);

  //writing on the file and console screen
  out << roundingOff << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}//box

void Cylinder::calcAndOutCYLINDER(ostream& out) const
{
  // geometry calculation
  double vol = PI * radius * radius * height;
  double sa = (2.0 * PI * radius * height) + (2.0 * PI * radius * radius);

  //writing on the file and console screen
  out << roundingOff << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}//CYLINDER

void Prism::calcAndOutPRISM(ostream& out) const
{
  // geometry calculation
  double vol = (sqrt(3)/4) * sides * sides * height;
  double sa = (2* (sqrt(3)/4) * sides * sides) + (3 * sides * height);

  //writing on the file and console screen
  out << roundingOff << "PRISM sides=" << sides << " height=" << height;
  out << roundingOn << " surface area=" << sa << " volume=" << vol << endl;
}

const vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin,end);
}//parseString


