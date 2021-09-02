#include <iostream>
#include <algorithm>
using namespace std;
//1,2,3은 이미 정해져있으니까 dp에 값을 넣어두고 4부터 3으로 나누어 떻어지는 경우, 2로 나누어 떨어지는 경우, 그 외경우로 나누어 
//3으로 나눈 값 , 2로 나눈 값, 1을 뺀 값 중 최소를 찾도록 하였습니다. 그 중 3,2로 나누어 떨어지는 경우에는 그 중에서 가장 최소를 찾도록 합니다
long long dp[1000001] = { 0 };

int main()
{
	long long n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (long long i = 4; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
			if (i % 2 == 0)
				dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		else
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[n] << endl;
	return 0;
}