#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int arr[8002] = { 0, };
	int n, mid, input, hight = 0, alway;
	double avg = 0;

	cin >> n;        //n: 데이터 입력 횟수

	for (int i = 0; i < n; i++)
	{
		cin >> input;            //input: 데이터 입력값
		arr[4000 + input]++;     //카운팅 정렬 실행

		avg += input;            //avg: 평균값

		if (hight < arr[4000 + input])        //입력 중 최대 빈도 확인
		{
			hight = arr[4000 + input];        //hight: 빈도의 최댓값
			alway = input;                    //alway: 최대의 빈도를 차지하는 수
		}
	}
	int min, max;                 //max: 최댓값, min: 최솟값
	min = max = input;

	bool flag = false;            //mid값을 초기화를 했는지 확인 용도
	int cnt = 0;                  //최대의 빈도를 가진 수의 갯수 확인 용도
	int sum = 0;                  //입력된 횟수 확인 용도

	for (int i = 0; i < 8002; i++)
	{
		int value = i - 4000;
		if (arr[i] > 0)
		{
			sum += arr[i];
			if (sum >= n / 2 + 1 && !flag)
			{
				mid = value;
				flag = true;
			}
			if (min > value) min = value;
			if (max < value) max = value;

			if (arr[i] == hight) cnt++;
			if (cnt == 2)        //두 번째로 작은 수만
			{
				cnt = 3;
				alway = value;
			}
		}
	}

	cout << round(avg / n) << "\n" << mid << "\n" << alway << "\n" << max - min;
	return 0;
}