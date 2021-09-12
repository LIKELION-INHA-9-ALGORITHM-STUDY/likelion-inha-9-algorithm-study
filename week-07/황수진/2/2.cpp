
#include<iostream>
#include<vector>
using namespace std;
int computer_num;
int pair_num;
int network[101][101] = { 0 };
bool visited[100] = { false };
int result = 0;

void dfs(int x) {
	result++;
	visited[x] = true;
	for (int i = 1; i <= computer_num; i++) {
		if (network[x][i] && !visited[i])
			dfs(i);
	}
	return;
}

int main() {
	cin >> computer_num;
	cin >> pair_num;
	for (int i = 0; i < pair_num; i++) {
		int a, b;
		cin >> a >> b;
		network[a][b] = 1;
		network[b][a] = 1;
	}
	dfs(1);
	cout << result - 1;

}