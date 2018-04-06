#include<iostream>
using namespace std;
int main()
{
  while(1){
  int x[5];
  int value;
  cout<<"\nIndex: ";
  cin>>value;
  cout<<endl<<x[value];
  cout<<"\nValue to set: ";
  cin>>x[value];
}
return 0;
}
