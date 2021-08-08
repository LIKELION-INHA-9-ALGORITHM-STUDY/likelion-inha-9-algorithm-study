#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end());

	int size = citations.size(), answer = 0;
	for (int i = 0; i < size; i++) {
		if (citations[i] >= size - i) {
			// 남은 인덱스의 개수가 정렬된 현재 값보다 작거나 같아지면. 남은 인덱스의 개수가 h
			answer = size - i;
			break;
		}
	}
	return answer;
}