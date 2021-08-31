#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> dp = { 1,2,4 };
	int i = 2;
	while (i < 9) {
		// 주어지는 수가 11보다 작기 때문에 10까지의 값만 저장한다.
		// 4번째 값 부터는 (1 + i-1을 표현하는 방법)에 해당하는 값들 + (2 + i-2를 표현하는 방법) + (3 + i-3을 표현하는 방법) ....
		// 위의 규칙이 성립하여 아래와 같은 점화식이 성립한다. (위의 1, 2, 3의 수들은 각 방법의 맨 앞에 위치한다.) 
		dp.push_back(dp[i - 2] + dp[i - 1] + dp[i]);
		i++;
	}

	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n - 1] << "\n";
	}
}