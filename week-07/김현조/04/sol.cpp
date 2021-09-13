// 문제 4. 타겟넘버

// n개의 음이 아닌 정수 -> 조합
// 사용할 수 있는 숫자 담긴 배열 numbers
// 타겟넘버 target이 매개변수로 주어짐 -> 경우의 수


// 재귀함수로 모든 경우의 수 check
// numbers안의 숫자들을 이용한 횟수 count가 size와 같을 때 재귀 끝


#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
int targetNum;

void dfs(int count, int nowTarget, vector<int> &numbers) 
{
    if(count == numbers.size())
    {
        if(nowTarget == targetNum)
            answer++;
            return;
    }

    int nextTarget1 = nowTarget + numbers[count];
    int nextTarget2 = nowTarget - numbers[count];

    dfs(count+1, nextTarget1, numbers);
    dfs(count+1, nextTarget2, numbers);
}


int solution(vector<int> numbers, int target) {
    targetNum = target;
    dfs(0, 0, numbers);
    return answer;
}