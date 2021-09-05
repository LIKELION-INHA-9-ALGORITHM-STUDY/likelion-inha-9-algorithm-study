#include <iostream>
using namespace std;

int main()
{
	int n;
	int a = 0;
	cin >> n;
	while ((n < 1) && (n >= 10 * 10 * 10 * 10 * 10 * 10))
	{
		cin >> n;
	}
	while (n != 1)
	{
		a += 1;
		if ((n % 3) == 0)
			n = n / 3;
		else if ((n % 2) == 0)
			n = n / 2;
		else
			n = n - 1;
	}
	cout << a << endl;
	return 0;
}