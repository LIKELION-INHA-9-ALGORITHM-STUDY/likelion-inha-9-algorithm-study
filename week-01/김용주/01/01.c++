#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int>m;
    for (int i = 0; i < participant.size(); i++)
    {
        if (m.find(participant[i]) == m.end())
            m.insert({ participant[i],1 });
        else
            m.find(participant[i])->second++;
    }
    for (int i = 0; i < completion.size(); i++)
    {
        if (m.find(completion[i]) != m.end())
        {
            m.find(completion[i])->second--;
        }
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second != 0)
            answer = iter->first;
    }
    return answer;
}