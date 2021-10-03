#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int house = 0;
	cin >> house;
	int rgb[3][1001] = { 0 };
	for (int i = 0; i < house; i++)
	{
		int R, G, B;
		cin >> R >> G >> B;
		if (i == 0)
		{
			rgb[0][0] = R; rgb[1][0] = G; rgb[2][0] = B;
		}
		else
		{
			rgb[0][i] = min(rgb[1][i - 1], rgb[2][i - 1]) + R;
			rgb[1][i] = min(rgb[0][i - 1], rgb[2][i - 1]) + G;
			rgb[2][i] = min(rgb[0][i - 1], rgb[1][i - 1]) + B;
		}
	}
	int answer = min(min(rgb[0][house - 1], rgb[1][house - 1]), rgb[2][house - 1]);
	cout << answer << endl;
	return 0;
}