#include <iostream>
using namespace std;
int n;
int cost[11][11] = { 0 };
bool visit[11] = { 0 };
int min_n = 999999999;
/*
* 하나의 길 찾고 다음 길을 찾는 것으로 생각해서 dfs를 통해 해결을 하였습니다. 두번 틀렸습니다가 나왔는데
* 첫번재 이유는 제가 visit[i]를 true를 해놓고 dfs가 끝나면 visit[i]를 false로 해놓는 코드를 안적었었는데
* 이렇게 되면 모든 경로를 찾을 수가 없습니다. 다음으로는 모든 도시를 돈 후에 처음 도시로 다시 돌아가야하는데
* 맨 마지막 도시에서 처음 도시로 돌아가는 경로가 없을 수있다는것을 생각하지 못한것 때문이었습니다.
*/
void dfs(int start, int  now,int cocost,int cnt)
{
	bool check = true;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
			check=false;
	}
	if (check && cnt==n)
	{
		if(cost[now][start]!=0)
			min_n = min_n > cocost + cost[now][start] ? cocost + cost[now][start] : min_n;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (visit[i] || cost[now][i]==0)
				continue;
			visit[i] = true;
			dfs(start, i, cocost + cost[now][i], cnt + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];

	for (int i = 0; i < n; i++)
	{
		visit[i] = true;
		dfs(i,i,0,1);
		for (int j = 0; j < n; j++)
			visit[j] = false;
	}
	cout << min_n << endl;
	return 0;
}