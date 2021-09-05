/*
	1에서부터 입력받은 수까지 올라가는 bottom-up 방식
	배열의 각 인덱스에는 1에서부터 2, 3, 4 ... 가 되는 방법 중 최솟값을 담는다.
	-> arr의 n번 인덱스에 n을 1로 만들 수 있는 최소 계산 횟수가 담긴다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[1000001];
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for (int i{ 4 }; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
		// 문제에 있는 세가지 방법을 적용하고 최솟값을 배열에 담는다.
	}
	cout << arr[n];
	delete[] arr;
	return 0;
}