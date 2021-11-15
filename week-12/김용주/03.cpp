#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> num;
long long answer = 0;
//입력으로 받은 각 학생의 예상 등수의 값으로 오름차순으로 정렬하고 정렬한 배열에 순서대로 1~n등을 준다
int main()
{
	long long N;
	cin >> N;
	for (long long i = 0; i < N; i++)
	{
		long long number;
		cin >> number;
		num.push_back(number);
	}
	sort(num.begin(), num.end());
	for (long long i = 1; i <= N; i++)
	{
		answer += abs(i - num[i - 1]);
	}
	cout << answer << endl;
	return 0;
}