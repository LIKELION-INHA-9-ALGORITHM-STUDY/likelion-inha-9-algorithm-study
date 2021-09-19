#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	long long max = times[times.size() - 1], left = 0, right = max * n, current = right;
	// 가능한 최대 값은 가장 긴 시간동안 n명.
	while (left < right) {
		long long person = 0;
		for (int i = times.size() - 1; i >= 0; i--) {
			person += current / times[i];
			// 현재 시간동안 몇 명이 입국심사를 받을 수 있는지 확인.
			if (person > n) break;
			// n명을 넘어가면 더 해볼 필요 없다.
		}
		if (person == n) break;
		// 딱 n명이 받을 수 있는 시간이면 stop.

		if (person < n) left = current + 1; // n명보다 적게 받았으면 시간을 늘려보자.
		else right = current - 1; // n명보다 많이 받았으면 시간을 줄여보자.
		current = (left + right) / 2;
	}
	// 끝나고 나왔을 때 그 시간이 최소값이 아닐 수 있음.

	while (true) {
		long long person = 0;
		for (int i = times.size() - 1; i >= 0; i--) {
			person += current / times[i];
		}
		if (person < n) break;
		// 받을 수 있는 사람이 n명보다 적어지면 그 전 시간이 최소값.
		current--;
	}
	return current + 1;
}