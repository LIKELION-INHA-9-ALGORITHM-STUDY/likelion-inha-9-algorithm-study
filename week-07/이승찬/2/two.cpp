#include <iostream>
using namespace std;
int num[1000][1000];
int comnum;
int coun;
int visit[1000];

void virusNum(int newnum)
{
	visit[newnum] = 1000;
	for (int i = 1; i <= comnum; i++)
	{
		if (!visit[i] && num[newnum][i] == 1000)
		{
			coun++;
			virusNum(i);
		}
	}
}
int main()
{
	int linknum;
	int a, b;
	cin >> comnum;
	cin >> linknum;
	for (int n = 0; n < linknum; n++)
	{
		cin >> a >> b;
		num[a][b] = 1000;
	}

	virusNum(1);
	cout << coun << endl;
}