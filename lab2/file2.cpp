#include<iostream>

int main()
{
	short numerator = 5;
	short denominator = 2;
	float result = numerator / float(denominator);

	std::cout << numerator << " divided by " << denominator << " = " << result << std::endl;

	return 0;
}
