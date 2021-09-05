#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		// 입력된 수가 1인 경우 바로 끝.
		cout << 0;
		return 0;
	}

	vector<vector<int>> dp = { {N} };
	// dp의 n번째 인덱스에 해당하는 벡터는 n번의 연산을 통해 만들 수 있는 숫자들.
	int flag = 0, cnt = 0; // 1이 만들어졌는지 판별하기 위한 flag와 연산 횟수 cnt
	while (true) {
		vector<int> temp;
		int size = dp[0].size();
		for (int j = 0; j < size; j++) {
			int current = dp[0][j];
			if (current == 2 || current == 3) {
				flag = 1;
				break;
				// 2거나 3인경우 1이 만들어지기 때문에 종료.
			}

			if (current % 3 == 0) temp.push_back(current / 3);
			if (current % 2 == 0) temp.push_back(current / 2);
			if (N > 1) temp.push_back(current - 1);
			// 연산을 통해 만들어지는 숫자들을 temp에 저장.
		}
		if (flag == 1) break;

		// 1이 안만들어져서 flag가 0이면,
		cnt++;  // 횟수 증가
		dp.push_back(temp); // 연산으로 만들어진 수들 dp에 넣기.
		dp.erase(dp.begin()); // 기존 dp는 필요 없으니 지우기.
	}
	cout << cnt + 1;
	// current가 2나 3이 된 경우에 종료하여 이들을 1로 만드는 연산을 하지 않았기 때문에 + 1
}