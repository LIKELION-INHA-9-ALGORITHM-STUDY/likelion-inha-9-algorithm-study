#include <iostream>
using namespace std;

int main()
{
	int n;
	int a = 0;
	cin >> n;
	for (int i = 0; i <= 100; i++)
	{
		if (n == 1)
		{
			break;
			a += 1;
			if ((n % 3) == 0)
				n = n / 3;
			else if ((n % 2) == 0)
				n = n / 2;
			else
				n = m - 1;
		}
	}
	cout << a << endl;
	return 0;
}