#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << binary_search(arr.begin(), arr.end(), num) << "\n";
	}
}