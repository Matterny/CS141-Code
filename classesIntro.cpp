#include<string>
#include<iostream>
using namespace std;

class TimeOfDay
{
public:
//Constructors
TimeOfDay();
TimeOfDay(int hours, int minutes, int seconds);
//Transformer
TimeOfDay Increment() const;
//Observers
void Write() const;
bool Equal(TimeOfDay otherTime) const;
bool LessThan(TimeOfDay otherTime) const;
private:
int hours;
int minutes;
int seconds;
};


TimeOfDay::TimeOfDay()
{
hours = 0;
minutes = 0;
seconds = 0;
}
TimeOfDay::TimeOfDay(int initHours, int initMinutes, int initSeconds)
{
hours = initHours;
minutes = initMinutes;
seconds = initSeconds;
}

TimeOfDay TimeOfDay::Increment() const{
  TimeOfDay result(hours, minute, seconds);
  results.seconds++;
  if(seconds>59){
    results.seconds=0;
    results.minutes++;
    if(results.minutes>59)
    {
      results.minutes=0;
      results.hours++;
      if(results.hours>23)
        results.hours=0;
    }
  }
}
