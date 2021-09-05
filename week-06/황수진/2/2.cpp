
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int n;
int main() {
	cin >> n;
	vector<int> d(n + 1);
	d[1] = 0;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
	}
	cout << d[n];
}