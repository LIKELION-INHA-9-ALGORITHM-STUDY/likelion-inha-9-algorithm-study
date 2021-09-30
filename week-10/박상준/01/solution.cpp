#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, input, middle, most, range;
	double average = 0;
	cin >> N;

	int* arr = new int[N];
	int* check = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
		check[i] = 0;
	}

	sort(arr, arr + N);

	middle = arr[N / 2]; // 중앙값
	range = arr[N - 1] - arr[0]; // 범위
	for (int i = 0; i < N; i++) {
		average += arr[i];
	}
	average = average / N; // 평균

	check[0] = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) check[i] = check[i - 1] + 1;
		else check[i] = 1;
	}
	// 연속된 값이 몇개인지 확인

	int mostCnt = *max_element(check, check + N); // 최빈값의 횟수 확인
	vector<int> mostIdx;
	for (int i = 0; i < N; i++) {
		if (check[i] == mostCnt) mostIdx.push_back(i);
		if (mostIdx.size() == 2) break; // 2개 이상이면 2개까지만.
	}
	most = arr[mostIdx[mostIdx.size() - 1]];
	// 최빈값.

	cout << fixed;
	cout.precision(0); // 소수점 이하 첫째 자리에서 반올림
	cout << average << "\n" << middle << "\n" << most << "\n" << range;
}