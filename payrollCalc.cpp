#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

float timeToInt(std::string);
#define inFile !inputFile.eof()
//Define inFile as "!inputFile.eof()", just to learn how to use #define



int main(){
  std::string timeInString = "11:15";
  ifstream inputFile;
  inputFile.open("payrollData.txt");
  int i=0;
  while(inFile){
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
