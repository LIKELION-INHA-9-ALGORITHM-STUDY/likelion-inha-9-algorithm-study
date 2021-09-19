#include<iostream>
#include <algorithm>
using namespace std;
long long len[10001] = { 0 };
/*
* 3번이랑 똑같은 코드 입니다.ㅎㅎ
*/
int main()
{
	long long K, N;
	cin >> K >> N;
	long long mean = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> len[i];
		mean += len[i];
	}
	if (K == 1)
	{
		cout << len[0] / N << endl;
		return 0;
	}
	mean = int(mean / K);
	sort(len, len + K);
	long long low = len[0] / N; long long high = mean;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long ans = 0;
		for (int i = 0; i < K; i++)
		{
			if (len[i] >= mid)
				ans += len[i] / mid;
		}

		if (ans >= N)
		{
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << high << endl;
	return 0;
}