#include <iostream>
using namespace std;
#include <algorithm>
int K, N; int arr[10000];
int main() {
	cin >> K >> N;
	int max_num = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (arr[i] > max_num) max_num = arr[i];
	}
	long long start = 1;
	long long end = max_num;

	int max_length = 0;
	while (start <= end) {
		long long center = (start + end) / 2;

		int count = 0; //while¹® ¾È¿¡
		for (int i = 0; i < K; i++) {
			count += arr[i] / center;
		}
		if (count < N) {
			end = center - 1;
		}
		else {
			start = center + 1;
			if (center > max_length)
				max_length = center;
		}
	}
	cout << max_length;
}
