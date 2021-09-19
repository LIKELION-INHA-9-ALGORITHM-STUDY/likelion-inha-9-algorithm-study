
#include <iostream>
#include<algorithm>
using namespace std;
int N, M; int tmp;
int A[100000];

int binarysearch(int x) {
	int start = 0;
	int end = N - 1;
	while (start <= end) {
		int center = (start + end) / 2;
		if (x == A[center])
			return 1;
		else if (x > A[center]) {
			start = center + 1;
		}
		else {
			end = center - 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << binarysearch(tmp) << "\n";
	}
}
