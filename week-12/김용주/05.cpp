#include <iostream>
#include <queue>
using namespace std;
int n;
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
struct yx_num {
	int y, x, num;
};
int board[21][21] = { 0 };
bool visited[21][21] = { 0 };
int route[21][21] = { 0 };
yx_num shark;
queue<yx_num> q;
int ans_time = 0;
int obj_fish;
//bfs로 현재 상어랑 가장 가까운 거리에 (조건에 맞는) 물고기를 찾고 물고기로 가는 시간을 답에 더하고를 반복해서 조건에 만족하는 물고기가 없는 경우 종료
void solution()
{
	while (1)
	{
		int go_y = 0; int go_x = 0; int distance = 401; //구불구불길로 20*20이 가장 길게 가는 길! 그래서 최대 길이 401
		if (obj_fish == 0)
		{
			obj_fish = shark.num + 1;
			shark.num++;
		}
		q.push({ shark.y,shark.x,shark.num });
		route[shark.y][shark.x] = 0;
		visited[shark.y][shark.x] = true;
		while (!q.empty())
		{
			int nowy = q.front().y; int nowx = q.front().x; int num = shark.num;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (nowy + dy[i] < 0 || nowy + dy[i] >= n || nowx + dx[i] < 0 || nowx + dx[i] >= n)
					continue;
				if (visited[nowy + dy[i]][nowx + dx[i]] == false)
				{
					visited[nowy + dy[i]][nowx + dx[i]] = true;
					if (board[nowy + dy[i]][nowx + dx[i]] <= shark.num)
					{
						route[nowy + dy[i]][nowx + dx[i]] = route[nowy][nowx] + 1;
						q.push({ nowy + dy[i],nowx + dx[i],num });
						if (board[nowy + dy[i]][nowx + dx[i]] != 0 && board[nowy + dy[i]][nowx + dx[i]] < shark.num)
						{
							if (distance > route[nowy + dy[i]][nowx + dx[i]])
							{
								distance = route[nowy + dy[i]][nowx + dx[i]];
								go_y = nowy + dy[i]; go_x = nowx + dx[i];
							}
							else if (distance == route[nowy + dy[i]][nowx + dx[i]])
							{
								if (go_y > nowy + dy[i])
								{
									go_y = nowy + dy[i]; go_x = nowx + dx[i];
								}
								else if (nowy + dy[i] == go_y)
								{
									if (go_x > nowx + dx[i])
									{
										go_y = nowy + dy[i]; go_x = nowx + dx[i];
									}
								}
							}
						}
					}
				}
			}
		}
		if (distance == 401)
			break;
		ans_time += distance;
		board[go_y][go_x] = 0; //shark가 9로 적혀있으면 이길을 못갈 수 가 있으니 0으로 둔다
		shark.y = go_y; shark.x = go_x;
		obj_fish--;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				visited[y][x] = false;
				route[y][x] = 0;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == 9)
			{
				shark.y = y; shark.x = x; shark.num = 2;
			}
		}
	}
	board[shark.y][shark.x] = 0; //shark가 9로 적혀있으면 이길을 못갈 수 가 있으니 0으로 둔다
	obj_fish = shark.num;
	solution();
	cout << ans_time << endl;
	return 0;
}