#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;

	cin >> N;
	int* cards = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num;
		cards[i] = num;
	}
	sort(cards, cards + N);

	int* p, * q;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		p = lower_bound(cards, cards + N, num); // num의 첫 위치 찾기.
		q = upper_bound(cards, cards + N, num); // num보다 큰 수중 가장 작은 수(?)의 위치 찾기.
		cout << q - p << " "; // 빼주면 몇개인지 나옴.
	}
}