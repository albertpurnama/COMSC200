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

struct Square
{
  double sides;
};
void calcAndOutSQUARE(ostream&, const Square&);

struct Rectangle
{
  double length;
  double width;
};
void calcAndOutRECTANGLE(ostream&, const Rectangle&);

struct Circle
{
  double radius;
};
void calcAndOutCIRCLE(ostream&, const Circle&);

struct Triangle
{
  double sides;
};
void calcAndOutTRIANGLE(ostream&, const Triangle&);

struct Cube
{
  double sides;
};
void calcAndOutCUBE(ostream&, const Cube&);

struct Box
{
  double length;
  double width;
  double height;
};
void calcAndOutBOX(ostream&, const Box&);

struct Cylinder
{
  double radius;
  double height;
};
void calcAndOutCYLINDER(ostream&, const Cylinder&);

struct Prism
{
  double sides;
  double height;
};
void calcAndOutPRISM(ostream&, const Prism&);

vector<string> parseString(string);

const double PI = atan(1.0) * 4; // global CONSTANT!

int main()
{
  // identification output code block
  cout << endl << "Programmer: Albert Putra Purnama" << endl;
  cout << "Programmer's ID: 1559220" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  string finput; //buffer

  //opening input file
  ifstream fin;
  fin.open("Shapes.input.txt");

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt");

  //creating the bag
  vector<void*> myBag;
  vector<char> myBagType; // companion array for tracking

  while (fin.good())
  {
    //getting input from file and testing input files
    getline(fin, finput);
    vector<string> tokens = parseString(finput); //parsing input file

    //checking inputs
    if(tokens.size() == 0) continue; //continue if blank line

    if(tokens[0] == "EOF") break; //break if it is the end of file

    //SQUARE
    else if(tokens[0] == "SQUARE")
    {
      //determining the values of dimensions
      double side = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Square* s1 = new Square;
      s1->sides = side;
      myBag.push_back(s1);
      myBagType.push_back('S');
    }//elseSQUARE

    //RECTANGLE
    else if(tokens[0] == "RECTANGLE")
    {
      //determining the values of dimensions
      double width = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double length = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Rectangle* rect = new Rectangle;
      rect->width = width;
      rect->length = length;
      myBag.push_back(rect);
      myBagType.push_back('R');
    }//elseRECTANGLE

    //CIRCLE
    else if(tokens[0] == "CIRCLE")
    {
      //determining the values of dimensions
      double rad = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      Circle* circ = new Circle;
      circ->radius = rad;
      myBag.push_back(circ);
      myBagType.push_back('C');
    }//CIRCLE

    //TRIANGLE
    else if(tokens[0] == "TRIANGLE")
    {
      //determining the values of dimensions
      double side = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Triangle* tri = new Triangle;
      tri->sides = side;
      myBag.push_back(tri);
      myBagType.push_back('T');
    }//TRIANGLE

    //CUBE
    else if(tokens[0] == "CUBE")
    {
      //determining the values of dimensions
      double side = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Cube* cub = new Cube;
      cub->sides = side;
      myBag.push_back(cub);
      myBagType.push_back('1');
    }//elseCUBE

    //BOX
    else if(tokens[0] == "BOX")
    {
      //determining the values of dimensions
      double height = tokens.size() < 4 ? 0 : atof(tokens[3].c_str());
      double width = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double length = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Box* boxx = new Box;
      boxx->length = length;
      boxx->width = width;
      boxx->height = height;
      myBag.push_back(boxx);
      myBagType.push_back('B');
    }//elseBOX

    //CYLINDER
    else if(tokens[0] == "CYLINDER")
    {
      //determining the values of dimensions
      double height = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double rad = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Cylinder* Cyl = new Cylinder;
      Cyl->radius = rad;
      Cyl->height = height;
      myBag.push_back(Cyl);
      myBagType.push_back('2'); // here we are using
    }//elseCYLINDER

    //PRISM
    else if(tokens[0] == "PRISM")
    {
      //determining the values of dimensions
      double sides = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double height = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());

      //creating the object and adding it to the bag
      Prism* pris = new Prism;
      pris->sides = sides;
      pris->height = height;
      myBag.push_back(pris);
      myBagType.push_back('P');
    }//elsePRISM

    else cout << tokens[0] <<" Invalid object.\n";
  }//while

  for(unsigned int i = 0 ; i < myBag.size() ; i++)
  {
    if(myBagType[i] == 'S')
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      calcAndOutSQUARE(cout , *pSquare);
    }
    else if(myBagType[i] == 'R')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      calcAndOutRECTANGLE(cout , *pRectangle);
    }
    else if(myBagType[i] == 'C')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      calcAndOutCIRCLE(cout , *pCircle);
    }
    else if(myBagType[i] == 'T')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      calcAndOutTRIANGLE(cout , *pTriangle);
    }
    else if(myBagType[i] == '1')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
      calcAndOutCUBE(cout , *pCube);
    }
    else if(myBagType[i] == 'B')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      calcAndOutBOX(cout , *pBox);
    }
    else if(myBagType[i] == '2')
    {
      Cylinder* pCyl = reinterpret_cast<Cylinder*>(myBag[i]);
      calcAndOutCYLINDER(cout , *pCyl);
    }
    else if(myBagType[i] == 'P')
    {
      Prism* pPris = reinterpret_cast<Prism*>(myBag[i]);
      calcAndOutPRISM(cout , *pPris);
    }
  }

  for(unsigned int j = 0 ; j < myBag.size() ; j++)
  {

    if(myBagType[j] == 'S')
    {
      Square* psquare = reinterpret_cast<Square*>(myBag[j]);
      calcAndOutSQUARE(fout , *psquare);
    }
    else if(myBagType[j] == 'R')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[j]);
      calcAndOutRECTANGLE(fout , *pRectangle);
    }
    else if(myBagType[j] == 'C')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[j]);
      calcAndOutCIRCLE(fout , *pCircle);
    }
    else if(myBagType[j] == 'T')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[j]);
      calcAndOutTRIANGLE(fout , *pTriangle);
    }
    else if(myBagType[j] == '1')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[j]);
      calcAndOutCUBE(fout , *pCube);
    }
    else if(myBagType[j] == 'B')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[j]);
      calcAndOutBOX(fout , *pBox);
    }
    else if(myBagType[j] == '2')
    {
      Cylinder* pCyl = reinterpret_cast<Cylinder*>(myBag[j]);
      calcAndOutCYLINDER(cout , *pCyl);
    }
    else if(myBagType[j] == 'P')
    {
      Prism* pPris = reinterpret_cast<Prism*>(myBag[j]);
      calcAndOutPRISM(cout , *pPris);
    }
  }

  for(unsigned int j = 0 ; j < myBag.size() ; j++)
  {

    if(myBagType[j] == 'S')
    {
      Square* psquare = reinterpret_cast<Square*>(myBag[j]);
      delete psquare;
    }
    else if(myBagType[j] == 'R')
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[j]);
      delete pRectangle;
    }
    else if(myBagType[j] == 'C')
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[j]);
      delete pCircle;
    }
    else if(myBagType[j] == 'T')
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[j]);
      delete pTriangle;
    }
    else if(myBagType[j] == '1')
    {
      Cube* pCube = reinterpret_cast<Cube*>(myBag[j]);
      delete pCube;
    }
    else if(myBagType[j] == 'B')
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[j]);
      delete pBox;
    }
    else if(myBagType[j] == '2')
    {
      Cylinder* pCyl = reinterpret_cast<Cylinder*>(myBag[j]);
      delete pCyl;
    }
    else if(myBagType[j] == 'P')
    {
      Prism* pPris = reinterpret_cast<Prism*>(myBag[j]);
      delete pPris;
    }
  }

  fin.close();
  fout.close();
}//main

