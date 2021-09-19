#include <iostream>
using namespace std;
#include <algorithm>

int arr[500000];
int N; int M; int tmp;
int rightIndex; int leftIndex;

int minIndex(int*arr, int value, int size) {
	int start = 0;
	int end = size - 1;

	while (start < end) {
		int center = (start + end) / 2;
		if (value <= arr[center])
			end = center;
		else
			start = center + 1;
	}
	return end;
}

int maxIndex(int*arr, int value, int size) {
	int start = 0;
	int end = size - 1;

	while (start < end) {
		int center = (start + end) / 2;
		if (value < arr[center]) {
			end = center;
		}
		else
			start = center + 1;
	}
	return end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start; int end; int center;

	sort(arr, arr + N);
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> tmp;
		int min = minIndex(arr, tmp, N);
		int max = maxIndex(arr, tmp, N);
		if (max == N - 1 && arr[N - 1] == tmp)
			max++;
		cout << max - min << " ";
	}
}
