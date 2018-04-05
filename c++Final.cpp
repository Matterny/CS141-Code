#include<iostream>
 #include<fstream>
 #include<string>
 #include<cmath>
 #include<cstdlib>
 using namespace std;
//Global functions
void drawMan(int);
void selectOption();

//global Variables
struct word{
  string catagory;
  string word;
  string hint1;
  string hint2;
};

word GuessingOption;

int main(){
  cout<<"Please tell me a catagory\n";//Replace with a menu of options
  cin>>GuessingOption.catagory;
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
  int x = rand() % 50;
  ifstream inputFile;
  inputFile.open(GuessingOption.catagory.c_str());
  string garbage;
  int i;
  while (i<x) {
    inputFile.getline(garbage);
    i++;
  }
  inputFile >>GuessingOption.word;

  inputFile.close();
}
