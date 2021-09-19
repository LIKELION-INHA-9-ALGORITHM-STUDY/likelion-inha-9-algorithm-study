#include <iostream>
#include <algorithm>
using namespace std;
int card_cnt = 0;
int card[100001] = { 0 };
int want_cnt = 0;
int want[100001] = { 0 };
int answer[100001] = { 0 };
/*
* 이분탐색 알고리즘 대로 숫자를 찾도록 하였습니다.
*/
int main()
{
	cin >> card_cnt;
	for (int i = 0; i < card_cnt; i++)
		cin >> card[i];
	cin >> want_cnt;
	for (int i = 0; i < want_cnt; i++)
		cin >> want[i];
	sort(card, card + card_cnt);
	for (int index = 0; index < want_cnt; index++)
	{
		int low = 0; int high = card_cnt - 1;
		while (low <= high)
		{
			int mid = (high + low) / 2;
			if (card[mid] == want[index])
			{
				answer[index] = 1;
				break;
			}
			else if (card[mid] > want[index])
				high = mid - 1;
			else if (card[mid] < want[index])
				low = mid + 1;
		}
	}
	for (int i = 0; i < want_cnt; i++)
		cout << answer[i] << " ";
	cout << endl;
	return 0;
}