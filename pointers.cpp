#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
  int* intPtr;
  int beta,gamma;
   intPtr = &beta;
  *intPtr = 28;
  std::cout<<beta<<endl<<intPtr<<gamma;
}
