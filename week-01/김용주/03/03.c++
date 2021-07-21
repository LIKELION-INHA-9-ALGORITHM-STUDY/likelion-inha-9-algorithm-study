#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string, int> m;
    for (int i = 0; i < clothes.size(); i++)
    {
        if (m.find(clothes[i][1]) != m.end())
            m.find(clothes[i][1])->second++;
        else
            m.insert({ clothes[i][1],1 });
    }
    for (int i = 0; i < clothes.size(); i++)
    {
        int ans = 0;
        if (m.find(clothes[i][1])->second != 0)
        {
            ans = m.find(clothes[i][1])->second + 1;
            m.find(clothes[i][1])->second = 0;
            answer *= ans;
        }
    }
    return answer - 1;
}