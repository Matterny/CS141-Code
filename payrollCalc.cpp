#include <sstream>
  #include <string>
  #include <iostream>
  #include <fstream>
  using namespace std;
    float timeToInt(std::string);
    void readData(string);
    float hoursWorked(string ,string , string , string );
    float breakLength(string clockIN,string lunchStart, string lunchEnd, string clockout);
    float overtime(string clockIN,string lunchStart, string lunchEnd, string clockout);
    float totalPay(float totalHrs,float otHours,float wage, float otPay, char otEle);
    void writeData(string);
    enum days {monday, tuesday, wednesday, thursday, friday};
    #define readf     inFile>>Employees[x].wage.hourly>>Employees[x].wage.otEle>>Employees[x].wage.otRate>>Employees[x].name.Fn>>Employees[x].name.Mn>>Employees[x].name.Ln>>Employees[x].department>>Employees[x].manager.Fn>>Employees[x].manager.Mn>>Employees[x].manager.Ln>>starttime >> lunchstart >> lunchend >> endtime;

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
  if(-timeToInt(clockIN)+timeToInt(clockout)-timeToInt(lunchStart)+timeToInt(lunchEnd)>0)
  return 40-timeToInt(clockIN)+timeToInt(clockout)-timeToInt(lunchStart)+timeToInt(lunchEnd);
  return 0;
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

    for(int count=0;count<5;count++){
      readf
      Employees[x].timecard[count].hrsWorked = hoursWorked(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[count].lunchBreakLength = breakLength(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[count].otHours = overtime(starttime,lunchstart,lunchend,endtime);
      Employees[x].timecard[count].totalPay = totalPay(Employees[x].timecard[count].hrsWorked,
        Employees[x].timecard[count].otHours,Employees[x].wage.hourly,Employees[x].wage.otRate,Employees[x].wage.otEle);
      }
    x++;
  }
  cout <<endl<<endtime<<endl;
  inFile.close();
}

void writeData(string fileName){
  if (fileName.substr(max(4, fileName.size())-4) != string(".xml")) {
    cout<<"Bad output fileName\n";
    return;
  }
  ofstream outfile;
  outfile.open(fileName.c_str());
  int x=0;
  while(x<20){
  outfile<<"<payroll>\n<employee>\n
 <name>"<< Employees[x].name.Fn<<" "<<Employees[x].name.Mn<<" "<<Employees[x].name.Ln<<"</name>\n
 <manager>"<< Employees[x].manager.Fn<<" "<<Employees[x].manager.Mn<<" "<<Employees[x].manager.Ln<<"</name>\n
 <department>"<<Employees[x].department<<"</department>\n
 <payrate>"<<Employees[x].wage.hourly<<"</payrate>\n
 <overtime>";
 if(Employees[x].wage.otEle=='Y')
  outfile<<"Yes";
 else if(Employees[x].wage.otEle=='N')
  outfile<<"No"
 else outfile<<"error";

 outfile<<"</overtime>\n
 <multiplier>1.3</multiplier>\n
 <hours>45</hours>\n
 <overhours>7.5</overhours>\n
 <lunch>6</lunch>\n
 <pay>718.20</pay>\n
 </employee>\n
 <employee>\n
 <name>Jessica Alice Waters</name>\n
 <manager>Jane Mary Hargreave</name>\n
 <department>Avionics</department>\n
 <payrate>19.40</payrate>\n
 <overtime>No</overtime>\n
 <multiplier>0</multiplier>\n
 <hours>37.5</hours>\n
 <overhours>0</overhours>\n
 <lunch>5</lunch>\n
 <pay>727.50</pay>\n
 </employee>\n
</payroll>";
x++;
}

  outfile.close();
}
