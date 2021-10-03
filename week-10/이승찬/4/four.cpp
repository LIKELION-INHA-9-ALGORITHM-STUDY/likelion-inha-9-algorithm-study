#include <iostream>
using namespace std;

int main()
{
	int number;
	int count = 0;
	cin >> number;
	for (int i = 1000; i >= 1; i--)
	{
		if ((number / (i * i)) >= 1) {
			number = number - (i * i);
			count += 1;
		}
	}
	cout << count << endl;
}