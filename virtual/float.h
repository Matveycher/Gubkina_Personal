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
public:
   virtual void calcAll() = 0;

protected:
   virtual void setRandom() = 0;
   float S = 0;
   float V = 0;
};

class Cube : public Shape
{
   friend std::ostream &operator<<(std::ostream &out, Cube &shape);
   friend std::istream &operator>>(std::istream &in, Cube &shape);

public:
   void calcAll() override
   {
      S = 6 * pow(h, 2);
      V = h * h * h;
   }
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
         setRandom();
      }
   }

private:
   float h = 0;
   void setRandom() override
   {
      h = rand() % 100 + 1;
   }
};

class Cone : public Shape
{
   friend std::ostream &operator<<(std::ostream &out, Cone &shape);
   friend std::istream &operator>>(std::istream &in, Cone &shape);

public:
   void calcAll() override
   {
      S = M_PI * r * r + M_PI * r * h;
      V = M_PI * r * r * h / 3;
   }
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
         setRandom();
      }
   }
   friend std::ostream &operator<<(std::ostream &out, Cone &shape);
   friend std::istream &operator>>(std::istream &in, Cone &shape);

private:
   float r = 0;
   float h = 0;
   void setRandom() override
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
   void calcAll() override
   {
      S = 4 * a * a;
      V = a * a * a / 3;
   }
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
         setRandom();
      }
      cout << a << "\n";
   }

private:
   float a = 0;
   void setRandom() override
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
