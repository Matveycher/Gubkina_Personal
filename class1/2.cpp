#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>
#include "2.h"

using namespace std;

void setShowRandom(Show &_show);
void printShow(Show _show);
void setShow(Show &_show);

int main()
{
   cout << "Example of random show:\n";
   Show showRandom;
   setShowRandom(showRandom);
   // showRandom.setHour(rand() % 24);
   printShow(showRandom);
   cout << "\n";

   cout << "Example of non-random show:\n";
   Show show;
   setShow(show);
   printShow(show);

   return 0;
}
