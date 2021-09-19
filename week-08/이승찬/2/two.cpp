#include <iostream>
#include <algorithm>
using namespace std;
#define Max 500001

int N, M;
int SNum[Max];


int LowerBound(int card) {
	int mid, low, high;
	low = 0;
	high = N - 1;

	while (low < high) {
		mid = (low + high) / 2;
		if (SNum[mid] >= card)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}


int UpperBound(int card) {
	int mid, low, high;
	low = 0;
	high = N - 1;

	while (low < high) {
		mid = (low + high) / 2;
		if (SNum[mid] > card)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

void solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> SNum[i];
	}
	sort(SNum, SNum + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int card;
		cin >> card;

		int lower = LowerBound(card);
		int upper = UpperBound(card);

		if (upper == N - 1 && card == SNum[N - 1])
			upper++;
		cout << upper - lower << ' ';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solution();
	return 0;
}