#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    // 사전순 정렬(유사 문자끼리 정렬됨.) -> 바로 뒤에 겹치는거 있는지만 보면 됨.
    bool answer = true;

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i].length() >= phone_book[i + 1].length()) continue;
        //앞 번호의 길이가 뒷 번호의 길이보다 길거나 같으면 중복 확률 x

        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) {
            answer = false; // 접두어인 경우.
            break;
        }
    }
    return answer;
}
