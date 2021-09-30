#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> squares;
	for (int i = 1; pow(i, 2) <= n; i++) {
		// n의 최대값인 50,000이 224의 제곱보다 작으니까, 벡터의 사이즈는 많아야 223.
		// 그냥 노가다하자.
		squares.push_back(pow(i, 2));
	}

	if (binary_search(squares.begin(), squares.end(), n) == 1) {
		// 제곱수 하나로 이루어진 경우 -> 이진 탐색이 빠르다.
		cout << 1;
		return 0;
	}

	// 제곱수 두 개로 이루어진 경우.
	int flag = 0;
	for (int i = squares.size() - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int sum = squares[i] + squares[j];
			if (sum == n) {
				flag = 1;
				break;
			}

			if (sum < n) break;
		}
	}

	if (flag == 1) {
		cout << 2;
		return 0;
	}

	// 제곱수 세 개로 이루어진 경우.
	for (int i = squares.size() - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			for (int k = j; k >= 0; k--) {
				int sum = squares[i] + squares[j] + squares[k];

				if (sum == n) {
					flag = 1;
					break;
				}

				if (sum < n) break;
			}
		}
	}

	if (flag == 1) {
		cout << 3;
		return 0;
	}

	// 제곱수 네 개로 이루어진 경우.
	for (int i = squares.size() - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			for (int k = j; k >= 0; k--) {
				for (int p = k; p >= 0; p--) {
					int sum = squares[i] + squares[j] + squares[k] + squares[p];

					if (sum == n) {
						flag = 1;
						break;
					}

					if (sum < n) break;
				}
			}
		}
	}

	if (flag == 1) {
		cout << 4;
		return 0;
	}

}