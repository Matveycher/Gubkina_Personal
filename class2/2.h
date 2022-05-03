#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>

using namespace std;

class Show
{
private:
   string name;
   struct time
   {
      int hour;
      int minute;
   } time;

public:
   string getName()
   {
      return name;
   }
   void setName(string name)
   {
      this->name = name;
   }
   int getHour()
   {
      return time.hour;
   }
   void setHour(int hour)
   {
      this->time.hour = hour;
   }
   int getMinute()
   {
      return time.minute;
   }
   void setMinute(int minute)
   {
      this->time.minute = minute;
   }

   void setShow()
   {
      cout << "Enter the name of the show: ";
      cin >> name;
      cout << "Enter the hour of the show: ";
      cin >> time.hour;
      cout << "Enter the minute of the show: ";
      cin >> time.minute;
   }
   void getShowRandom()
   {
      time.hour = rand() % 24;
      time.minute = rand() % 60;
      name = "Random Show " + to_string(rand() % 100);
   }
   void printShow()
   {
      cout << "Show: " << name << endl;
      cout << "Time: " << time.hour << ":" << time.minute << endl;
   }
   Show()
   {
      name = "";
      time.hour = 0;
      time.minute = 0;
   }
   Show(string name, int hour, int minute)
   {
      this->name = name;
      this->time.hour = hour;
      this->time.minute = minute;
   }
};

class ShowList
{
private:
   Show *shows;
   int size;
   int capacity;

public:
   ShowList()
   {
      size = 0;
      capacity = 10;
      shows = new Show[capacity];
   }
   ~ShowList()
   {
      delete[] shows;

      cout << "xxxxx";
   }
   void addShow(Show _show)
   {
      if (size == capacity)
      {
         capacity *= 2;
         Show *newShows = new Show[capacity];
         for (int i = 0; i < size; i++)
         {
            newShows[i] = shows[i];
         }
         delete[] shows;
         shows = newShows;
      }
      shows[size] = _show;
      size++;
   }
   void printShows()
   {
      for (int i = 0; i < size; i++)
      {
         shows[i].printShow();
      }
   }
   void getShowsRandom()
   {
      for (int i = 0; i < size; i++)
      {
         shows[i].getShowRandom();
      }
   }
};

void setShowRandom(Show &_show)
{
   _show.getShowRandom();
}
void printShow(Show _show)
{
   _show.printShow();
}
void setShow(Show &_show)
{
   _show.setShow();
}
