#include<iostream>
 #include<fstream>
 #include<cstdlib>
 #include<string>
 #include<cmath>
 using namespace std;
//Global functions
void drawMan(int);
void selectOption();

//Global Macros. Not 100% needed, but I'm not willing to go without for this. 
#define FileSize 50
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
  selectOption();
  drawMan(4);
}

void drawMan(int stage){
  //Draw the man hanging, with 6 being perfect and 0 being dead.
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
