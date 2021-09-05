#include <iostream>
using namespace std;
int n;
long long arr[100];

long long fibonacci(long long x) {
	if (x == 1)return 1;
	if (x == 2)return 1;
	//if (arr[x] != 0)return arr[x];
	return arr[x] = fibonacci(x - 1) + fibonacci(x - 2);
}
int main() {
	cin >> n;
	cout << fibonacci(n);
}