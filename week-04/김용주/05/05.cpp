#include <iostream>
#include <algorithm>
using namespace std;
int n;
string n_n[52];
int nx[] = { 1,0 };
int ny[] = { 0,1 };

/*
	옆에 있는 문자가 다른 경우에 교환을 해서 하나하나 max의 값을 확인해보도록합니다.
	마지막 인덱스에 있는 경우나 문자열이 바뀌는 경우에 false->true로 하여서 그때 마다 최댓값을 확인합니다
*/

int check_max()
{
	int C_now = 0, P_now = 0, Y_now = 0, Z_now = 0;
	int C_max = 0, P_max = 0, Y_max = 0, Z_max = 0;
	bool C = false, P = false, Y = false, Z = false;
	int answer = 0;
	bool check = false;
	for (int y = 0; y < n; y++)
	{
		check = false;
		for (int x = 0; x < n; x++)
		{
			if (n_n[y][x] == 'C')
			{
				C_now++;
				C = true;
			}
			else if (n_n[y][x] == 'P')
			{
				P_now++;
				P = true;
			}
			else if (n_n[y][x] == 'Y')
			{
				Y_now++;
				Y = true;
			}
			else if (n_n[y][x] == 'Z')
			{
				Z_now++;
				Z = true;
			}
			if (x < n - 1)
			{
				if (n_n[y ][x] == n_n[y][x+1])
					check = false;
				else
					check = true;
			}
			else
				check = true;
			if (check)
			{
				if (C)
				{
					C = false;
					C_max = C_max < C_now ? C_now : C_max;
					C_now = 0;
				}
				else if (P)
				{
					P = false;
					P_max = P_max < P_now ? P_now : P_max;
					P_now = 0;
				}
				else if (Y)
				{
					Y = false;
					Y_max = Y_max < Y_now ? Y_now : Y_max;
					Y_now = 0;
				}
				else if (Z)
				{
					Z = false;
					Z_max = Z_max < Z_now ? Z_now : Z_max;
					Z_now = 0;
				}
			}
		}
		answer = max(C_max, max(P_max, max(Y_max, Z_max)));
	}
	for (int x = 0; x < n; x++)
	{
		check = false;
		for (int y = 0; y < n; y++)
		{
			
			if (n_n[y][x] == 'C')
			{
				C_now++;
				C = true;
			}
			else if (n_n[y][x] == 'P')
			{
				P_now++;
				P = true;
			}
			else if (n_n[y][x] == 'Y')
			{
				Y_now++;
				Y = true;
			}
			else if (n_n[y][x] == 'Z')
			{
				Z_now++;
				Z = true;
			}
			if (y < n - 1)
			{
				if (n_n[y + 1][x] == n_n[y][x])
					check = false;
				else
					check = true;
			}
			else
				check = true;
			if (check)
			{
				if (C)
				{
					C = false;
					C_max = C_max < C_now ? C_now : C_max;
					C_now = 0;
				}
				else if (P)
				{
					P = false;
					P_max = P_max < P_now ? P_now : P_max;
					P_now = 0;
				}
				else if (Y)
				{
					Y = false;
					Y_max = Y_max < Y_now ? Y_now : Y_max;
					Y_now = 0;
				}
				else if (Z)
				{
					Z = false;
					Z_max = Z_max < Z_now ? Z_now : Z_max;
					Z_now = 0;
				}
			}
		}
		answer = max(C_max, max(P_max, max(Y_max, Z_max)));
	}
	return answer;
}
int main()
{
	int max_ans = 0;
	cin >> n;
	for (int y = 0; y < n; y++)
		cin >> n_n[y];

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (y + ny[i] >= n || x + nx[i] >= n)
					continue;
				if (n_n[y][x] == n_n[y + ny[i]][x + nx[i]])
					continue;
				char m = n_n[y][x];
				n_n[y][x] = n_n[y + ny[i]][x + nx[i]];
				n_n[y + ny[i]][x + nx[i]] = m;
				int answer = check_max();
				max_ans = max_ans < answer? answer : max_ans;
				m = n_n[y+ny[i]][x+nx[i]];
				n_n[y + ny[i]][x + nx[i]]=n_n[y][x];
				n_n[y][x] = m;
			}

		}
	}
	cout << max_ans << endl;
	return 0;
}