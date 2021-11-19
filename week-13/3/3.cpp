#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> check(v);

	sort(check.begin(), check.end());
	check.erase(unique(check.begin(), check.end()), check.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(check.begin(), check.end(), v[i]) - check.begin() << " ";
	}
}