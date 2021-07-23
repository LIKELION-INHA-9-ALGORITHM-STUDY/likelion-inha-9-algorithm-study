#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    map<string, int> m; // string(key): 선수 이름, int(value): 완주하지 못한 선수를 구별하기 위한 정수

    for (string c : completion)
    {
        m[c]++; // 완주자의 이름을 key로 했을 때 value: 1 (value의 default가 0)
    }
    for (string p : participant)
    {
        m[p]--; // 참가자의 이름을 key로 했을 때의 value에서 1빼기
        if (m[p] == -1)
        { // 완주자 벡터에 없고 참가자 벡터에만 있는 경우 value: -1
            return p;
        }
    }
}

string solution_(vector<string> participant, vector<string> completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int num = completion.size();
    for (int i{0}; i < num; i++)
    {
        if (participant[i] != completion[i])
        {
            return participant[i];
        }
    }
}