#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
	int supo1[5] = { 1, 2, 3, 4, 5 };
	int supo2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int supo3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int supos[3] = { 0,0,0 };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == supo1[i % 5]) supos[0]++;
		if (answers[i] == supo2[i % 8]) supos[1]++;
		if (answers[i] == supo3[i % 10]) supos[2]++;
	}

	vector<int> answer;

	//1번 수포자 vs 2번 수포자
	if (supos[0] >= supos[1]) {
		answer.push_back(1); // 1번 >= 2번
		if (supos[0] == supos[1]) answer.push_back(2); // 1번 == 2번
	}
	else answer.push_back(2); // 1번 < 2번

	// 앞 2명과 3번 수포자 처리
	if (supos[answer[answer.size() - 1] - 1] <= supos[2]) {
		// 위의 결과 <= 3번 
		if (supos[answer[answer.size() - 1] - 1] < supos[2]) answer.clear(); // 위의 결과 < 3번 -> 위의 결과 지움.
		answer.push_back(3);
	}
	return answer;
}