#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, R, G, B;
	cin >> N;

	cin >> R >> G >> B;
	vector<int> min = { R,G,B };
	// R의 경우, 그 전까지의 min[1]과 min[2]중 작은 값을 선택하여 새로운 R과 더해서 min[0]에 저장하자.
	// 다른 색의 경우에도 같은 방식으로.
	for (int i = 0; i < N - 1; i++) {
		cin >> R >> G >> B;
		if (min[1] < min[2]) R += min[1];
		else R += min[2];

		if (min[0] < min[2]) G += min[0];
		else G += min[2];

		if (min[0] < min[1]) B += min[0];
		else B += min[1];

		min[0] = R;
		min[1] = G;
		min[2] = B;
		// min[0~2]에 정수 삼각형 문제 처럼 거기까지 가는데 필요한 최소 비용을 저장해나가자.
	}
	sort(min.begin(), min.end());
	cout << min[0];
}