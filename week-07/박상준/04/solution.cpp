#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int target) {
	vector<vector<int>> triangle = { {0} };
	// 루트(0)에서부터 나오는 수의 +와 - 연산의 결과값을 자식으로 갖는 이진 트리.
	// 삼각형의 가장 아래 층에서 타겟 넘버의 수 세기.
	for (int i = 0; i < numbers.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < triangle[i].size(); j++) {
			temp.push_back(triangle[i][j] + numbers[i]);
			temp.push_back(triangle[i][j] - numbers[i]);
		}
		triangle.push_back(temp);
	}

	int lastIndex = triangle.size() - 1, answer = 0;
	for (int i = 0; i < triangle[lastIndex].size(); i++) {
		if (triangle[lastIndex][i] == target) answer++;
	}
	return answer;
}