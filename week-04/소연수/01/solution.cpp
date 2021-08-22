#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int scores[3] = {
        0,
    };

    for (int i{0}; i < answers.size(); i++)
    {
        if (a[i % sizeof(a)] == answers[i])
            scores[0]++;
        if (b[i % sizeof(b)] == answers[i])
            scores[1]++;
        if (c[i % sizeof(c)] == answers[i])
            scores[2]++;
    }

    int max_score = max(scores[0], max(scores[1], scores[2])); // 가장 높은 점수를 담는 변수
    vector<int> answer;

    for (int i{0}; i < 3; i++) // 세 점수를 돌면서
    {
        if (scores[i] == max_score)  // 최고점과 같은 점수일 경우
            answer.push_back(i + 1); // answer 벡터에 추가
    }
    return answer;
}