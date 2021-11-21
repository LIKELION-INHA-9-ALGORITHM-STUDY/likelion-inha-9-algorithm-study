#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, input;
	cin >> N;

	vector<int> arr, check;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
		check.push_back(input);
	}
	sort(check.begin(), check.end());
	check.erase(unique(check.begin(), check.end()), check.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(check.begin(), check.end(), arr[i]) - check.begin() << " ";
	}
}