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

void getShow(Show &show);
void printShow(const Show &show);
void getShowRandom(Show &show);
Show *AddStruct(Show *&show, int &size);

int main(int argc, char const *argv[])
{
   Show *show = nullptr;
   int randomise = 0;
   int showAmount = 0;
   int stopOrContinue = 0;
   cout << "Do you want to randomise?" << endl;
   cin >> randomise;
   do
   {
      int i
      Show show = AddStruct(show, showAmount);
      if (randomise == 1)
      {
         getShowRandom(show[showAmount]);
      }
      else
      {
         getShow(show[showAmount]);
      }
      printShow(show[showAmount]);
      showAmount++;
      cout << "Do you want to add more shows? (1 for yes, 0 for no): ";
      cin >> stopOrContinue;
   } while (stopOrContinue == 1);
   for (int i = 0; i < showAmount; i++)
   {
      cout << "Show " << i + 1 << ": " << endl;
      cout << show[i].name << endl;
      cout << show[i].time.hour << ":" << show[i].time.minute << endl;
   }

   return 0;
}

void getShow(Show &show)
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

void getShowRandom(Show &show)
{
   show.time.hour = rand() % 24;
   show.time.minute = rand() % 60;
   show.name = "Random Show";
}

Show *AddStruct(Show Obj, const int amount)
{
   if (amount == 0)
   {
      Obj = new Show[amount + 1];
   }
   else
   {
      Show *tempObj = new Show[amount + 1];
      for (int i = 0; i < amount; i++)
      {
         tempObj[i] = Obj[i];
      }
      delete[] Obj;
      Obj = tempObj;
   }