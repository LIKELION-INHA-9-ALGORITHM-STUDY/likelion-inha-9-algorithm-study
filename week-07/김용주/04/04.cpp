#include <string>
#include <vector>

using namespace std;
int p_m[2] = { -1,1 };
int answer = 0;
/*
* dfs로 풀었습니다. 재귀를 이용한 dfs로 했고 numbers의 벡터의 끝에 있는 숫자까지 가서 target이 맞으면 answer를 +1하였습니다.
*/
void dfs(int cnt, int now, int size, int target, vector<int>numbers)
{
    if (cnt == size)
    {
        if (now == target)
            answer++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        dfs(cnt + 1, now + (numbers[cnt] * p_m[i]), size, target, numbers);
    }
}
int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers.size(), target, numbers);
    return answer;
}