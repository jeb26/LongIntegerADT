#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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

int main(void)
{
	string s("180270361023456789");
	bool complete = false;
	while(!complete)
	{
		if(s.length() <= 4)
		{
			char const* int_str = s.c_str();
			int data = atoi(int_str);

			//l->insert_left(data);

			cout << data << endl;
			
			complete = true;
		}
		else
		{
			int str_len = s.length();
			int location = (str_len - 4);

			std:string sub = s.substr(location, 4);
			s.erase(location, 4);
			
			char const* sub_int = sub.c_str();
			int data = atoi(sub_int);

			cout << data << endl;
			
			//l->insert_left(data);
		}
	}
	return 0;
}

/**
	Kevin Substring Solution

	#include <iostream>
	using namespace std;

	int main(){
	int a = 0;
	int b = 4;

	while(a <= 12) {
	       // do something...
	    cout << "a is: " << a << " b is: " << b << endl;
	       a += 4;
	       b += 4;
	}
	return 0;
}
**/