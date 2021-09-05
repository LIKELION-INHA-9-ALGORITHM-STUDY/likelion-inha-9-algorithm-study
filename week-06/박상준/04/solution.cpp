#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, score;
	cin >> n;

	vector<int> scores;
	for (int i = 0; i < n; i++) {
		cin >> score;
		scores.push_back(score);
	}

	vector<int> dp = { scores[0] }; // 첫 계단까지의 최대값.
	if (n > 1) dp.push_back(scores[0] + scores[1]); // 두번째 계단까지의 최대값.
	if (n > 2) dp.push_back(max(scores[0] + scores[2], scores[1] + scores[2])); // 세번째 계단까지의 최대값.
	for (int i = 3; i < n; i++) {
		// 규칙을 지키면서 i번째 계단까지 도달하기 위한 방법은 2가지가 있다.
		// 1) i-2번째 계단에서 두 계단을 오르기.
		// 2) i-3번재 계단에서 두 계단을 올라 i-1번째 계단에 도착하고, 거기서 한 계단을 오르기.
		// 이를 점화식으로 표현하면 아래와 같다.
		// 점화식 안세우고 이차원 벡터로 값 저장하면서 하다가 계속되는 메모리 초과에 고통받음ㅠ
		dp.push_back(max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]));
	}
	cout << dp[n - 1];
}