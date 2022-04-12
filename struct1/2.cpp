#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>

using namespace std;

struct Show
{
   string name;
   struct time
   {
      int hour;
      int minute;
   } time;
};

void setShow(Show &show);
void printShow(const Show &show);
void setShowRandom(Show &show);
Show *AddStruct(Show *&show, int &size);

int main(int argc, char const *argv[])
{
   int randomise = 0;
   int showAmount = 0;
   int stopOrContinue = 0;
   cout << "Do you want to randomise?(1 for Yes, 0 for No)" << endl;
   cin >> randomise;
   cout << "How many shows do you want to add?" << endl;
   cin >> showAmount;
   Show *show = new Show[showAmount];
   for (int i = 0; i < showAmount; i++)
   {
      if (randomise == 1)
      {
         setShowRandom(show[i]);
      }
      else
      {
         setShow(show[i]);
      }
      printShow(show[i]);
   }
   for (int n = 0; n < showAmount; n++)
   {
      cout << "Show " << n + 1 << ": " << endl;
      cout << show[n].name << endl;
      cout << show[n].time.hour << ":" << show[n].time.minute << endl
           << endl;
   }

   return 0;
}

void setShow(Show &show)
{
   cout << "Enter the name of the show: ";
   getline(cin, show.name);
   cout << "Enter the hour of the show: ";
   cin >> show.time.hour;
   cout << "Enter the minute of the show: ";
   cin >> show.time.minute;
}

void printShow(const Show &show)
{
   cout << "The show " << show.name << " is at " << show.time.hour << ":" << show.time.minute << endl;
}

void setShowRandom(Show &show)
{
   show.time.hour = rand() % 24;
   show.time.minute = rand() % 60;
   show.name = "Random Show " + to_string(rand() % 100);
}
