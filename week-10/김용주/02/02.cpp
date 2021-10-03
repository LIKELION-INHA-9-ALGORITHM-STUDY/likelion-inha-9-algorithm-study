#include <iostream>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void dfs(int x, int y, int maxw, int maxh, int w_h[51][51])
{
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] < 0 || x + dx[i] >= maxw || y + dy[i] >= maxh)
			continue;
		if (w_h[x + dx[i]][y + dy[i]] != 1)
			continue;
		w_h[x + dx[i]][y + dy[i]] = 2;
		dfs(x + dx[i], y + dy[i], maxw, maxh, w_h);
	}
}
int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int answer = 0;
		int w, h, cnt;
		int w_h[51][51] = { 0 };
		cin >> w >> h >> cnt;
		for (int c = 0; c < cnt; c++)
		{
			int x, y;
			cin >> x >> y;
			w_h[x][y] = 1;
		}
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (w_h[x][y] == 1)
				{
					dfs(x, y, w, h, w_h);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}