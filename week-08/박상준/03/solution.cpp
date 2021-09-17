#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr;
	int K, N, length;
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> length;
		arr.push_back(length);
	}
	sort(arr.begin(), arr.end());

	long long left = 1, right = arr[arr.size() - 1], current = right;
	// 가장 긴 경우를 최대로 해서 시작.
	while (left < right) {
		int cnt = 0;
		// 만들어지는 랜선의 개수
		for (int i = arr.size() - 1; i >= 0; i--) {
			cnt += arr[i] / current;
		}
		if (cnt == N) break;
		// 딱 N개가 만들어지면 stop.

		if (cnt < N) right = current - 1; // 적게 만들어지면 하나의 길이를 줄여보자.
		else left = current + 1; // 많이 만들어지면 하나의 길이를 늘려보자.
		current = (left + right) / 2;
	}
	// 끝나고 나왔을 때, 그게 최대 길이가 아닐 수 있음.
	while (true) {
		int cnt = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			cnt += arr[i] / current;
		}
		if (cnt < N) break;
		// 개수가 N보다 작아지면 그 전 값이 최대 값.
		current++;
	}
	cout << current - 1;
}