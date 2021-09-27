#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	// 시간이 작은 경우가 앞으로, 시간이 같다면 높이가 높은 경우가 앞으로.
	if (a[0] == b[0]) return a[1] > b[1];
	else return a[0] < b[0];
}

int main() {
	int N, M, B, input;

	cin >> N >> M >> B;

	vector<vector<int>> space;
	for (int i = 0; i < N; i++) {
		space.push_back({});
		for (int j = 0; j < M; j++) {
			cin >> input;
			space[i].push_back(input);
		}
	}

	vector<vector<int>> results;
	for (int i = 256; i >= 0; i--) {
		// 땅의 최대 높이 256부터 확인해보자.
		int duration = 0, inven = B;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (space[j][k] > i) {
					// 해당 칸의 높이가 만들 높이보다 높은 경우.
					inven += space[j][k] - i;
					// 높은 만큼 블록을 제거해서 인벤토리에 넣기
					duration += 2 * (space[j][k] - i);
					// 제거한 블록*2 만큼 소요 시간 추가.
				}

				if (space[j][k] < i) {
					// 해당 칸의 높이가 만들 높이보다 작은 경우.
					inven -= i - space[j][k];
					// 인벤에서 필요한 블록만큼 꺼내기
					duration += i - space[j][k];
					// 쌓은 블록만큼 소요시간 추가
				}
			}
		}

		if (inven >= 0) {
			// 연산 후 인벤토리에 있는 블럭이 0 이상이면 그 높이를 만들 수 있고, 0 미만이면 못 만드는 높이이다.
			if (!results.empty() && duration > results[results.size() - 1][0]) break;
			// 소요시간이 커지는 상황이 발생하면 그 직전이 최소값이다. 다시 내려가는 일은 없다.
			results.push_back({ duration,i });
		}
	}

	sort(results.begin(), results.end(), compare);
	cout << results[0][0] << " " << results[0][1];
}