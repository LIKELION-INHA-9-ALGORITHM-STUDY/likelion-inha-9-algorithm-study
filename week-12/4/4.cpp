#include <iostream>
using namespace std;
#include<stack>
int answer;
int main() {
	int n, k;
	cin >> n >> k;
	stack<int> s;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.push(tmp);
	}
	while (k) {
		if (s.top() <= k) {
			answer += k / s.top();
			k %= s.top();
		}
		s.pop();
	}

	cout << answer;
}