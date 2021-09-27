#include <iostream>
#include <string>
#include <stack>
using namespace std;

// NO를 출력하는 경우: 스택의 맨 위에 있는 수(stack.top()보다 꺼내야 하는 수가 작을 때

int main() {
	int n;
	cin >> n;
	stack<int> s;
	string ans;
	int top{ 0 }; // 마지막으로 들어간 수(push한 횟수) (!= stack.top())

	for (int i{ 0 }; i < n; i++) {
		int a;
		cin >> a;
		if (a > top) { // a >= top 으로 하면 a = top 인 경우 top이 한 번 더 들어가게 됨
			for (int j{ top + 1 }; j <= a; j++) {
				s.push(j);
				ans += '+';
				top++;
			}
			s.pop();
			ans += '-';
		}
		else {
			if (a == top) {
				s.pop();
				ans += '-';
			}
			else {
				if(a == s.top()) {
					s.pop();
					ans += '-';
				}
				else {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	for (char a : ans) {
		cout << a << "\n";
	}
	return 0;
}
