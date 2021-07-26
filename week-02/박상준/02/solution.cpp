#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	queue<int> days; // 각 기능 개발에 소요될 일수를 담을 큐

	int size = progresses.size();
	for (int i = 0; i < size; i++) {
		int day = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i] != 0) day++;
		//각 기능 개발에 소요되는 일수 계산
		days.push(day);
	}

	vector<int> answer;
	while (!days.empty()) {
		int pop = 1, front = days.front();
		days.pop(); // 맨 앞 기능 배포.
		while (!days.empty() && front >= days.front()) {
			days.pop();
			pop++;
			// 뒤 기능들의 소요 일수가 작거나 같은 경우 함께 배포.
		}
		answer.push_back(pop);
	}
	return answer;
}