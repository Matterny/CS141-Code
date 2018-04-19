#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#define read(inFile);    inFile>>Employees[x].wage.hourly>>Employees[x].name.Fn>>Employees[x].name.Mn>>Employees[x].name.Ln>>Employees[x].department>>Employees[x].manager.Fn>>Employees[x].manager.Mn>>Employees[x].manager.Ln>>starttime >> lunchstart >> lunchend >> endtime;
//This is because these lines are so long I dont want them to exist inside my code.
float timeToInt(std::string);
void readData(string);

enum days {monday, tuesday, wednesday, thursday, friday};
struct Wage{
  float hourly, otRate;
  bool otEle;
};
struct Person{
  string Fn, Mn, Ln;
};
struct timeCard{
  float hrsWorked, lunchBreakLength, otHours, totalPay;
};
struct employee{
  Person name,manager;
  Wage wage;
  timeCard timecard[5];
  string department;
};
employee Employees[20];

int main(){
  std::string timeInString = "11:15";
  ifstream inputFile;
  inputFile.open("payrollData.txt");
  int i=0;
  while(!inputFile.eof()){
  char x;
  i++;
  cout<<i<<"\n";
  inputFile>>x;
  }
  timeToInt(timeInString);
  return 0;
}




float timeToInt(std::string timeInString){
  //Find the location of the :
  int locOfDivider = timeInString.find(':');
  std::string timeHours = timeInString.substr(0, locOfDivider);
  std::string timeMins = timeInString.substr(locOfDivider+1, timeInString.length());
  int timeHoursInt;
  std::istringstream(timeHours) >> timeHoursInt;
  int timeMinsInt;
  std::istringstream(timeMins) >> timeMinsInt;
  return timeHoursInt+timeMinsInt/60;
}

float hoursWorked(string clockIN,string lunchStart, string lunchEnd, string clockout){
  return -timeToInt(clockIN)+timeToInt(clockout)-timeToInt(lunchStart)+timeToInt(lunchEnd);
}

void readData(string fileName){
  ifstream inFile;
  inFile.open(fileName.c_str());
  int x=0;
  while(!inFile.eof()){
    string starttime,lunchstart, lunchend, endtime;
    read(inFile);
    for(int count=0;count<5;count++){
      read(inFile);
      Employees[x].timecard[count].hrsWorked = hoursWorked(starttime,lunchstart,lunchend,endtime);
    }

    x++;
  }

  inFile.close();
}
