#include<fstream>
  #include<iostream>
  #include<cstdlib>
  #include<string>
  using namespace std;

struct library{
  string title;
  char in;
  string Fn, Ln;
  int late;
};
library libraryData[20];

void readFile(){
  ifstream inputs;
  inputs.open("library.txt");
  for(int x=0;x<20;x++){
    inputs>>libraryData[x].title>>libraryData[x].in>>libraryData[x].Fn>>libraryData[x].Ln>>libraryData[x].late;
  }
  inputs.close();
}
void viewAll(){
  for(int x=0;x<20;x++){
    cout<<libraryData[x].title<<" "<<libraryData[x].in<<" "<<libraryData[x].Fn<<libraryData[x].Ln<<libraryData[x].late<<endl;
  }
}
void showbypatron(string fn, string ln){
int hasAny = 0;
  for(int x=0;x<20;x++){
    if ((libraryData[x].Fn==fn)){//cout<<"FN";
    if(libraryData[x].Ln==ln){//cout<<"LN";
      hasAny++;
      cout<<libraryData[x].title<<" "<<libraryData[x].late<<endl;
    }}
  }
  if(hasAny)cout<<fn<<" "<<ln<<" has "<<hasAny<<" Books checked out right now\n";
  else cout<<"This user has no books signed out at this time\n";
}
void calcPenalty(){
  for(int x=0;x<20;x++){
    int penalty = libraryData[x].late;
    if ((libraryData[x].late!=-1)){
    float payment = .1*penalty+(penalty>5)*(.1*(penalty-5))+(penalty>9)*(penalty-9)*.05;
    cout<<libraryData[x].Fn<<" "<<libraryData[x].Ln<<" "<<libraryData[x].title<<" $"<< payment <<endl;
  }}
}

void ShowMenu(){
  //while(1)
  {
    system("clear");
    cout<<"Please select an option\n1. Show all books loaned out by a patron\n2. List all overdue books and their penalty\n3. Quit the program\nPlease select a number: ";
    char option;
    cin>>option;
    if (option=='1'){
      cout<<"Please enter the first and last name, seperated by a space: ";
      string fn, ln;
      cin>>fn>> ln;
      showbypatron(fn,ln);
      //Show all books loaned out by patron
    }
    else if(option == '2'){
      //List all overdue books and penalty
      calcPenalty();
    }
    else if (option =='3'){
      //break;
      cout<<"\nThank you for using the libraTron 100";
    }
  }
}

int main(){
  readFile();
  //viewAll();
  ShowMenu();
  return 0;
}
