#include <iostream>
using namespace std;

int main() {
	int n, m, b;
	cin >> n >> m >> b;
	int minTime{ 2000000000 };
	int maxheight;
	int map[500][500];

	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < m; j++) {
			cin >> map[i][j];
		}
	}
	// map 초기화

	for (int i{ 0 }; i <= 256; i++) { // 모두 i의 높이로 블럭을 맞춘다
		// 모든 i의 경우 탐색하면서 최소 시간, 최대 높이인 경우 출력
		int build{ 0 }; // 블럭 쌓기
		int remove{ 0 }; // 블럭 제거
		for (int j{ 0 }; j < n; j++) {
			for (int k{ 0 }; k < m; k++) {
				int di = map[j][k] - i;
				if (di < 0) {
					build -= di;
				}
				else if (di > 0) {
					remove += di;
				}
			}
		}
		if (remove + b >= build) {
			// [제거할 블럭 + 가지고 있는 블럭 >= 쌓을 블럭] 일 때
			int time = remove * 2 + build;
			if (minTime >= time) {
				minTime = time;
				maxheight = i;
			}
		}
	}
	cout << minTime << " " << maxheight << endl;
	return 0;
}