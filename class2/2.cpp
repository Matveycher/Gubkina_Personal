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
   ShowList showList;
   Show show;
   setShow(show);
   showList.addShow(show);
   setShow(show);
   showList.addShow(show);
   setShow(show);
   showList.addShow(show);
   showList.printShows();
   showList.getShowsRandom();
   showList.printShows();
   return 0;
}
