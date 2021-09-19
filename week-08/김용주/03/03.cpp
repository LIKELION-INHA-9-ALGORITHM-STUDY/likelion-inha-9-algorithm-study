#include<iostream>
#include <algorithm>
using namespace std;
long long len[1000001] = { 0 };
/*
* 사실 매개변수 탐색이 뭔지 찾아보고 풀었습니다. ㅎㅎ start는 무조건 가능한 경우 end는 무조건 불가능한 경우라고 하더라고요
* 근데 이 문제에서는 start는 무조건 가능하도록 end는 가능할 수 있을 것 같은 것중 가장 큰 값이라는 생각으로 문제를 풀었습니다.
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
			low = mid + 1; //최대를 찾아야하니까 기존에 통과한거의 +1
		}
		else
			high = mid - 1; //통과 못한 거의 바로 밑에 거 찾아보기
	}
	cout << high << endl;
	return 0;
}