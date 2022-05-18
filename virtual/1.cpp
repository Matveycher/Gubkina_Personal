#include "float.h"

/*
ЧЕРНЫХ МАТВЕЙ
Написать программу, в которой описана иерархия классов: геометрические фигуры (куб, конус, тетраэдр).
 Реализовать методы вычисления объема и площади поверхности фигуры.
Продемонстрировать работу всех методов классов, предоставив пользователю выбор типа фигуры для демонстрации.
*/

int main()
{
   cout << "Enter the type of the shape(c for Cube, n for Cone, t for Tetrahedront): ";
   char answer;
   cin >> answer;
   Shape *ptr;
   switch (answer)
   {
   case 'c':
   {
      Cube cube;
      ptr = &cube;
      ptr->calcAll();
      cout << cube;
      break;
   }
   case 't':
   {
      Tetrahedron tetrahedron;
      ptr = &tetrahedron;
      ptr->calcAll();
      cout << tetrahedron;
      break;
   }
   case 'n':
   {
      Cone cone;
      ptr = &cone;
      ptr->calcAll();
      cout << cone;
      break;
   }
   default:
      cout << "Incorrect input. Try again\n";
   }
}