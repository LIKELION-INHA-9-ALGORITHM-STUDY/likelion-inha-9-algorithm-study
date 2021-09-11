#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start, int& answer) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] == false) {
			dfs(next, answer);
			answer++;
		}
	}
}

int main() {
	int computers, pairs, num1, num2;

	cin >> computers >> pairs;
	for (int i = 0; i < computers + 1; i++) {
		graph.push_back({});
		visited.push_back(false);
	}

	for (int i = 0; i < pairs; i++) {
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	for (int i = 0; i < computers + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	int answer = 0;
	dfs(1, answer);
	// 1번부터 dfs로 한 번 순회되는 노드의 수가 바이러스에 걸리게 되는 컴퓨터의 수.
	cout << answer;
}