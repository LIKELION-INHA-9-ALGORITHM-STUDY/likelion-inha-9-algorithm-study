#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101]; // 무방향 그래프를 인접리스트로~
bool chk[101]; // 방문한 노드를 표시하는 배열
int ans{ 0 }; // 바이러스에 걸리게 되는 컴퓨터의 수

void dfs(int n) {
	chk[n] = 1;
	for (int i{ 0 }; i < v[n].size(); i++) {
		int a = v[n][i];
		if (!chk[a]) {
			dfs(a);
			ans++;
		}
	}
}

int main() {
	int c, p;
	cin >> c >> p;

	for (int i{ 0 }; i < p; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << ans <<endl;
	return 0;
}