#include <vector>
#include <iostream>

using namespace std;

// i와 i-1을 비교해서 같지 않은 것만 answer에 추가했습니다.
vector<int> solution(vector<int> arr)
{
	int arrLen = arr.size();
	vector<int> answer;
	answer.push_back(arr[0]);
	for (int i = 1; i < arrLen; i++) {
		if (arr[i - 1] != arr[i])
			answer.push_back(arr[i]);
	}
	return answer;
}