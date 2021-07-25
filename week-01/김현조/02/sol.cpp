// 문제 2. 전화번호 목록

#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

bool solution(vector<string> phone_book) {
    // 선언
    unordered_map<string, int> temp;

    for (int i = 0; i < phone_book.size(); i++)
    {
        string number = "";

        for (int j = 0; j < phone_book.size(); j++) // 부분 문자열 존재 확인
        {
            number += phone_book[i][j];
            temp[number]++;
        }
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        if (temp[phone_book[i]] > 1) // 빈도수 1 초과
            return false;
    }
    return true;
}