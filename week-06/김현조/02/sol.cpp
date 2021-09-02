// 문제 2. 1로 만들기

// 정수 X 연산
// X가 3의 배수면 3으로 나눈다
// X가 2의 배수면 2로 나눈다
// 1을 뺀다
// 정수 N -> 연산 잘 사용해서 1을 만들자
// 연산 횟수 최솟값?


// vector 만들고 for문으로 반복
// N = 1일 때, 연산 횟수 0으로 초기화 설정

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> Arr(N+1);

    // 초기화
    Arr[1] = 0;
    for(int i=2; i<=N; i++)
    {
        Arr[i] = Arr[i-1] + 1;
        if(!(i%3))
            Arr[i] = min(Arr[i], Arr[i/3]+1);
        if(!(i%2))
            Arr[i] = min(Arr[i], Arr[i/2]+1);
    }

    cout << Arr[N];
}