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

float sGeron(float a, float b, float c)
{
   float pHalf = (a + b + c) / 2;
   return sqrt(pHalf * (pHalf - a) * (pHalf - b) * (pHalf - c));
}

class Shape
{
public:
   void getVolume()
   {
      cout << "The volume of the shape: ";
      cout << V << "\n";
   }

   void getArea()
   {
      cout << "The area of the shape: ";
      cout << S << "\n";
   }

protected:
   float h = 0;
   float r = 0;
   float a1 = 0;
   float a2 = 0;
   float a3 = 0;
   float a4 = 0;
   float a5 = 0;
   float a6 = 0;
   float S = 0;
   float V = 0;
};

class Cube : public Shape
{
public:
   void setCube()
   {
      cout << "Enter the height of the cube: ";
      cin >> h;
   }

   void setCubeRandom()
   {
      h = rand() % 100;
   }
   Cube()
   {
      cout << "Do you want to enter the parameters of the cube? (y/n) ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         setCube();
      }
      else
      {
         setCubeRandom();
      }
      calcS();
      calcV();
   }

   float calcS()
   {
      S = 6 * h * h;
      return 0;
   }
   float calcV()
   {
      V = h * h * h;
      return 0;
   };
};

class Cone : public Shape
{
public:
   void setCone()
   {
      cout << "Enter the height of the cone: ";
      cin >> h;
      cout << "Enter the radius of the cone: ";
      cin >> r;
   }
   void setConeRandom()
   {
      h = rand() % 100;
      r = rand() % 100;
   }
   Cone()
   {
      cout << "Do you want to enter the parameters of the cone? (y/n) ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         setCone();
      }
      else
      {
         setConeRandom();
      }
      calcS();
      calcV();
   }

private:
   float calcV()
   {
      V = (M_PI * r * r * h) / 3;
      return 0;
   }
   float calcS()
   {
      S = (M_PI * r * r) + (M_PI * r * h);
      return 0;
   }
};

class Tetrahedron : public Shape
{
public:
   void setTetrahedron()
   {
      cout << "Enter the side 1 of the tetrahedron: ";
      cin >> a1;
      cout << "Enter the side 2 of the tetrahedron: ";
      cin >> a2;
      cout << "Enter the side 3 of the tetrahedron: ";
      cin >> a3;
      cout << "Enter the side 4 of the tetrahedron: ";
      cin >> a4;
      cout << "Enter the side 5 of the tetrahedron: ";
      cin >> a5;
      cout << "Enter the side 6 of the tetrahedron: ";
      cin >> a6;
   }

   void setTetrahedronRandom()
   {
      a1 = rand() % 100;
      a2 = rand() % 100;
      a3 = rand() % 100;
      a4 = rand() % 100;
      a5 = rand() % 100;
      a6 = rand() % 100;
   }
   Tetrahedron()
   {
      cout << "Do you want to enter the sides of the tetrahedron manually? (y/n) ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         setTetrahedron();
      }
      else
      {
         setTetrahedronRandom();
      }
      cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << "\n";
      calcV();
      calcS();
   }

private:
   float calcV()
   {
      V = sqrt(a1 * a1 * a5 * a5 * (a2 * a2 + a3 * a3 + a4 * a4 + a6 * a6 - a1 * a1 - a5 * a5) + a2 * a2 * a6 * a6 * (a1 * a1 + a3 * a3 + a4 * a4 + a5 * a5 - a2 * a2 - a6 * a6) + a3 * a3 * a4 * a4 * (a1 * a1 + a2 * a2 + a5 * a5 + a6 * a6 - a3 * a3 - a4 * a4) - a1 * a1 * a2 * a2 * a4 * a4 - a1 * a1 * a3 * a3 * a6 * a6 - a2 * a2 * a3 * a3 * a5 * a5 - a4 * a4 * a5 * a5 * a6 * a6);
      return 0;
   }
   float calcS()
   {
      // S = sGeron(a1, a2, a3) + sGeron(a1, a2, a4) + sGeron(a1, a2, a5) + sGeron(a1, a2, a6);
      // S = sGeron(a1, a2, a3);
      S = sqrt(a1);
      return 0;
   }
};
