#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>
#include "2.h"
using namespace std;

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