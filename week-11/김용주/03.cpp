#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
int att = 0; int tu_size = 0;
vector<int> test;
vector<vector<int>> ans;
/*
재귀를 통해서 attribute의 조합을 testcase로 만들었습니다. 그 후 각 testcase마다 최소성과 유일성을 모두 검사하고 해당하는 경우에만 answer벡터에 저장하는 방식으로 코드를 작성하였습니다.
*/
void reculsive(vector<vector<string>> relation, int startp, int cnt, int obj)
{
    if (cnt == obj) //원하는 자리수 되면 check
    {
        for(int i=0;i<answer;i++) //최소성 test
        {
        //현재 test중인 testcase가 이제껏 answer중의 하나의 문자열을 완전히 포함하는 지 확인
            int same_check=ans[i].size();
            for(int m=0;m<ans[i].size();m++)
            {
                for(int t=0;t<test.size();t++)
                {
                    if(ans[i][m]==test[t])
                        same_check--;
                }
                if(same_check==0)
                    return;
            }
        }
        //유일성 check
        //test해보려는 attribute에 따라 각 tuple의 값을 string으로 넣어두고
        string v[22]; bool check = true;
        for (int tuple = 0; tuple < tu_size; tuple++)
        {
            for (int i = 0; i < test.size(); i++)
            {
                v[tuple] += relation[tuple][test[i]];
            }
        }
        //넣어둔 string 중 같은것이 있는지 확인
        for (int tuple = 0; tuple < tu_size; tuple++)
        {
            for (int t = tuple + 1; t < tu_size; t++)
            {
                if (v[tuple] == v[t])
                {
                    check = false;
                    break;
                }
            }
            if (!check)
                break;
        }
        if (check)
        {
            vector<int> v;
            for (int i = 0; i < test.size(); i++)
                v.push_back(test[i]);
            ans.push_back(v);
            answer++;
        }
        return;
    }
    for (int i = startp; i < att; i++)
    {
        test.push_back(i);
        reculsive(relation, i + 1, cnt + 1, obj);
        test.pop_back();
    }
}
int solution(vector<vector<string>> relation) {
    tu_size = relation.size(); //tuple의 개수
    att = relation[0].size(); //attribute의 개수
    
    for (int i = 1; i <= att; i++) //1의 자리 수 부터 att의 개수의 자리수까지 test case만듦
    {
        reculsive(relation, 0, 0, i);
    }
    return answer;
}