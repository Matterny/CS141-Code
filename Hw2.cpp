#include <iostream>
 #include <string>
 #include <fstream>
 #include <cstdlib>
 #include <stdio.h>
 #include <cmath>
using namespace std;
 bool isname(string name);
 string accountNumber();
 void accountBalance(string);
 void logtofile(string action,string accountNumber, float startingBalance, float change, float endingbalance);
 float getbalance(string);



int main(){
  ///////////////////////////////////////Declare Variables////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  string name[2],accNum;string accFile = "accounts.txt";//Declare An array called name, and a string called accNum
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
  ifstream dataFile;
  dataFile.open(accFile.c_str());
  if(!dataFile.is_open())
  {
    dataFile.close();
    ofstream database;
    database.open(accFile.c_str());
    database<<"FirstName LastName AccountNumber \n";
    database.close();
    dataFile.open(accFile.c_str());
  }
  bool userFound=0;
  while(!dataFile.eof())
  {string fn, ln, Anum;
    dataFile>>fn;
    if(fn == name[0])
    {dataFile>>ln;
      if(ln == name[1])
      {
        dataFile>>Anum;
        if(Anum==accNum)
        {
          userFound=1;
          break;
        }
      }
    }
  }
  dataFile.close();
  if(!userFound){
  cout<<"No record of that user exists, make an account?\n";
  char ans;
  while(1){
  cin>>ans;
  if (toupper(ans)=='Y')
  {
    //Code for making an account
    ofstream database;
    database.open(accFile.c_str(), ofstream::app);
    database<<name[0]<<" "<<name[1]<<" "<<accNum<<endl;
    cout<<"Initial Balance: \n";
    float balance;
    cin>>balance;
    string action = "AccountCreated";
    logtofile(action,accNum,0,balance,balance);
    //logtofile("action","accNum",balance,balance,balance);
    database.close();
    break;
  }
  else if(toupper(ans)=='N')
  {
    return 0;
  }
  else
  cout<<"Try Y or N";
  }}



  ///////////////////////////////////////////////////Return sucessful////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout<<"Results OK, "<<name[0]<<" "<<name[1]<<" "<<accNum<<endl;//Reurn sucessful with users name

  accountBalance(accNum);

  return 0;
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
  if(10==acounNum.length())
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

    if(acounNum.length()!=8)
    {
      isValid=false;
      std::cout<<"\nYour account number must be 9 or 11 charecters, depending on if you use hyphons\n";
    }
  }
  return acounNum;
}


void accountBalance(string userNum){
  while(1){
    system("clear");
    float change;
    float balance = getbalance(userNum);
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
      change = abs(change);
      logtofile("Deposit",userNum,balance,change,balance+change);
      balance = balance + change;             //gets an input and increases the balance by it.
    }
    else if (userInput == 'W')                     //checks the input for W
    {
      std::cout <<"How much money would you like to withdraw?\n";
      std::cin >> change;                     //Asks the user how much they would like to withdraw
      change = abs(change);
      if(balance - change < 0)
      {
        std::cout << "Your balance is too low to do that\n";//If the user doesnt have enough money, reject the transaction.
        userInput = 'S';//Show the user their balance
      }
      else//If the user has enough money, continue
      {
        logtofile("Withdraw",userNum,balance,change,balance-change);
        balance = balance - change;
      }
    }
    else if (userInput == 'S'){
    ifstream fileName;
    fileName.open("accountlogs.txt");
    while(!fileName.eof())
    { string logInfo[5];
      fileName>>logInfo[0]>>logInfo[1]>>logInfo[2]>>logInfo[3]>>logInfo[4];
    cout<<"\nAction: "<<logInfo[0];
    cout<<"\nStarting Balance: "<<logInfo[2];
    cout<<"\nTransaction Amount: "<<logInfo[3];
    cout<<"\nEnding Balance: "<<logInfo[4]<<endl<<endl<<endl;
  }
  cout<<"Enter anything to continue\n";
  string garbage;
  cin>>garbage;
    }
    else
    cout<< "I dont know that ability\n";//Return an error if the command isnt recognized.
  }
}


void logtofile(string action,string usrid,float start, float delta, float endpt){
  ofstream logging;
  logging.open("accountlogs.txt",ofstream::app);
  logging<<action<<" "<<usrid<<" "<<start<<" "<<delta<<" "<<endpt<<endl;
  logging.close();
}


float getbalance(string userNum){
  string i;
  float o;
  ifstream inputFile;
  inputFile.open("accountlogs.txt");
  for(inputFile>>i;i!=userNum;inputFile>>i)//Trash all valus until you get the accountnumber
  if(inputFile.eof())break;
  inputFile>>i;
  inputFile>>i;//Trash the next 2 values
  inputFile>>o;
  return o;
}
