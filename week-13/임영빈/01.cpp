#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> card_q;
	int N;
	
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		card_q.push(i);
	while (card_q.size() > 1) {
		card_q.pop();
		card_q.push(card_q.front());
		card_q.pop();
	}
	cout << card_q.front();
}