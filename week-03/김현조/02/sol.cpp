// 문제 2. 가장 큰 수 - 정렬


// 0 또는 양의 정수가 주어졌을 때
// 정수를 이어 붙여 만들 수 있는 가장 큰 수?


// 주어진 수열에서 배치를 바꿔서 가장 큰 수를 찾아야 함
// 단순 오름/내린차순 정렬이 아닌, 새로운 기준을 만들어서 정렬하자

// 문자열 2개를 비교 -> 합칠 때 더 큰 문자열 순서대로 정렬


#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

bool Standard(string A, string B)
{
    if(A+B > B+A)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> Array;

    // vevtor -> string vector
    for(int i=0; i<numbers.size(); i++)
        Array.push_back(to_string(numbers[i]));

    // 사용자 함수 Standard로 정렬
    sort(Array.begin(), Array.end(), Standard);

    // 원소들 다 합치기
    for(int i=0; i<Array.size(); i++)
        answer=answer+Array[i];

    // 처음 수가 0이면 뒤 수도 모두 0이므로 0 반환
    if(answer[0]=='0')
        answer="0";


    return answer;
}