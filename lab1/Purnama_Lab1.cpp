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

vector<string> parseString(string);
void calcAndOutSQUARE(double);
void calcAndOutRECTANGLE(double, double);
void calcAndOutCIRCLE(double);
void calcAndOutTRIANGLE(double);
void calcAndOutCUBE(double);
void calcAndOutBOX(double, double, double);
void calcAndOutCYLINDER(double, double);

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
      double sides = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutSQUARE(sides); //passing the value of tokens to the function
    }//elseSQUARE

    //RECTANGLE
    else if(tokens[0] == "RECTANGLE")
    {
      //determining the values of dimensions
      double width = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double length = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutRECTANGLE(length, width);
    }//elseRECTANGLE

    //CIRCLE
    else if(tokens[0] == "CIRCLE")
    {
      //determining the values of dimensions
      double rad = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutCIRCLE(rad);
    }//elseCIRCLE

    //TRIANGLE
    else if(tokens[0] == "TRIANGLE")
    {
      //determining the values of dimensions
      double sides = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutTRIANGLE(sides);
    }//elseTRIANGLE

    //CUBE
    else if(tokens[0] == "CUBE")
    {
      //determining the values of dimensions
      double sides = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutCUBE(sides);
    }//elseCUBE

    //BOX
    else if(tokens[0] == "BOX")
    {
      //determining the values of dimensions
      double height = tokens.size() < 4 ? 0 : atof(tokens[3].c_str());
      double width = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double length = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutBOX(length, width, height);
    }//elseBOX

    //CYLINDER
    else if(tokens[0] == "CYLINDER")
    {
      //determining the values of dimensions
      double height = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double rad = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutCYLINDER(rad, height);
    }//elseCYLINDER

    //PRISM
    else if(tokens[0] == "PRISM")
    {
      //determining the values of dimensions
      double sides = tokens.size() < 3 ? 0 : atof(tokens[2].c_str());
      double height = tokens.size() < 2 ? 0 : atof(tokens[1].c_str());
      calcAndOutRECTANGLE(sides, height);
    }//elsePRISM

    else cout << tokens[0] << " invalid object.";

    cout << endl;
  }//while

  fin.close();
}//main

void calcAndOutSQUARE(double s)
{
  // geometry calculation
  double area = s * s;
  double peri = 4 * s;

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file and console screen
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "SQUARE sides=" << s;
  fout.setf(ios::fixed); // setting precision
  fout.precision(2);
  fout << " area=" << area << " perimeter=" << peri << endl;

  cout.unsetf(ios::fixed); // unsetting precision
  cout.precision(6);
  cout << "SQUARE sides=" << s;
  cout.setf(ios::fixed); // setting precision
  cout.precision(2);
  cout << " area=" << area << " perimeter=" << peri;

  fout.close(); //closing the output file
}//SQUARE

void calcAndOutRECTANGLE(double l, double w)
{
  // geometry calculation
  double area = l * w;
  double peri = (2 * l) + (2 * w);

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "RECTANGLE length=" << l << " width=" << w;
  fout.setf(ios::fixed); //setting precision
  fout.precision(2);
  fout << " area=" << area << " perimeter=" << peri << endl;

  //outputting on console screen
  cout.unsetf(ios::fixed); //unsetting precision
  cout.precision(6);
  cout << "RECTANGLE length=" << l << " width=" << w;
  cout.setf(ios::fixed); //setting precision
  cout.precision(2);
  cout << " area=" << area << " perimeter=" << peri;

  fout.close(); //closing the output file
}//RECTANGLE

void calcAndOutCIRCLE(double r)
{
  // geometry calculation
  double area = PI * r * r;
  double peri = PI * 2 * r;

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file and console screen
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "CIRCLE sides=" << r;
  fout.setf(ios::fixed); // setting precision
  fout.precision(2);
  fout << " area=" << area << " perimeter=" << peri << endl;

  cout.unsetf(ios::fixed); // unsetting precision
  cout.precision(6);
  cout << "CIRCLE sides=" << r;
  cout.setf(ios::fixed); // setting precision
  cout.precision(2);
  cout << " area=" << area << " perimeter=" << peri;

  fout.close(); //closing the output file
}//CIRCLE

