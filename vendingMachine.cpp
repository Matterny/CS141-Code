#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct location{
  string building;
  int floor;
};

struct drink{
  string name;
  float size, price;
};

struct vendingMachine{
  location position;
  drink beverage[10];
};
int Lines;
vendingMachine allVendingMachines[5];

void readFile();
void menu();
void buy();
void show();

int main(){
  readFile();
  menu();
  return 0;
}

//Reads the files into a structure. Works.
void readFile(){
  ifstream MasterList;
  MasterList.open("vendingmachinedata.txt");

  int x=0;
  int i=0;
  while(!MasterList.eof()){//While in MasterList, read the datapoints.
    MasterList>>allVendingMachines[x].position.building>>allVendingMachines[x].position.floor;
    MasterList>>allVendingMachines[x].beverage[i-10*x].name>>allVendingMachines[x].beverage[i-10*x].size>>allVendingMachines[x].beverage[i-10*x].price;
    i++;
    x=i/10;
  }
  Lines = x;
  MasterList.close();
}

void menu(){
  while(1){
  cout<<"Buy a beverage or show the machines? (type exit to exit)\n";
  string selected;
  cin>>selected;
  for(int i=0;i<sizeof(selected);i++)
    if (selected[i] > 91)                       //make any lowercase inputs Uppercase.
      selected[i] = selected[i] - 32;
  if(selected == "BUY"){
    cout<<"You have selected BUY.\n";
    buy();
  }

  else if(selected == "SHOW"){//Code for showing beverages for sale.
    cout<<"You have Selected show\n";
    show();
  }
  else if(selected == "EXIT"){
    break;
  }
  else{
    cout<<"Sorry, I do not know that command\n";
  }
}}

void buy(){while(1){
  cout<<"Please specify: location, floor, drink name and drink size, seperated by spaces\n";
  string location, name;
  int level;
  float size, price;
  cin>>location>>level;
  cin>>name>>size;
  int x,i;
  for(x=0;x<Lines;x++){
    if(allVendingMachines[x].position.building==location){
      if(allVendingMachines[x].position.floor ==level){
        for(i=0;i<10;++i){
            if(allVendingMachines[x].beverage[i].name==name){
              if(allVendingMachines[x].beverage[i].size==size){
                cout<<"Sucessful, great choice\n";
                allVendingMachines[x].beverage[i].name="SOLD-NOT ABLE TO BUY";//The spaces ensure that a user cant buy this beverage anymore.
                return;
              }
            }
         }
       }
     }
   }
  cout<<"Information was Invalid, please try again\n";
}}

void show(){
  int i=0,x=0;
  while(x<Lines){//While in MasterList, read the datapoints.
    cout<<endl<<allVendingMachines[x].position.building<<" "<<allVendingMachines[x].position.floor<<" ";
    cout<<allVendingMachines[x].beverage[i-10*x].name<<" "<<allVendingMachines[x].beverage[i-10*x].size;//<<allVendingMachines[x].beverage[i-10*x].price;
    i++;
    x=i/10;
  }
  cout<<endl;
}
