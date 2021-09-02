// 문제 3. 1,2,3 더하기

// 정수 N 을 1, 2,3의 합으로 나타내는 방법의 수
// test case 개수 T

// 직접 경우의 수를 찾아보니
// 1 2 4 7 13 ... 수열임
// 일종의 점화식(수식)으로 DP 방식

#include <iostream>
using namespace std;

int dpArr[12];

int main() 
{
    int N;
    cin >> N;

    dpArr[1]=1;
    dpArr[2]=2;
    dpArr[3]=4;

    for(int i=0; i<N; i++)
    {
        int T;
        cin >> T;

        int j=4;
        for(; j<=T; j++)
            dpArr[j] = dpArr[j-1] + dpArr[j-2] + dpArr[j-3];

        cout << dpArr[T];
        j = T + 1;
    }

    return 0;
}