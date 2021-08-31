#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long> fibo = { 0, 1 };
	int n;

	cin >> n;
	while (n > fibo.size() - 1) {
		fibo.push_back(fibo[fibo.size() - 2] + fibo[fibo.size() - 1]);
	}
	cout << fibo[n];
}