void calcAndOutSQUARE(ostream& out, const Square& s)
{
  // geometry calculation
  double area = s.sides * s.sides;
  double peri = 4 * s.sides;

  //writing on the file and console screen
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "SQUARE sides=" << s.sides;
  out.setf(ios::fixed); // setting precision
  out.precision(2);
  out << " area=" << area << " perimeter=" << peri << endl;
}//SQUARE

void calcAndOutRECTANGLE(ostream& out, const Rectangle& r)
{
  // geometry calculation
  double area = r.length * r.width;
  double peri = (2 * r.length) + (2 * r.width);

  //writing on the file
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "RECTANGLE length=" << r.length << " width=" << r.width;
  out.setf(ios::fixed); //setting precision
  out.precision(2);
  out << " area=" << area << " perimeter=" << peri << endl;
}//RECTANGLE

void calcAndOutCIRCLE(ostream& out, const Circle& c)
{
  // geometry calculation
  double area = PI * c.radius * c.radius;
  double peri = PI * 2 * c.radius;

  //writing on the file and console screen
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "CIRCLE sides=" << c.radius;
  out.setf(ios::fixed); // setting precision
  out.precision(2);
  out << " area=" << area << " perimeter=" << peri << endl;
}//CIRCLE

void calcAndOutTRIANGLE(ostream& out, const Triangle& t)
{
  // geometry calculation
  double area = (sqrt(3)/4) * t.sides * t.sides;
  double peri = 3 * t.sides;

  //writing on the file and console screen
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "TRIANGLE sides=" << t.sides;
  out.setf(ios::fixed); // setting precision
  out.precision(2);
  out << " area=" << area << " perimeter=" << peri << endl;
}//TRIANGLE

