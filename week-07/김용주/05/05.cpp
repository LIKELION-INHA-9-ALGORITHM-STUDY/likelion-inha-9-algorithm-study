#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
문제가 한 컴퓨터에서 연결되어 있는 걸 다 찾아야 하기 때문에 bfs를 사용해야한다고 생각했습니다.
그래서 한 네트워크에서 연결된 컴퓨터 들을 다 찾아서 visit처리하고 queue에 넣어서 연결의 연결들을 다 찾았습니다.
그러다가 q가 empty인 상황인 하나의 네트워크가 끝난 상황일때 해당 네트워크에 연결되지 않은 컴퓨터 찾을 때면 새로 queue에 넣고 새로운 네트워크를 확인합니다
*/
bool visit[201] = { 0 };
queue<int> q;

void bfs(vector<int> one_com)
{
    for (int i = 0; i < one_com.size(); i++)
    {
        if (one_com[i] == 0 || visit[i])
            continue;
        visit[i] = true;
        q.push(i);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 1;
    q.push(0);
    visit[0] = true;
    while (!q.empty())
    {
        int s_p = q.front();
        q.pop();
        bfs(computers[s_p]);
        if (q.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (!visit[i])
                {
                    q.push(i);
                    visit[i] = true;
                    answer++;
                    break;
                }
            }
        }
    }
    return answer;
}