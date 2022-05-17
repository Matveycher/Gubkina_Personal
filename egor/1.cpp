#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>

//Написать программу, в которой описана иерархия классов: числа (целое, вещественное,комплексное). Реализовать методы сложения, произведения. Продемонстрировать работу всех методов классов, предоставив пользователю выбор типа основного и вспомогательного числа для демонстрации.

class Number
{
protected:
   int Integer
} class ComplexNumber : protected Number
{
protected:
   int Imaginary;
   float RealPart;
}

class RealNumber : protected Number
{
protected:
   int RealPart;
} class IntegerNumber : protected Number
{

}

int
main()
{
   cout << "Choose type of the first Number(I,R,C)\n" char num1Type;
   cin >> num1Type;
   switch (num1Type)
   {
   case 'I':
      IntegerNumber num1;
      break;
   case 'R':
      RealNumber num1;
      break;
   case 'C':
      ComplexNumber num1;
      break;
   default:
      cout << "Wrong input\n";
      return 0;
   }
   cout << "Enter the first number\n";
   cin >> num1; // это через перегрузку сделай
   cout << "Choose type of the second Number(I,R,C)\n" char num2Type;
   cin >> num2Type;
   switch (num2Type)
   {
   case 'I':
      IntegerNumber num2;
      break;
   case 'R':
      RealNumber num2;
      break;
   case 'C':
      ComplexNumber num2;
      break;
   default:
      cout << "Wrong input\n";
      return 0;
   }
   cin >> num2; // это через перегрузку сделай
   cout << "Choose operation(+,*)\n";
   char operation;
   cin >> operation;
   while (operation == '+' || operation == '*')
   {
      switch (operation)
      {
      case '+':
         num1 = num1 + num2; // это тоже через перегрузку
         cout << num1;
         break;
      case '*':
         num1 = num1 * num2; // это тоже через перегрузку
         cout << num1;
         break;
      default:
         cout << "Wrong input\n";
         return 0;
      }
   }

   return 0;
}