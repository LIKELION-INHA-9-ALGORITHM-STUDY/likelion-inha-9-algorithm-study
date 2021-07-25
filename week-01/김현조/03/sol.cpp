// 문제 3. 위장

#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

int solution(vector<vector<string>> clothes) 
{
    // 선언
    unordered_map<string, int> temp;
    int answer = 1;

    // 범위기반 for문 - 알아서 처음부터 끝까지 순회 
    for (int i = 0; i < clothes.size(); i++)
    {
        temp[clothes[i][1]]++; // 참가자들을 key 값으로 name 지정
    }
  
    for (auto pair : temp)
    {
        answer *= (pair.second + 1);
    }
    return answer - 1;
}