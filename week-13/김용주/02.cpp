#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct s_e{
    int start,end;
};
int N;
vector<s_e> c;
//그리디로 끝나는 시간이 가장 이른 순서대로 정렬하여 끝나고 바로 시작할 수 있는 회의들로 찾았습니다.
bool compare(s_e a, s_e b)
{
    if(a.end==b.end)
        return a.start < b.start;
    return
        a.end < b.end;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int s,e;
        cin>>s>>e;
        c.push_back({s,e});
    }
    sort(c.begin(),c.end(),compare);
    int answer=1; int end_time=c[0].end;
    for(int i=1;i<c.size();i++)
    {
        if(end_time <= c[i].start)
        {
            answer++;
            end_time=c[i].end;
        }
    }
    cout<<answer<<endl;
    return 0;
}