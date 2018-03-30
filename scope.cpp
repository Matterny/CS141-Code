#include<iostream>
#include<cmath>
#include<limits>
using namespace std;

float TAXRATE = 0.4;
float newTaxRate(float);
float squareRoot(float);
int main()
{
  float initialValue = -1;
float pay = 50000;
cin>>pay;
while(cin.fail())
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),"\n");
  cout<<"\ntry a number: \n"
  cin>>pay;
}
pay = newTaxRate(pay);

cout<<pay<<endl;

cout<<TAXRATE<<endl;


cout<<squareRoot(0);

return 0;
}

float newTaxRate(float pay)
{
static float TAXRATE=0.3 ;
pay=pay-pay*TAXRATE;
cout<<TAXRATE<<endl<<pay<<endl;
return pay;
}

float squareRoot(float input)
{
  return sqrt(input);
}
