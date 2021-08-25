#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 비용을 기준으로 오름차순 정렬
bool sortByCost(vector<int> v1, vector<int> v2) {
	return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
	//costs를 비용을 기준으로 오름차순 정렬
	sort(costs.begin(), costs.end(), sortByCost);

	// 연결된 섬들을 저장하는 벡터. 가장 적은 비용의 경로가 이어주는 두 섬으로 초기화.
	vector<int> connected = { costs[0][0], costs[0][1] };
	int answer = costs[0][2];

	// 해당 섬이 연결되었는지 확인하기 위함. 처음 두 섬을 이어준 상태로 시작.
	vector<int> check;
	for (int i = 0; i < n; i++) check.push_back(0);
	check[costs[0][0]]++;
	check[costs[0][1]]++;

	//첫 섬은 이어주고 시작하니 지워주자.
	costs.erase(costs.begin());
	while (connected.size() < n) {
		// 모든 섬이 이어질때까지
		int size = costs.size();
		for (int i = 0; i < size; i++) {
			if (check[costs[i][0]] == 0 && check[costs[i][1]] != 0) {
				// costs의 0번째 인덱스 섬이 이어지지 않았을 때, 1번째 인덱스의 섬은 이어져있는 상태라면
				check[costs[i][0]]++;
				connected.push_back(costs[i][0]);
				answer += costs[i][2];
				costs.erase(costs.begin() + i);
				break;
			}

			if (check[costs[i][1]] == 0 && check[costs[i][0]] != 0) {
				// costs의 1번째 인덱스 섬이 이어지지 않았을 때, 0번째 인덱스의 섬은 이어져있는 상태라면
				check[costs[i][1]]++;
				connected.push_back(costs[i][1]);
				answer += costs[i][2];
				costs.erase(costs.begin() + i);
				break;
			}
		}
	}
	return answer;
}