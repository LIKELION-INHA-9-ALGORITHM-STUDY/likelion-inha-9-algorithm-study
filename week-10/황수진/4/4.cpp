#include<iostream>
using namespace std;
#include<algorithm>
#define INT_MAX 50005
int n;
int tmp;
int arr[50000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = INT_MAX;
		for (int j = 1; j*j <= i; j++) {
			tmp = min(tmp, arr[i - j * j] + 1);
		}
		arr[i] = tmp;

	}
	cout << arr[n] << "\n";
}
