#include<iostream>
 #include<fstream>
 #include<cstdlib>
 #include<string>
 #include<cmath>
 using namespace std;
//Global functions
void drawMan(int);
void selectOption();
bool guessInWord(char);
void guessingGame();
//Global Macros. Not 100% needed, but I'm not willing to go without for this.
#define FileSize 7    //Can be made larger, IF the files are all increased in size by 1 line.
#define cinToUpper    cin>>option;for(int i=0;i<option.length();i++)option[i]=toupper(option[i])
//global Variables
struct word{
  string catagory;
  string word;
  string hint1;
  string hint2;
};

word GuessingOption;

int main(){
  while(1){
  selectOption();
  guessingGame();

  cout<<"Play again?\n";
  char answer;
  cin>>answer;
  if(toupper(answer)!='Y'){
    break;
  }
}}

void drawMan(int stage){//Draw the man hanging, with 6 being perfect and 0 being dead.
  switch (stage) {
    case 0:
        cout
        <<" _____________"<<endl
        <<  "|         |" << endl
        <<  "|         0" << endl
        <<  "|        /|\\ " << endl
        <<  "|        / \\ " << endl
        <<  "|" << endl
        <<  "|" << endl;
        break;
    case 1:
        cout
        <<" _____________"<<endl
        <<  "|         |" << endl
        <<  "|         0" << endl
        <<  "|        /|\\ " << endl
        <<  "|        /  " << endl
        <<  "|" << endl
        <<  "|" << endl;
        break;
    case 2:
        cout
        <<" _____________"<<endl
        <<  "|         |" << endl
        <<  "|         0" << endl
        <<  "|        /|\\ " << endl
        <<  "|         " << endl
        <<  "|" << endl
        <<  "|" << endl;
        break;
    case 3:
            cout
            <<" _____________"<<endl
            <<  "|         | " << endl
            <<  "|         0 " << endl
            <<  "|        /| " << endl
            <<  "|           " << endl
            <<  "|" << endl
            <<  "|" << endl;
            break;
    case 4:
            cout
            <<" _____________"<<endl
            <<  "|         | " << endl
            <<  "|         0 " << endl
            <<  "|         | " << endl
            <<  "|           " << endl
            <<  "|" << endl
            <<  "|" << endl;
            break;
    case 5:
            cout
            <<" _____________"<<endl
            <<  "|         | " << endl
            <<  "|         0 " << endl
            <<  "|           " << endl
            <<  "|           " << endl
            <<  "|" << endl
            <<  "|" << endl;
            break;
    case 6:
                cout
                <<" _____________"<<endl
                <<  "|           " << endl
                <<  "|           " << endl
                <<  "|           " << endl
                <<  "|           " << endl
                <<  "|" << endl
                <<  "|" << endl;
                break;
  }
}

void selectOption(){
  while(1){
    system("clear");
    cout<<"Please Select a catagory from the list below\n";
    cout<<"Sports\nStates\nProgramming\nClarkson\nMath\n";//List the 5 options for the user
    string option;
    cinToUpper;
    if(option == "SPORTS"){
      GuessingOption.catagory = "sports.txt";
      break;
    }
    else if(option == "STATES"){
      GuessingOption.catagory = "states.txt";
      break;
    }
    else if(option == "PROGRAMMING"){
      GuessingOption.catagory = "programming.txt";
      break;
    }
    else if(option == "CLARKSON"){
      GuessingOption.catagory = "clarkson.txt";
      break;
    }
    else if(option == "MATH"){
      GuessingOption.catagory = "math.txt";
      break;
    }
  }
  int x = rand() % FileSize;
  ifstream inputFile;
  inputFile.open(GuessingOption.catagory.c_str());
  int i;
  string garbage;
  while (i<=x) {
    getline(inputFile,garbage);
    i++;
  }
  inputFile >>GuessingOption.word>>GuessingOption.hint1>>GuessingOption.hint2;

  inputFile.close();
}

bool guessInWord(char guess){
  if(GuessingOption.word.find(guess) != std::string::npos)return 1;
  return 0;
}
void guessingGame(){
  int badTries = 6;
  string prevTries = "";
  while (badTries>0){
    system("clear");
    cout<<"Past tries: "<<prevTries<<endl;
    cout<<"The catagory is inside the file: " << GuessingOption.catagory<<endl;
    if(badTries<3)cout<<"First hint: "<<GuessingOption.hint1<<endl;
    if(badTries<2)cout<<"Last hint: "<<GuessingOption.hint2<<endl;
    cout<<"Please guess a letter: \n";
    drawMan(badTries);
    char guess;
    cin>>guess;
    if(guessInWord(guess)){
      prevTries = prevTries+guess;
    }
    else{
      badTries--;
    }
  }
}
