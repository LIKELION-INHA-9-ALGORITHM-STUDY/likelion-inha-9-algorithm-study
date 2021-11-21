#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) q.push(i);

	while (q.size() > 1) {
		q.pop();
		int repushed = q.front();
		q.pop();
		q.push(repushed);
	}

	cout << q.front();
}