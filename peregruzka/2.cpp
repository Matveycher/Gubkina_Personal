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
   cout << "Do you want to create a show or showlist? (1/2): ";
   int choice;
   cin >> choice;
   if (choice == 1)
   {
      Show show;
      cout << "Do you want to enter the show? (y/n): ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         cin >> show;
      }
      else
      {
         show.getShowRandom();
      }
      cout << show;
      cout << "Do you want to increment the show? (y/n): ";
      cin >> answer;
      if (answer == 'y')
      {
         ++show;
      }
      cout << show;
   }
   else if (choice == 2)
   {
      cout << "Enter the number of shows: ";
      int n;
      cin >> n;
      ShowList showlist(n);

      cout << "Do you want to enter the showlist? (y/n): ";
      char answer;
      cin >> answer;
      if (answer == 'y')
      {
         cin >> showlist;
      }
      else
      {
         showlist.getShowsRandom();
      }
      cout << showlist;
      cout << "Do you want to sort the showlist? (y/n): ";
      cin >> answer;
      if (answer == 'y')
      {
         showlist.Sort();
      }
      cout << showlist;
      return 0;
   }
}
