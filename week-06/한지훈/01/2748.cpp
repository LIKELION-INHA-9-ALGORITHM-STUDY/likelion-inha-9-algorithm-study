#include <iostream>
using namespace std;

long long arr[100] = { 0, 1, };

long long fibo(int num) {

	if (num == 0 || num == 1) {
		return arr[num];
	}
	else if (arr[num] == NULL) {
		arr[num] = fibo(num - 1) + fibo(num - 2);
	}

	return arr[num];

}

int main() {

	int num;
	cin >> num;
	cout << fibo(num);

}