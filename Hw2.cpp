#include <iostream>
 #include <string>
 #include <fstream>
 #include <cstdlib>
 #include <stdio.h>
using namespace std;
 bool isname(string name);
 string accountNumber();
 void accountBalance(string);


int main(){
  ///////////////////////////////////////Declare Variables////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  string name[2],accNum,accFile = "accounts.txt";//Declare An array called name, and a string called accNum
  int zipCode;//Declare an integer called zipCode.
  //////////////////////////////////////Variables are declared////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////Get users names/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    system("clear");
    cout<<"Please tell me your first name: ";//ask for first name
    for(cin>>name[0];!isname(name[0]);cin>>name[0]);

    cout<<"Please tell me your last name: ";//Ask for Last name
    for(cin>>name[1];!isname(name[1]);cin>>name[1]);//Validate Length
  //////////////////////////////////////////////////Program has users names///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



  /////////////////////////////////////////////////////Get accNum//////////////////////////////////////////
  accNum = accountNumber();

  //////////////////////////////////////////////////See if users are in database//////////////////////////////////////////////////
  ifstream database;
  database.open('accounts.txt');
  bool userFound=0;
  while(!database.eof())
  {string fn, ln, Anum;
    database>>fn;
    if(fn == name[0])
    {database>>ln;
      if(ln == name[1])
      {
        database>>accNum;
        if(Anum=accNum)
        {
          userFound=1;
          break;
        }
      }
    }
  }
database.close();
if(!userFound){
  cout<<"No record of that user exists, make an account?\n";
  char ans;
  while(1){
  cin>>ans;
  if (ans=='Y')
  {
    //Code for making an account
    break;
  }
  else if(ans=='N')
  {
    return 0;
  }
  else
  cout<<"Try Y or N";
}}



  ///////////////////////////////////////////////////Return sucessful////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout<<"Results OK, "<<name[0]<<" "<<name[1]<<" "<<accNum<<endl;//Reurn sucessful with users name

  accountBalance(name[0]+name[1]+accNum);
}


bool isname(string name){
  system("clear");
  bool isValid = true;
  if(!isupper(name[0])){
    isValid=false;
    cout<<"The first letter must be capitalized\n";}

  if ((2<name.length())&&(name.length()<10)){//Length is correct.
      for(int i=0;i<name.length();i++){
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
    else {
      isValid=false;//name is either too short or too long.
      cout<<"\nThis name must be between 2 and 10 charecters\n";
    }

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
  cout<<acounNum.length();
  if(11==acounNum.length())
    {
      acounNum.erase(3,1);
      acounNum.erase(6,1);//Remember that everything was shifted right one spot.
    }
    cout<<acounNum<<endl;
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



void accountBalance(string user){
  ofstream logging;
  logging.open((user+".log").c_str());
  //std::cin>>balance;
  while(1){
    int change,balance;
    char userInput;
    std::cout<<"Please select an option:\n";  //Ask the user to select an option
    std::cout<<"D is deposit\n";
    std::cout<<"W is withdraw\n";
    std::cout<<"S is for Show balance\n";
    std::cout<<"Q will exit"<<std::endl;      //Lists the options
    std::cin >> userInput;
    if (userInput > 91)                       //make any lowercase inputs Uppercase.
    userInput = userInput - 32;
    if (userInput == 'Q')                    //Leaves the loop if userInput is q or Q
    break;
    else if (userInput == 'D')                    //checks the input for D
    {
      std::cout <<"How much money would you like to deposit?\n";
      std::cin >> change;
      balance = balance + change;             //gets an input and increases the balance by it.
    }
    else if (userInput == 'W')                     //checks the input for W
    {
      std::cout <<"How much money would you like to withdraw?\n";
      std::cin >> change;                     //Asks the user how much they would like to withdraw
      if(balance - change < 0)
      {
        std::cout << "Your balance is too low to do that\n";//If the user doesnt have enough money, reject the transaction.
        userInput = 'S';//Show the user their balance
      }
      else//If the user has enough money, continue
      balance = balance - change;
    }
    else if (userInput == 'S'){
    std::cout << "Your current balance is: $" << balance << std::endl;
    std::cout <<std::endl<<std::endl;}
    else
    cout<< "I dont know that ability\n";//Return an error if the command isnt recognized.
  }
  logging.close();
}
