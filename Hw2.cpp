#include<iostream>
#include <string>
#include <fstream>
#include<cstdlib>
using namespace std;
bool isName(string name);
string accountNumber();

int main(){
  ///////////////////////////////////////Declare Variables//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  string Name[2],accNum;//Declare An array called Name, and a string called accNum
  int zipCode;//Declare an int called zipCode.
  //////////////////////////////////////Variables are declared////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  ////////////////////////////////////////////////////Get users names/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  system("clear");
  std::cout<<"Please tell me your first name: ";//ask for first name
  for(cin>>Name[0];!isName(Name[0]);cin>>Name[0])std::cout<<"\nYour first name must be between 2 and 10 charecters\n";

  std::cout<<"Please tell me your last name: ";//Ask for Last name
  for(cin>>Name[1];(2>Name[1].length())||(Name[1].length()>10);cin>>Name[1])//Validate Length
  {std::cout<<"\nYour Last name must be between 2 and 10 charecters\n";}
  //////////////////////////////////////////////////Program has users names///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Yeah, end bars are done now


  /////////////////////////////////////////////////////Get accNum//////////////////////////////////////////
  accNum = accountNumber();

  ///////////////////////////////////////////////////Return sucessful////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::cout<<"Results OK, "<<Name[0]<<" "<<Name[1]<<" "<<accNum<<endl;//Reurn sucessful with users name
}


bool isName(string name){
  system("clear");
  bool isValid = true;
  if ((2<name.length())&&(name.length()<10))//Length is correct.
    {
      for(int i;i<sizeof(name);i++)
      {
        if(!isalpha(name[i]))
        {
          if((name[i]==45)&&(!isupper(name[i+1])))
          //Is Valid
          isValid=isValid;
          else
          {isValid = false;//Is not letter and is not hyphon.
            cout<<"You have an illegal symbol in your name\n";
          }
        }
      }
    }
    else isValid=false;//Name is either too short or too long.
    return isValid;
}


string accountNumber(){
  system("clear");
  string acounNum;//Initialize acounNum to an empty 11 charecter array

  bool isValid = false;
  while(!isValid){
    isValid=true;
    cout<<"Please enter your account number: \n";
  cin>>acounNum;
  if(11==acounNum.length())
    {
      acounNum.erase(3,1);
      acounNum.erase(7,1);
    }
    for(int i =0;i<acounNum.length();i++)
    {
      if(!isdigit(acounNum[i]))
        {isValid=false;
          cout<<"You have an invalid symbol in your Account number\n";
    }}

    if(acounNum.length()!=9)
    {
      isValid=false;
      std::cout<<"\nYour account number must be 9 or 11 charecters, depending on if you use hyphons\n";
    }
  }
  return acounNum;
}
