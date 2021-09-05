#include <iostream>
#include <algorithm>
using namespace std;
//3개의 계단을 오르는것 자체가 안되니까 i-2에서 두계단을 한번에 오르는 경우
//i-3번째에서 i-1번째로 퐁당한 후에 연속 계단 오르는 경우 중 max값을 찾으면된다
int main()
{
	int n;
	int stair[301] = { 0 };
	int dp[301] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	int count = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
	}
	cout << dp[n] << endl;
	return 0;
}