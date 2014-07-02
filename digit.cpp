#include <iostream>

int main()
{
	int t = -1;
	int digits = 0;

	while(t)
	{
		t /= 10;
		digits++;
	}

	std::cout << "number of digits is: " << digits << std::endl;

	return 0;
}