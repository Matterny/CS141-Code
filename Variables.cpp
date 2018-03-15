#include <iostream>

int main()
{
  const char FPS = 30.25;
  const char movieLen = 100;
  short movieFrames = FPS*movieLen;
  std::cout << float(FPS) << std::endl;   // % operator returns the remander
  //std::cout << population << std::endl;
  return 0;
}
