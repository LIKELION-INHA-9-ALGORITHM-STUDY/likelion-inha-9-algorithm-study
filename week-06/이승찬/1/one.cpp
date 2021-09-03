#include <iostream>
using namespace std;

int main()
{
	int a;
	int first = 0;
	int second = 1;
	int newnum = 0;
	cin >> a;
	if (a <= 90)
	{
		for (int i = 1; i <= a; i++)
		{
			first = second;
			second = newnum;
			newnum = first + second;
		}
		cout << newnum << endl;
	}
	return 0;
}