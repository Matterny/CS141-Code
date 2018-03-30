#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
  void readNames(string);
  void readPWD(string);
  void randomizeArray();
  void writeInfo(string);


typedef string NAME;
struct userID{
  NAME fn;
  NAME ln;
  string password;
};

userID employees[50];
string passwords[50];
string newPWD[50];

int main(){
  readNames("employees.txt");
  readPWD("passwords.txt");
  randomizeArray();
  writeInfo("empPasswords.txt");
  return 0;
}

void readNames(string fileName){
  ifstream users;
  users.open(fileName.c_str());
  for(int x=0;x<50;x++)
  {
    users>>employees[x].fn>>employees[x].ln;
  }
  users.close();
}

void readPWD(string fileName){
  ifstream DB;
  DB.open(fileName.c_str());
  for(int x=0;x<50;x++)
  {
    DB>>passwords[x];
  }
  DB.close();
}

void randomizeArray(){
  for(int x=0;x<50;x++)
  {int randomPos = rand() % 50;
    newPWD[x] = passwords[randomPos];
  }
}

void writeInfo(string fileName){
  ofstream info;
  info.open(fileName.c_str());
  for(int x=0;x<50;x++){
      info<<employees[x].fn<<" "<<employees[x].ln<<" "<<newPWD[x]<<endl;
    }
  }
