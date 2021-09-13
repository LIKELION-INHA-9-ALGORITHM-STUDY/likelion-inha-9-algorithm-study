#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<vector<int>> costs;
	vector<int> cities;
	int N, cost;

	cin >> N;
	for (int i = 0; i < N; i++) {
		costs.push_back({});
		cities.push_back(i);
		for (int j = 0; j < N; j++) {
			cin >> cost;
			costs[i].push_back(cost);
		}
	}

	int min = -1;
	do {
		// 가능한 모든 순열에 대해 순회가 가능한지 확인하자.
		int check = 0, result = 0;
		for (int i = 0; i < cities.size() - 1; i++) {
			if (costs[cities[i]][cities[i + 1]] == 0) {
				// 순회를 하지 못하고 중간에 끊키는 경우.
				check = 1;
				break;
			}
			result += costs[cities[i]][cities[i + 1]];
		}

		if (costs[cities[cities.size() - 1]][cities[0]] == 0) check = 1;
		// 순회를 끝내고 마지막 도시에서 출발했던 도시로 돌아갈 길이 없는 경우.

		if (check == 0) {
			// 순회를 완료한 경우.
			result += costs[cities[cities.size() - 1]][cities[0]];
			// 출발지로 돌아가는 값 더하기.
			if (min == -1 || result < min) min = result;
		}
	} while (next_permutation(cities.begin(), cities.end()));
	cout << min;
}