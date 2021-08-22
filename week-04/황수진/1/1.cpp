#include <string>
#include <vector>

using namespace std;
int first[5] = { 1,2,3,4,5 };
int second[8] = { 2,1,2,3,2,4,2,5 };
int third[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int score[3] = { 0,0,0 };
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == first[i % 5]) score[0]++;
		if (answers[i] == second[i % 8]) score[1]++;
		if (answers[i] == third[i % 10]) score[2]++;
	}

	int max = score[0];
	for (int i = 1; i < 3; i++) {
		if (score[i] >= max)
			max = score[i];
	}

	for (int i = 0; i < 3; i++) {
		if (score[i] == max)
			answer.push_back(i + 1);
	}

	return answer;
}