#include <iostream>
#include <vector>
using namespace std;
/*
dfs를 통해서 풀었습니다. 1과 연결된거의 한 줄기를 쭉 따라가고 쭉쭉 확인해서 이미 방문한 노드가 아니면
1에 의해 바이러스에 감염되니까 answer에 추가합니다. 처음에 틀렸던게 한쪽만 연결을 해서 였는데
1-3 3-1 이런식으로 연결을 해줘야지만 맞을 수 있었습니다
*/
vector<vector<int>> com_net(101);
bool visit[101] = { 0 };
int answer = 0;
void dfs(int now)
{
	for (int i = 0; i < com_net[now].size(); i++)
	{
		if (visit[com_net[now][i]])
			continue;
		visit[com_net[now][i]] = true;
		answer++;
		dfs(com_net[now][i]);
	}
}
int main()
{
	int computers = 0;
	int net = 0;
	cin >> computers >> net;
	for (int i = 0; i < net; i++)
	{
		int one, two;
		cin >> one >> two;
		com_net[one].push_back(two);
		com_net[two].push_back(one);
	}
	visit[1] = true;
	dfs(1);
	cout << answer << endl;
	return 0;
}