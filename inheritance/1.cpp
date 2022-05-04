#include "2.h"

/*
ЧЕРНЫХ МАТВЕЙ
Написать программу, в которой описана иерархия классов: геометрические фигуры (куб, конус, тетраэдр).
 Реализовать методы вычисления объема и площади поверхности фигуры.
Продемонстрировать работу всех методов классов, предоставив пользователю выбор типа фигуры для демонстрации.
*/

int main()
{
   cout << "Enter the type of the shape: ";
   char answer;
   cin >> answer;
   switch (answer)
   {
   case 'c':
   {
      Cube cube;
      cube.getVolume();
      cube.getArea();
      break;
   }
   case 't':
   {
      Tetrahedron tetrahedron;
      tetrahedron.getVolume();
      tetrahedron.getArea();
      break;
   }
   case 'n':
   {
      Cone cone;
      cone.getVolume();
      cone.getArea();
      break;
   }
   }
}
