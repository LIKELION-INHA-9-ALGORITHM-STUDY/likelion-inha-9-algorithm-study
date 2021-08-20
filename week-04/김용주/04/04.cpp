#include <iostream>
using namespace std;
/*
    이미 true인거 찾고도 계속 돈다는게 제가 생각해도 문제입니다...
    여튼 저는 재귀 이용해서 3번의 삼각수? 를 통해 원하는 값에 도달할 경우 check를 true로 하고 나머지의 경우는 패스 하는 재귀로 했습니다.
*/
int test = 0;
bool check = false;
int change_num(int i)
{
	return i * (i + 1) / 2;
}
void reculsive(int start,int num, int count)
{
	if (count == 3)
	{
		if (num == 0)
			check = true;
		return;
	}
	else if (count > 3)
		return;
	else 
	{
		for (int i = start; i >= 1; i--)
		{
			if (num - change_num(i) >= 0)
				reculsive(i, num - change_num(i), count + 1);
		}
	}
}
int main()
{
	cin >> test;
	int num = 0;
	for (int i = 0; i < test; i++)
	{
		cin >> num;
		check = false;
		reculsive(num, num, 0);
		if(check)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

	return 0;
}