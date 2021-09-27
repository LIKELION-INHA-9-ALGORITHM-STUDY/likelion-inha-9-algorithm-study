#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<vector<int>> paper;
	int answer[3] = { 0,0,0 }, N, input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		paper.push_back({});
		for (int j = 0; j < N; j++) {
			cin >> input;
			paper[i].push_back(input);
		}
	}

	int use = 0, current = N, cut = 0;
	while (current >= 3) {
		// current : 현재 한 변의 길이. 3x3으로 잘릴때까지 반복
		int startx = 0, starty = 0;
		for (int i = 0; i < pow(3, cut * 2); i++) {
			int first = paper[starty][startx], flag = 0;

			if (first == -2) continue;

			for (int j = starty; j < starty + current; j++) {
				for (int k = startx; k < startx + current; k++) {
					if (first != paper[j][k]) {
						// 그 종이가 같은 값으로 이루어져 있지 않으면
						flag = 1;
						break;
					}
				}
			}

			if (flag == 0) {
				// 종이가 같은 값으로 이루어져 있는 경우
				answer[first + 1]++;
				for (int j = starty; j < starty + current; j++) {
					for (int k = startx; k < startx + current; k++) {
						// 사용한 종이이므로 -2로 값 바꿔서 사용 표시.
						paper[j][k] = -2;
					}
				}
			}

			startx += current;
			if (startx >= N) {
				// 행 바꾸기.
				startx = 0;
				starty += current;
			}
		}
		cut++;
		current = current / 3;
		// 종이를 잘라준다 -> 한 변의 길이 / 3
	}
	// 반복문을 탈출하면 이제 1 x 1 크기만 남는다. -> 다 돌면서 확인해주자.

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 1 x 1 크기의 종이 값들 확인.
			if (paper[i][j] != -2) answer[paper[i][j] + 1]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << answer[i] << "\n";
	}
}