#include <string>
#include <iostream>
#include <random>
#include <exception>
#include <cmath>
#include <ctime>

using namespace std;

class Show
{
   friend std::ostream &operator<<(std::ostream &out, Show &show);
   friend std::istream &operator>>(std::istream &in, Show &show);

private:
   string name;

public:
   class Time
   {
   public:
      friend std::ostream &operator<<(std::ostream &out, Time &time)
      {
         out << time.hour << ":" << time.minute;
         return out;
      }
      int hour;
      int minute;
   } time;

public:
   void getShowRandom()
   {
      time.hour = rand() % 24;
      time.minute = rand() % 60;
      name = "Random Show " + to_string(rand() % 100 + 1);
   }

   Show operator++()
   {
      time.minute++;
      if (time.minute == 60)
      {
         time.minute = 0;
         time.hour++;
         if (time.hour == 24)
         {
            time.hour = 0;
         }
      }
      return *this;
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
   friend std::ostream &operator<<(std::ostream &out, ShowList &showlist);
   friend std::istream &operator>>(std::istream &in, ShowList &showlist);

private:
   Show *shows;
   int capacity;

public:
   ShowList(int amount)
   {
      capacity = amount;
      shows = new Show[capacity];
   }
   void Sort()
   {
      for (int i = 0; i < capacity; i++)
      {
         for (int j = 0; j < capacity - 1; j++)
         {
            if (shows[j].time.hour > shows[j + 1].time.hour)
            {
               Show temp = shows[j];
               shows[j] = shows[j + 1];
               shows[j + 1] = temp;
            }
            else if (shows[j].time.hour == shows[j + 1].time.hour)
            {
               if (shows[j].time.minute > shows[j + 1].time.minute)
               {
                  Show temp = shows[j];
                  shows[j] = shows[j + 1];
                  shows[j + 1] = temp;
               }
            }
         }
      }
   }

   ShowList()
   {
      capacity = 10;
      shows = new Show[capacity];
   }
   ~ShowList()
   {
      delete[] shows;
   }

   void getShowsRandom()
   {
      for (int i = 0; i < capacity; i++)
      {
         shows[i].getShowRandom();
      }
   }
};

void setShowRandom(Show &_show)
{
   _show.getShowRandom();
}
/*std::ostream &operator<<(std::ostream &out, Time &time)
{
   out << time.hour << ":" << time.minute;
   return out;
}
*/

std::ostream &operator<<(std::ostream &out, Show &show)
{
   out << "The name of the show is " << show.name << "\n"
       //<< "The time of the show is " << show.time.hour << ":" << show.time.minute << "\n";
       << "The time of the show is " << show.time << "\n";
   return out;
}

std::ostream &operator<<(std::ostream &out, ShowList &showlist)
{
   for (int i = 0; i < showlist.capacity; i++)
   {
      out << "Show " << i + 1 << " is:\n"
          << showlist.shows[i];
   }
   return out;
}

std::istream &operator>>(std::istream &in, Show &show)
{
   cout << "Enter show name ";
   in >> show.name;
   cout << "Enter hour ";
   in >> show.time.hour;
   cout << "Enter minute ";
   in >> show.time.minute;
   return in;
}

std::istream &operator>>(std::istream &in, ShowList &showlist)
{

   for (int i = 0; i < showlist.capacity; i++)
   {
      cout << "Enter show " << i + 1 << ":\n";
      in >> showlist.shows[i];
   }
   return in;
}
