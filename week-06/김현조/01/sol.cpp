//// 210902 멋사 코테 스터디 6주차 - 동적계획법 DP
// 문제 1. 피보나치 수 2

// //// 동적계획법 (Dynamic Programming)

// : 큰 문제를 작은 문제로 나누어 푼다 -> 분할정복이랑 비슷?
// -> 차이점 : 작은 문제가 중복이 일어나지 않도록 함
// -> 정답을 구한 작은 문제는 메모 Memoization 해두고 결과값을 이용
// => 같은 문제는 구할 때마자 정답이 같음

// // 구현 방법
// a) Bottom-up : 작은 문제부터
// b) Top-down : 제귀함수로 구현


// n번째 피보나치 수 구하자


// 시간 제한이 짧아서 -> 이전 값을 다시 활용하는 DP로 쓰자
// N이 커질수록 값이 기하급수적으로 증가하므로 long long 사용
// 배열에 각 피보나치 수를 저장하는 방식


#include <iostream>
using namespace std;

long long fiboArr[100] = {0, 1, };

long long fibo(int N)
{
    if(N==0 || N==1)
        return fiboArr[N];

    else if(fiboArr[N]==0)
        fiboArr[N]=fibo(N-1)+fibo(N-2);

    return fiboArr[N];
}

int main()
{
    int N;
    cin >> N;
    
    cout << fibo(N);
}