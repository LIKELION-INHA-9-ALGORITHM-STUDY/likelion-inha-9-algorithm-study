#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	vector<int> toMake;
	int n, input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		toMake.push_back(input);
	}

	stack<int> stack;
	vector<char> answer;
	int index = 0, cnt = 1;
	while (cnt <= n) {
		// 1부터 n까지 순서대로 들어간다.
		if (!stack.empty() && stack.top() == toMake[index]) {
			// 스택이 비었거나, 현재 탑이 나와야 하는 경우
			stack.pop();
			answer.push_back('-');
			index++;
		}

		else {
			// cnt를 그냥 스택에 넣는 경우
			stack.push(cnt++);
			answer.push_back('+');
		}
	}
	// n까지 스택에 넣고 반복문을 탈출하면 스택에 남아있는 수들이 존재한다.

	int flag = 0;
	while (!stack.empty()) {
		// 스택에 남은 수가 없을 때까지
		if (stack.top() == toMake[index++]) {
			// 탑에 있는 수가 나와야 할 수면 꺼내기.
			stack.pop();
			answer.push_back('-');
		}

		else {
			//탑에 있는 수가 나와야 할 수가 아니면, 새로운 수의 유입이 없으므로 그 수열은 못 만든다.
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		// 만들 수 있는 수열인 경우
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
	}
	else cout << "NO"; // 못 만드는 수열인 경우
}