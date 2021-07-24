//// 210719 멋사 코테 스터디 1주차 - HASH
// 문제 1. 완주하지 못한 선수


/* 
map : index를 문자열로 받는 배열 ㅇㅇ (일반 Array는 index가 숫자)
-> 각 노드가 key0value 쌍으로 이루어진 트리 (파이썬에서는 dictionary)

unordered_map : map보다 더 빠른 탐색을 위한 자료구조 C++ STL
- Hash Table로 구현, O(1), map은 Binary Search Tree로 O(logN)
- 중복 data 허용하지 않고 map에 비해 data가 많으면 더 좋음
- key가 유사한 data가 많으면 hash 충돌로 인해 성능 떨어질 수 있음
- 함수 
: empty, size, operator, find(key), count(key), insert({key, value}), erase(key), clear, operator=
- index로 접근 불가 -> iterator로 접근해야함
*/

#include <iostream>
using namespace std;

#include <string>
#include <vector> // Extendable Array
#include <unordered_map>

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
    // 선언
    unordered_map<string, int> temp;

    // 범위기반 for문 - 알아서 처음부터 끝까지 순회 
    for (string name : participant)
    {
        temp[name]++; // 참가자들을 key 값으로 name 지정
    }

    for (string name : completion)
    {
        temp[name]--; // 완주자들은 값 감소
    }

    for (auto pair : temp)
    {
        if (pair.second > 0)
        {
            answer = pair.first;
            break;
        }     
    }
    return answer;
}