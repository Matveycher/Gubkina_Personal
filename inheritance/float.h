#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>

/*
ЧЕРНЫХ МАТВЕЙ
Написать программу, в которой описана иерархия классов: геометрические фигуры (куб, конус, тетраэдр).
 Реализовать методы вычисления объема и площади поверхности фигуры.
Продемонстрировать работу всех методов классов, предоставив пользователю выбор типа фигуры для демонстрации.
*/

using namespace std;

class Shape
{
protected:
   float h = 0;
   float r = 0;
   float a = 0;
   float S = 0;
   float V = 0;
};

class Cube : public Shape
{
   friend std::ostream &operator<<(std::ostream &out, Cube &shape);
   friend std::istream &operator>>(std::istream &in, Cube &shape);

public:
   Cube()
   {
      cout << "Do you want to enter the parameters of the cube? (y/n) ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         cin >> *this;
      }
      else
      {
         setCubeRandom();
      }
      calcS();
      calcV();
   }

private:
   void calcS()
   {
      S = 6 * h * h;
   }
   void calcV()
   {
      V = h * h * h;
   };
   void setCubeRandom()
   {
      h = rand() % 100 + 1;
   }
};

class Cone : public Shape
{
   friend std::ostream &operator<<(std::ostream &out, Cone &shape);
   friend std::istream &operator>>(std::istream &in, Cone &shape);

public:
   Cone()
   {
      cout << "Do you want to enter the parameters of the cone? (y/n) ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         cout << "Enter the height, then enter the radius of the cone: ";
         cin >> *this;
      }
      else
      {
         setConeRandom();
      }
      calcS();
      calcV();
   }
   friend std::ostream &operator<<(std::ostream &out, Cone &shape);
   friend std::istream &operator>>(std::istream &in, Cone &shape);

private:
   void calcV()
   {
      V = (M_PI * r * r * h) / 3;
   }
   void calcS()
   {
      S = (M_PI * r * r) + (M_PI * r * h);
   }
   void setConeRandom()
   {
      h = rand() % 100 + 1;
      r = rand() % 100 + 1;
   }
};

class Tetrahedron : public Shape
{
   friend std::ostream &operator<<(std::ostream &out, Tetrahedron &shape);
   friend std::istream &operator>>(std::istream &in, Tetrahedron &shape);

public:
   Tetrahedron()
   {
      cout << "Do you want to enter the sides of the tetrahedron manually? (y/n) ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         cin >> *this;
      }
      else
      {
         setTetrahedronRandom();
      }
      cout << a << "\n";
      calcV();
      calcS();
   }

private:
   void calcV()
   {
      V = sqrt(3) / 12 * a * a * a;
   }
   void calcS()
   {
      S = sqrt(3) * a * a;
   }
   void setTetrahedronRandom()
   {
      a = rand() % 10 + 1;
   }
};

std::ostream &operator<<(std::ostream &out, Cube &shape)
{
   out << "The length of the side: " << shape.h << "\n"
       << "The volume of the cube: " << shape.V << "\n"
       << "The area of the cube: " << shape.S << "\n";
   return out;
}

std::ostream &operator<<(std::ostream &out, Cone &shape)
{

   out << "The height of the cone: " << shape.h << "\n"
       << "The radius of the cone: " << shape.r << "\n"
       << "The volume of the cone: " << shape.V << "\n"
       << "The area of the cone: " << shape.S << "\n";
   return out;
}

std::ostream &operator<<(std::ostream &out, Tetrahedron &shape)
{
   out << "The side of the tetrahedron: " << shape.a << "\n"
       << "The volume of the tetrahedron: " << shape.V << "\n"
       << "The area of the tetrahedron: " << shape.S << "\n";
   return out;
}

std::istream &operator>>(std::istream &in, Cube &shape)
{
   in >> shape.h;
   return in;
}
std::istream &operator>>(std::istream &in, Cone &shape)
{
   in >> shape.h >> shape.r;
   return in;
}

std::istream &operator>>(std::istream &in, Tetrahedron &shape)
{
   in >> shape.a;
   return in;
}

