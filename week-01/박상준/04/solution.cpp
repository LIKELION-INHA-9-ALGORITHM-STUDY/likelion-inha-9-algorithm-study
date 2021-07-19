#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    // 같은 대진인 경우, a와 b에 대해 각각을 2로 나눈 몫 + 나머지의 값이 같다.
    // 다음 대진에서 새로 주어지는 번호는 기존의 번호를 2로 나눈 몫 + 나머지의 값이다.
    // 따라서 a == b 일때 break.
    while (true) {
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
        if (a == b) break;
    }
    return answer;
}