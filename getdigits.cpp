#include <iostream>
using namespace std;

int main()
{
	int test = 123456789;

	while(test)
	{
		int curr_digit = test % 10;
		cout << "digit: " << curr_digit << endl;
		test /= 10;
	}

	return 0;
}