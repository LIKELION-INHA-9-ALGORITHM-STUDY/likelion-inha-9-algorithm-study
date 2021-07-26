#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	stack<int> indexes;
	vector<int> answer;

	int priceSize = prices.size();
	for (int i = 0; i < priceSize; i++) {
		answer.push_back(priceSize - 1 - i); // 가격이 끝까지 떨어지지 않는다고 가정하고 최대값으로 초기화.

		if (indexes.empty()) indexes.push(i);
		else {
			while (prices[indexes.top()] > prices[i]) { // 가격이 떨어진 경우 while문으로 들어감.
				answer[indexes.top()] = i - indexes.top();
				// 최대값으로 초기화했던 answer의 해당 인덱스 값을 떨어지지 않은 기간으로 수정.
				indexes.pop(); // 떨어진 인덱스 삭제.
				if (indexes.empty()) break;
				// 앞의 인덱스들을 저장한 스택이 비거나, 떨어지지 않았을 때까지 반복.
			}
			indexes.push(i);
		}
	}
	// for 문을 탈출했을때, 가격이 떨어지지 않은 경우는 처음에 초기화했던 최대값 유지. 
	// 떨어진 경우는 while문에서 떨어지지 않은 기간으로 수정됨.
	return answer;
}