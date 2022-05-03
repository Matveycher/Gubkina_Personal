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

struct Channel
{
   int amountOfShows;
   struct Show *show;
};

void getShow(Show &show);
void printShow(const Show &show);
void getShowRandom(Show &show);

void getChannel(Channel *channel);
void printChannel(const Channel &channel);
void getChannelRandom(Channel *channel);

int main(int argc, char const *argv[])
{
   int randomise = 0;
   int showAmount = 0;
   int stopOrContinue = 0;
   cout << "Do you want to randomise?(1 for Yes, 0 for No)" << endl;
   cin >> randomise;
   Channel *channel1 = new Channel;
   if (randomise == 1)
   {
      getChannelRandom(channel1);
   }
   else
   {
      getChannel(channel1);
      cout << "How many shows do you want to add?" << endl;
      cin >> channel1->amountOfShows;
   }
   printChannel(*channel1);

   cout << channel1->show->name;
   free(channel1->show);
   cout << channel1->show->name;
   free(channel1);
   // cout << channel1->show->name;
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
   show.name = "Random Show " + to_string(rand() % 100);
}

void getChannel(Channel *channel)
{
   cout << "Enter the amount of shows: ";
   cin >> channel->amountOfShows;
   channel->show = new Show[channel->amountOfShows];
   for (int i = 0; i < channel->amountOfShows; i++)
   {
      getShow(channel->show[i]);
   }
}

void printChannel(const Channel &channel)
{
   for (int i = 0; i < channel.amountOfShows; i++)
   {
      cout << "Show " << i + 1 << ": " << endl;
      cout << channel.show[i].name << endl;
      cout << channel.show[i].time.hour << ":" << channel.show[i].time.minute << endl
           << endl;
   }
}

void getChannelRandom(Channel *channel)
{
   channel->amountOfShows = rand() % 10;
   channel->show = new Show[channel->amountOfShows];
   for (int i = 0; i < channel->amountOfShows; i++)
   {
      getShowRandom(channel->show[i]);
   }
}
