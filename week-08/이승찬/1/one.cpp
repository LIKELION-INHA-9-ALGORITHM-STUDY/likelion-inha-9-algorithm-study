#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001];

void binarySearch(int key) {
	int start = 0;
	int end = n - 1;
	int mid;

	while (end >= start) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			cout << 1 << endl;
			return;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << 0 << endl;
	return 0;
}

int main()
{
	ios_base::sync_with_studio(0);
	cin.tie(0);
	cin >> n;
	int tenp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		binarySearch(temp);
	}
	return 0;
}