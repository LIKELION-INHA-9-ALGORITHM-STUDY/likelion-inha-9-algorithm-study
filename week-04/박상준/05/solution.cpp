#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<char>> candies;
	int n, max = 1;
	char input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < n; j++) {
			cin >> input;
			temp.push_back(input);
		}
		candies.push_back(temp);
	}

	// 가로에 대한 확인
	for (int i = 0; i < n; i++) {
		char current = candies[i][0];
		int cnt = 1, change = 0;
		// if (max == n) break;

		for (int j = 1; j < n; j++) {
			if (current == candies[i][j]) cnt++; // 같은 값이 연속되는 경우
			else {
				if (change == 0 && ((i > 0 && current == candies[i - 1][j]) || (i < n - 1 && current == candies[i + 1][j]) || (j < n - 1 && current == candies[i][j + 1]))) {
					// 바꿀수 있는 경우
					cnt++;
					change = 1;
					if ((i==0||(i > 0 && current != candies[i - 1][j])) && (i==n-1||(i < n - 1 && current != candies[i + 1][j])) && (j < n - 1 && current == candies[i][j + 1])) {
						// 진행 방향이랑 바꾼 경우 -> 그게 마지막임
						if (max < cnt) max = cnt;
						current = candies[i][j];
						change = 0;
						cnt = 1;
						if ((i > 0 && current == candies[i - 1][j - 1]) || (j > 1 && current == candies[i][j - 2]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
							// 갱신된 current의 앞에서 바꿔올 수 있는 경우
							change = 1;
							cnt++;
						}
					}
					else {
						// 바꾼 경우 얼마나 가는지 확인
						while (j + change < n && current == candies[i][j + change]) {
							cnt++;
							change++;
						}
						if (max < cnt) max = cnt;
						cnt = 1;
						change = 0;
						current = candies[i][j];
						if ((i > 0 && current == candies[i - 1][j - 1]) || (j > 1 && current == candies[i][j - 2]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
							// 갱신된 current의 앞에서 바꿔올 수 있는 경우
							change = 1;
							cnt++;
							if ((i > 0 && current == candies[i - 1][j - 1]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
								// 위나 아래에서 가져온 경우
								int checkFront = j - 2;
								while (checkFront >= 0 && candies[i][checkFront--] == current) {
									cnt++;
								}
							}
						}
					}
				}
				else {
					// 못바꾸는 경우.
					current = candies[i][j];
					change = 0;
					cnt = 1;
					if ((i > 0 && current == candies[i - 1][j - 1]) || (j > 1 && current == candies[i][j - 2]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
						// 갱신된 current의 앞에서 바꿔올 수 있는 경우
						change = 1;
						cnt++;
						if ((i > 0 && current == candies[i - 1][j - 1]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
							int checkFront = j - 2;
							while (checkFront >= 0 && candies[i][checkFront--] == current) {
								cnt++;
							}
						}
					}
				}
			}
			if (max < cnt) max = cnt;
		}
	}

	if (max == n) {
		// 가로에서 최대값 나왔으면 더 확인할 필요 없음.
		cout << max;
		return 0;
	}

	// 세로에 대한 확인
	for (int i = 0; i < n; i++) {
		char current = candies[0][i];
		int cnt = 1, change = 0;
		if (max == n) break;

		for (int j = 1; j < n; j++) {
			if (current == candies[j][i]) cnt++; // 같은 값이 연속되는 경우
			else {
				if (change == 0 && ((i > 0 && current == candies[j][i - 1]) || (i < n - 1 && current == candies[j][i + 1]) || (j < n - 1 && current == candies[j + 1][i]))) {
					// 바꿀수 있는 경우
					cnt++;
					change = 1;
					if ((i==0||(i > 0 && current != candies[j][i - 1])) && (i==n-1||(i < n - 1 && current != candies[j][i + 1])) && (j < n - 1 && current == candies[j + 1][i])) {
						// 진행 방향이랑 바꾼 경우 -> 그게 마지막임
						if (max < cnt) max = cnt;
						current = candies[j][i];
						change = 0;
						cnt = 1;
					}
					else {
						// 바꾼 경우 얼마나 가는지 확인
						while (j + change < n && current == candies[j + change][i]) {
							cnt++;
							change++;
						}
						if (max < cnt) max = cnt;
						cnt = 1;
						change = 0;
						current = candies[j][i];
						if ((i > 0 && current == candies[j - 1][i - 1]) || (j > 1 && current == candies[j - 2][i]) || (i < n - 1 && current == candies[j - 1][i + 1])) {
							// 갱신된 current의 앞에서 바꿔올 수 있는 경우
							change = 1;
							cnt++;
							if ((i > 0 && current == candies[j - 1][i - 1]) || (i < n - 1 && current == candies[j - 1][i + 1])) {
								// 왼쪽이나 오른쪽에서 가져온 경우
								int checkFront = j - 2;
								while (checkFront >= 0 && candies[checkFront--][i] == current) {
									cnt++;
								}
							}
						}
					}
				}
				else {
					// 못바꾸는 경우.
					current = candies[j][i];
					change = 0;
					cnt = 1;
					if ((i > 0 && current == candies[j - 1][i - 1]) || (j > 1 && current == candies[j - 2][i]) || (i < n - 1 && current == candies[j - 1][i + 1])) {
						// 갱신된 current의 앞에서 바꿔올 수 있는 경우
						change = 1;
						cnt++;
					}
				}
			}
			if (max < cnt) max = cnt;
		}
	}
	cout << max;
}