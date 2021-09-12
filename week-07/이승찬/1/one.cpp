#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	int numone, numtwo, numthree;
	int beforeplusone, beforeplustwo, beforeplusthree;
	int plus=0;
	int count = 0;
	int counts = 0;
	cout << "첫번째 숫자를 입력하시오 : ";
	cin >> a;
	cout << endl;
	cout << "몇 제곱을 할까요? : ";
	cin >> b;
	cout << endl;

	int go = 0;
	int num[101];
	num[0] = a;
	for (int z = 0; z <= 100; z++)
	{
		if ((a / 100) < 1)
		{
			numone = a / 10;
			numtwo = a % 10;
			beforeplusone = pow(numone, b);
			beforeplustwo = pow(numtwo, b);
			plus = beforeplusone + beforeplustwo;
			num[z] = plus;
			a = plus;
		}
		else
		{
			numone = a / 100;
			numtwo = (a / 10)%10;
			numthree = a % 10;
			beforeplusone = pow(numone, b);
			beforeplustwo = pow(numtwo, b);
			beforeplusthree = pow(numthree, b);
			plus = beforeplusone + beforeplustwo + beforeplusthree;
			num[z] = plus;
			a = plus;
		}
		count++;
		for (int z = 0; z < (count-1); z++)
		{
			if (plus == num[z])
				go = 1000;
		}
		if (go == 1000)
			break;
	}
	for (int z = 0; z <= 100; z++)
	{
		if (num[z] == plus)
			break;
		counts++;
	}
	cout << counts+1 << endl;
	return 0;
}