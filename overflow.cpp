#include <iostream>

int digit(int t)
{
	int num = t;
	int digits = 0;

	while(num)
	{
		num /= 10;
		digits++;
	}
	return digits;
}

int over_flow(int *t)
{
	int num = *t;
	int digits = digit(num);

	if(digits <= 4)
	{
		return 0;
	}
	else
	{
		int permitted = *t % 10000;
		int overflow = *t / 10000;
		*t = permitted;
		return overflow;
	}
}

int main()
{
	int t = 99999999;
	//int digits = 0;

	int overflow = over_flow(&t);

	std::cout << "t is: " << t << " overflow is: " << overflow << std::endl;

	return 0;
}