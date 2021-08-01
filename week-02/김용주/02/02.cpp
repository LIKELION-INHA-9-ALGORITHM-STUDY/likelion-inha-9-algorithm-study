#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    //100에서 progresses 값 까지 speed의 값으로 딱 떨어지는 경우와 아닌경우
    for(int i=progresses.size()-1;i>=0;i--)
    {
        int check = 100-progresses[i];
        if(check%speeds[i]==0)
            s.push(check/speeds[i]);
        else
            s.push(check/speeds[i]+1);
    }
    //가장 처음 값에 비해 더 큰 날짜가 나올떄까지 날짜를 세야함
    int max_num=s.top();
    s.pop();
    int ans=1;
    while(!s.empty())
    {
        if(max_num < s.top())
        {
            answer.push_back(ans);
            ans=1;
            max_num = s.top();
        }
        else
            ans++;
        s.pop();
    }
    // 맨 마지막 값이 push되어야함
    answer.push_back(ans);
    return answer;
}