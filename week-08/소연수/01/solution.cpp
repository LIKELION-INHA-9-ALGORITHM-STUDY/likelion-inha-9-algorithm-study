// 이진 탐색 알고리즘 반복문으로 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool BinarySearch(int* arr, int len, int key) {
	int start{ 0 }; // 이진 탐색할 부분 첫 인덱스
	int end{ len - 1 }; // 이진 탐색할 부분 끝 인덱스
	int mid; // 이진 탐색할 부분 가운데 인덱스

	while (end - start >= 0) { // end-start가 음수가 되면 주어진 배열에 존재하지 않는 것
		mid = (start + end) / 2;

		if (arr[mid] == key) {
			return true;
		}
		else if (arr[mid] > key) { // 찾는 수가 이진 탐색 범위의 중간 수보다 작으면
			end = mid - 1; // 다음 이진 탐색할 부분의 끝 인덱스를 중간 인덱스보다 하나 앞으로
		}
		else { // 찾는 수가 이진 탐색 범위의 중간 수보다 클 때
			start = mid + 1; // 다음 이진 탐색할 범위의 시작을 중간 인덱스보다 한 칸 뒤로
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); // cin 속도 향상

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i{ 0 }; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	sort(arr, arr+n); // 이진 탐색 전 배열 오름차순 정렬
	
	int m;
	cin >> m;
	vector<int> ans;
	for (int i{ 0 }; i < m; i++) {
		int b;
		cin >> b;
		ans.push_back(BinarySearch(arr, n, b));
	}
	for (int a : ans) {
		cout << a << '\n';
	}
	return 0;
}


// Algorithm 헤더 파일에 있는 binary_search 함수 이용
// binary_search(정렬된 컨테이너의 시작 주소, 끝 주소, 찾는 값)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); // cin 속도 향상

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i{ 0 }; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	sort(arr, arr + n); // 이진 탐색 전 배열 오름차순 정렬

	int m;
	cin >> m;
	vector<int> ans;
	for (int i{ 0 }; i < m; i++) {
		int b;
		cin >> b;
		ans.push_back(binary_search(arr, arr+n, b));
	}
	for (int a : ans) {
		cout << a << '\n';
	}
	return 0;
}