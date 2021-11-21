#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 100001
struct mo_peo {
	int money, people;
};
int obj_peo = 0; int case_cnt = 0;
vector<mo_peo> cases;
int answer[MAX_NUM] = { 0 };
int main()
{
	cin >> obj_peo >> case_cnt;
	for (int i = 0; i < case_cnt; i++)
	{
		int m, p;
		cin >> m >> p;
		cases.push_back({ m,p });
	}
	for (int i = 0; i < cases.size(); i++)
	{
		for (int k = cases[i].money; k < MAX_NUM; k++)
		{
			answer[k] = max(answer[k], answer[k - cases[i].money] + cases[i].people);
		}
	}
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (answer[i] >= obj_peo)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}