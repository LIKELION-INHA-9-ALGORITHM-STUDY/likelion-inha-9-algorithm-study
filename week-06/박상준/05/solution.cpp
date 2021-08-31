#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	// 삼각형의 각 칸을 그 칸까지 도달하면서 거치는 숫자의 최대값으로 만들자.
	int triangle_size = triangle.size();
	for (int i = 1; i < triangle_size; i++) {
		for (int j = 0; j < i + 1; j++) {
			// 왼쪽 끝 -> 대각선 오른쪽 위
			if (j == 0)  triangle[i][j] += triangle[i - 1][0];

			// 오른쪽 끝 -> 대각선 왼쪽 위
			else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];

			else {
				// 오른쪽과 왼쪽 중 더 큰 수
				if (triangle[i - 1][j - 1] >= triangle[i - 1][j]) triangle[i][j] += triangle[i - 1][j - 1];
				else triangle[i][j] += triangle[i - 1][j];
			}
		}
	}
	// 삼각형의 가장 아래 줄을 정렬해서 최대 값 찾기.
	sort(triangle[triangle_size - 1].begin(), triangle[triangle_size - 1].end());
	int answer = triangle[triangle_size - 1][triangle_size - 1];
	return answer;
}