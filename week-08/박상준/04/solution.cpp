#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr;
	int K, N, capacity;
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> capacity;
		arr.push_back(capacity);
	}
	sort(arr.begin(), arr.end());

	long long left = 1, right = arr[arr.size() - 1], current = right;
	while (left < right) {
		int cnt = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			cnt += arr[i] / current;
		}
		if (cnt == N) break;

		if (cnt < N) right = current - 1;
		else left = current + 1;
		current = (left + right) / 2;
	}

	while (true) {
		int cnt = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			cnt += arr[i] / current;
		}
		if (cnt < N) break;
		current++;
	}
	cout << current - 1;
}