void calcAndOutCUBE(ostream& out, const Cube& c)
{
  // geometry calculation
  double vol = c.sides * c.sides * c.sides;
  double sa = 6 * c.sides* c.sides;

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "CUBE sides=" << c.sides;
  out.setf(ios::fixed); // setting precision
  out.precision(2);
  out << " surface area=" << sa << " volume=" << vol << endl;
}//cube

void calcAndOutBOX(ostream& out, const Box& b)
{
  // geometry calculation
  double vol = b.length * b.width * b.height;
  double sa = (2 * b.length * b.width) + (2 * b.length * b.height) + (2 * b.width * b.height);

  //writing on the file and console screen
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "BOX length=" << b.length << " width=" << b.width << " height=" << b.height;
  out.setf(ios::fixed); // setting precision
  out.precision(2);
  out << " surface area=" << sa << " volume=" << vol << endl;
}//box

void calcAndOutCYLINDER(ostream& out, const Cylinder& c)
{
  // geometry calculation
  double vol = PI * c.radius * c.radius * c.height;
  double sa = (2.0 * PI * c.radius * c.height) + (2.0 * PI * c.radius * c.radius);

  //writing on the file and console screen
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "CYLINDER radius=" << c.radius << " height=" << c.height;
  out.setf(ios::fixed); //setting precision
  out.precision(2);
  out << " surface area=" << sa << " volume=" << vol << endl;
}//CYLINDER

void calcAndOutPRISM(ostream& out, const Prism& p)
{
  // geometry calculation
  double vol = (sqrt(3)/4) * p.sides * p.sides * p.height;
  double sa = (2* (sqrt(3)/4) * p.sides * p.sides) + (3 * p.sides * p.height);

  //writing on the file and console screen
  out.unsetf(ios::fixed); // unsetting precision
  out.precision(6);
  out << "PRISM sides=" << p.sides << " height=" << p.height;
  out.setf(ios::fixed); //setting precision
  out.precision(2);
  out << " surface area=" << sa << " volume=" << vol << endl;
}

vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin,end);
}//parseString


