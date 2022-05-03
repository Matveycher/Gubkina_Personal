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

void setShowRandom(Show &_show);
void printShow(Show _show);
void setShow(Show &_show);

void setShow(Show &_show)
{
   int minute = 0;
   int hour = 0;
   string name = "";
   cout << "Enter the name of the show: \n";
   cin >> name;
   _show.setName("name");
   cout << "Enter the hour of the show: \n";
   cin >> hour;
   _show.setHour(hour);
   cout << "Enter the minute of the show: \n";
   cin >> minute;
   _show.setMinute(minute);
}
void setShowRandom(Show &_show)
{
   _show.setHour(rand() % 24);
   _show.setMinute(rand() % 60);
   _show.setName("Random Show " + to_string(rand() % 100));
}
void printShow(Show _show)
{
   cout << "Show: " << _show.getName() << endl;
   cout << "Time: " << _show.getHour() << ":" << _show.getMinute() << endl;
}