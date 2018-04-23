#include <sstream>
  #include <string>
  #include <iostream>
  #include <fstream>
  #include <cmath>
  using namespace std;
    float timeToInt(std::string);
    void readData(string);
    float hoursWorked(string ,string , string , string );
    float breakLength(string clockIN,string lunchStart, string lunchEnd, string clockout);
    float overtime(string,string lunchStart, string lunchEnd, string clockout);
    float totalPay(float,float,float, float, char);
    void writeData(string);
    enum days {monday, tuesday, wednesday, thursday, friday};
    //#define readf     inFile>>Employees[x].wage.hourly>>Employees[x].wage.otEle>>Employees[x].wage.otRate>>Employees[x].name.Fn>>Employees[x].name.Mn>>Employees[x].name.Ln>>Employees[x].department>>Employees[x].manager.Fn>>Employees[x].manager.Mn>>Employees[x].manager.Ln>>starttime >> lunchstart >> lunchend >> endtime;

struct Wage{
  float hourly, otRate;
  char otEle;
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
  timeCard weekly;
  string department;
};
employee Employees[20];

int main(){
  cout<<"File to open: \n";
  string nameOfFile;
  cin>>nameOfFile;
  readData(nameOfFile);
  cout<<"\nFile to write: \n";
  cin>>nameOfFile;
  writeData(nameOfFile);
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
float breakLength(string clockIN,string lunchStart, string lunchEnd, string clockout){
  return -timeToInt(lunchStart)+timeToInt(lunchEnd);
}
float overtime(string clockIN,string lunchStart, string lunchEnd, string clockout){
  float hoursPerDay = -timeToInt(clockIN)+timeToInt(clockout)-timeToInt(lunchStart)+timeToInt(lunchEnd);
  return abs(hoursPerDay-7.5);

}
float totalPay(float totalHrs,float otHours,float wage, float otPay, char otEle){
  if(otEle == 'Y')
    return totalHrs*wage+otHours*(otPay-1)*wage;
  else if (otEle == 'N')
    return totalHrs*wage;
  else {
    cout <<"\nDB ERROR, PLEASE RECOMPUTE AFTER FIXING\n";
    return -1;
  }
}

void readData(string fileName){
  ifstream inFile;
  inFile.open(fileName.c_str());
  int x=0;
  string endtime;
  while(x<20){
    string starttime,lunchstart, lunchend;
    Employees[x].weekly.totalPay =0;
    Employees[x].weekly.otHours  =0;
    Employees[x].weekly.lunchBreakLength =0;
    Employees[x].weekly.hrsWorked =0;
    for(int count=0;count<5;count++){
      inFile>>Employees[x].wage.hourly>>Employees[x].wage.otEle>>Employees[x].wage.otRate>>Employees[x].name.Fn>>Employees[x].name.Mn>>Employees[x].name.Ln>>Employees[x].department>>Employees[x].manager.Fn>>Employees[x].manager.Mn>>Employees[x].manager.Ln>>starttime >> lunchstart >> lunchend >> endtime;
      //Gets the value per day
      Employees[x].timecard[count].hrsWorked = hoursWorked(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[count].lunchBreakLength = breakLength(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[count].otHours = overtime(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[count].totalPay = totalPay(Employees[x].timecard[count].hrsWorked,
        Employees[x].timecard[count].otHours,Employees[x].wage.hourly,Employees[x].wage.otRate,Employees[x].wage.otEle);

        //Adds up values to get a total per week
      Employees[x].weekly.totalPay  +=Employees[x].timecard[count].totalPay;
      Employees[x].weekly.hrsWorked +=Employees[x].timecard[count].hrsWorked;
      Employees[x].weekly.otHours   +=Employees[x].timecard[count].otHours;
      Employees[x].weekly.lunchBreakLength +=Employees[x].timecard[count].lunchBreakLength;
      }
    x++;
  }
  cout <<endl<<endtime<<endl;
  inFile.close();
}

void writeData(string fileName){
  if (fileName.substr( fileName.size()-4) != string(".xml")) {
    cout<<"Bad output fileName\n";
    return;
  }
  ofstream outfile;
  outfile.open(fileName.c_str());
//  /*
  int x=0;
  outfile<<"<payroll>\n";
  while(x<20){
  outfile<<"<employee>\n<name>"<< Employees[x].name.Fn<<" "<<Employees[x].name.Mn<<" "<<Employees[x].name.Ln<<"</name>\n";
  outfile<<"<manager>"<< Employees[x].manager.Fn<<" "<<Employees[x].manager.Mn<<" "<<Employees[x].manager.Ln<<"</name>\n";
  outfile<<"<department>"<<Employees[x].department<<"</department>\n<payrate>";
  outfile<<Employees[x].wage.hourly<<"</payrate>\n<overtime>";
  if(Employees[x].wage.otEle=='Y')
    {outfile<<"Yes";}
  else {if(Employees[x].wage.otEle=='N')
    outfile<<"No";
    else outfile<<"error";
    }
 outfile<<"</overtime>\n<multiplier>"<< Employees[x].wage.otRate << "</multiplier>\n<hours>"<<Employees[x].weekly.hrsWorked <<"</hours>\n<overhours>";
 outfile<<Employees[x].weekly.hrsWorked-37.5 <<"</overhours>\n<lunch>"<<Employees[x].weekly.lunchBreakLength<<"</lunch>\n<pay>"<< Employees[x].weekly.totalPay <<"</pay>\n</employee>\n";
x++;
}
//  */
outfile<<"</payroll>";
  outfile.close();
}
