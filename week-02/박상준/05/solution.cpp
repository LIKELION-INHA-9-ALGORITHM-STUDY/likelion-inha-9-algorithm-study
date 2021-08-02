#include <iostream>
#include <vector>
using namespace std;

int solution(int n) {
	vector<int> fibo = { 1,2 };

	if (n == 1 || n == 2) return n;
	for (int i = 2; i < n; i++) {
		fibo.push_back((fibo[i - 2] + fibo[i - 1]) % 1000000007);
	}
	return fibo[n - 1];
	// "순열" 문제라고 생각하고 풀면서 시간초과 해결해보려고 몇 시간을 삽질했는데
	// 이 문제 그냥 피보나치 수열 문제였다...
	// 진짜... 왜 피보나치인지도 모르겠다. 노가다하다가 얼떨결에 알았다...
	// 왜 피보나치인지 아시는 분 피드백 부탁드립니다 ㅠ
}
