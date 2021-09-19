#include <stdio.h>
#include <algorithm>
using namespace std;
int card_cnt = 0;
int card[500001] = { 0 };
int want_cnt = 0;
int want[500001] = { 0 };
//첫번째는 숫자가 시작하는 첫번째 인덱스 찾고 끝나고 난 후의 인덱스 찾아서 빼는 걸로 했고
//두번째는 for문에서 각자 위치에 있는 것 찾아서 해당 값 출력하도록 하였습니다. 10000000더한건 음수때문!
int lowerbound(int num)
{
	int low = 0; int high = card_cnt - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (card[mid] >= num)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int higherbound(int num)
{
	int low = 0; int high = card_cnt - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (card[mid] > num)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}
int main()
{
	scanf("%d", &card_cnt);
	for (int i = 0; i < card_cnt; i++)
		scanf("%d", &card[i]);
	sort(card, card + card_cnt);
	scanf("%d", &want_cnt);
	for (int i = 0; i < want_cnt; i++)
		scanf("%d", &want[i]);
	for (int i = 0; i < want_cnt; i++)
	{
		int low = lowerbound(want[i]); int high = higherbound(want[i]);
		if (high == card_cnt - 1 && want[i] == card[high])
			high++;
		printf("%d\n", high - low);
	}

	return 0;
}

/*
* #include<stdio.h>
using namespace std;
int num[20000011] = { 0 };
int main()
{
	int card_cnt;
	scanf("%d", &card_cnt);
	int card;
	for (int i = 0; i < card_cnt; i++)
	{
		scanf("%d", &card);
		num[card+10000000]++;
	}
	int want_cnt;
	scanf("%d", &want_cnt);
	for (int i = 0; i < want_cnt; i++)
	{
		int want;
		scanf("%d", &want);
		printf("%d\n", num[want+10000000]);
	}
	return 0;
}
*/