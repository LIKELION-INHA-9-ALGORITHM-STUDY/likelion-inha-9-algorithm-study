#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//내림차순 정렬 용 함수
bool func(char a, char b) {
    return a > b;
}

string solution(string number, int k) {
    int cnt = 0;
    string temp = number;
    sort(temp.begin(), temp.end(), func);

    if (temp == number) {
        // 이미 내림차순 정렬된 수인 경우 -> 그냥 뒤에서 k개 지우자.
        while (cnt < k) {
            number.pop_back();
            cnt++;
        }
    }

    else {
        // 내림차순 정렬된 수가 아닌 경우
        while (cnt < k) {
            for (int i = 0; i < number.length() - 1; i++) {
                if (number[i] < number[i + 1]) { // a 뒤에 오는 수가 a 보다 큰 경우.
                    number = number.substr(0, i) + number.substr(i + 1); // a 삭제
                    cnt++; // 삭제 횟수 ++
                    break;
                }
                // a 뒤에 오는 수가 a 보다 작거나 같은 경우 그냥 두기
            }
        }
    }
    return number;
}