#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> exp = { -1 }; // 0번 인덱스 자리 비워둠
	for (int i{ 0 }; i<n; i++) {
		int tmp;
		cin >> tmp;
		exp.push_back(tmp);
	}
	sort(exp.begin(), exp.end()); // 오름차순 정렬 -> 실제 등수 순
	
	long long ans{ 0 };
	// 최악의 경우 1부터 499,999까지의 합을 담아야 하므로 long long 자료형
	for (int i{ 1 }; i <= n; i++) {
		ans += abs(i - exp[i]); // 불만도 더하기
	}

	cout << ans << endl;
	return 0;
}