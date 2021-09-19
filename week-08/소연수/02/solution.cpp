// 반복문으로 구현한 이진 탐색 알고리즘 (시간 초과)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearchCount(int* arr, int len, int k) {
	int start{ 0 };
	int end{ len - 1 };
	int count{ 0 };
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2 ;

		if (arr[mid] == k) {
			count++;
			arr[mid] = 10000001;
			sort(arr, arr + len);
		}
		else if (arr[mid] > k) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i{ 0 }; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	sort(arr, arr + n);

	int m;
	cin >> m;
	vector<int> ans;
	for (int i{ 0 }; i < m; i++) {
		int b;
		cin >> b;
		ans.push_back(binarySearchCount(arr, n, b));
	}
	for (int a : ans) {
		cout << a << " ";
	}
}

// unordered_map 이용 풀이
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	unordered_map <int, int> map;
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		int a;
		cin >> a;
		map[a]++;
	}

	int m;
	cin >> m;

	for (int i{ 0 }; i < m; i++) {
		int b;
		cin >> b;
		cout << map[b] << " ";
	}
	return 0;
}

// 이진 탐색 이용 (upper_bound, lower_bound) 풀이
/*
ex)
1 3 3 3 5 7 8 에서
lower_bound(start, end, 3): 2 (3이상의 값이 처음 나오는 위치)
upper_bound(start, end, 3): 5 (3을 초과하는 값이 처음 나오는 위치)
이 두 값의 차를 이용해(5-2) 3의 개수를 구할 수 있다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i{ 0 }; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	sort(arr, arr + n);

	int m;
	cin >> m;
	for (int i{ 0 }; i < m; i++) {
		int b;
		cin >> b;
		cout << upper_bound(arr, arr + n, b) - lower_bound(arr, arr + n, b) << " ";
	}
	return 0;
}