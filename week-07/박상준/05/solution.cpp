#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start, int& connected) {
	visited[start] = true;
	connected++;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] == false) dfs(next, connected);
	}
}

int solution(int n, vector<vector<int>> computers) {
	for (int i = 0; i < n; i++) {
		graph.push_back({});
		visited.push_back(false);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (computers[i][j] == 1) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	int connected = 0, networks = 0;
	// 연결된 컴퓨터의 수와 네트워크의 수.
	dfs(0, connected);
	networks++;
	// 첫 순회를 했을 때, connect 값 확인.
	while (connected < n) {
		// 연결된 컴퓨터의 수가 전체 컴퓨터의 수가 될 때 까지,
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				// 방문 체크 벡터를 순회하면서 아직 방문하지 않은 노드 확인.
				dfs(i, connected);
				// 거기서부터 다시 순회 시작, connected 갱신.
				networks++;
				// 네트워크의 수 ++
			}
		}
	}
	return networks;
}