void calcAndOutTRIANGLE(double s)
{
  // geometry calculation
  double area = (sqrt(3)/4) * s * s;
  double peri = 3 * s;

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file and console screen
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "TRIANGLE sides=" << s;
  fout.setf(ios::fixed); // setting precision
  fout.precision(2);
  fout << " area=" << area << " perimeter=" << peri << endl;

  cout.unsetf(ios::fixed); // unsetting precision
  cout.precision(6);
  cout << "TRIANGLE sides=" << s;
  cout.setf(ios::fixed); // setting precision
  cout.precision(2);
  cout << " area=" << area << " perimeter=" << peri;

  fout.close(); //closing the output file
}//TRIANGLE

void calcAndOutCUBE(double s)
{
  // geometry calculation
  double vol = s * s * s;
  double sa = 6 * s * s;

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "CUBE sides=" << s;
  fout.setf(ios::fixed); // setting precision
  fout.precision(2);
  fout << " surface area=" << sa << " volume=" << vol << endl;

  //outputting to console screen
  cout.unsetf(ios::fixed); // unsetting precision
  cout.precision(6);
  cout << "CUBE sides=" << s;
  cout.setf(ios::fixed); // setting precision
  cout.precision(2);
  cout << " surface area=" << sa << " volume=" << vol;

  fout.close(); //closing the output file
}//cube

void calcAndOutBOX(double l, double w, double h)
{
  // geometry calculation
  double vol = l * w * h;
  double sa = (2 * l * w) + (2 * l * h) + (2 * w * h);

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "BOX length=" << l << " width=" << w << " height=" << h;
  fout.setf(ios::fixed); // setting precision
  fout.precision(2);
  cout << " surface area=" << sa << " volume=" << vol << endl;

  //outputting to console screen
  cout.unsetf(ios::fixed); // unsetting precision
  cout.precision(6);
  cout << "BOX length=" << l << " width=" << w << " height=" << h;
  cout.setf(ios::fixed); // setting precision
  cout.precision(2);
  cout << " surface area=" << sa << " volume=" << vol;

  fout.close(); //closing the output file
}//box

void calcAndOutCYLINDER(double r, double h)
{
  // geometry calculation
  double vol = PI * r * r * h;
  double sa = (2.0 * PI * r * h) + (2.0 * PI * r * r);

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "CYLINDER radius=" << r << " height=" << h;
  fout.setf(ios::fixed); //setting precision
  fout.precision(2);
  fout << " surface area=" << sa << " volume=" << vol << endl;

  //outputting on console screen
  cout.unsetf(ios::fixed); //unsetting precision
  cout.precision(6);
  cout << "CYLINDER radius=" << r << " height=" << h;
  cout.setf(ios::fixed); //setting precision
  cout.precision(2);
  cout << " surface area=" << sa << " volume=" << vol;

  fout.close(); //closing the output file
}//CYLINDER

void calcAndOutPRISM(double s, double h)
{
  // geometry calculation
  double vol = (sqrt(3)/4) * s * s * h;
  double sa = (2* (sqrt(3)/4) * s * s) + (3 * s * h);

  //opening output file
  ofstream fout;
  fout.open("Shapes.output.txt" , ios::out | ios::app);

  //writing on the file
  fout.unsetf(ios::fixed); // unsetting precision
  fout.precision(6);
  fout << "PRISM sides=" << s << " height=" << h;
  fout.setf(ios::fixed); //setting precision
  fout.precision(2);
  fout << " surface area=" << sa << " volume=" << vol << endl;

  //outputting on console screen
  cout.unsetf(ios::fixed); //unsetting precision
  cout.precision(6);
  cout << "PRISM sides=" << s << " height=" << h;
  cout.setf(ios::fixed); //setting precision
  cout.precision(2);
  cout << " surface area=" << sa << " volume=" << vol;

  fout.close(); //closing the output file
}//PRISM

vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin,end);
}//parseString


//this comment is for github purposes

