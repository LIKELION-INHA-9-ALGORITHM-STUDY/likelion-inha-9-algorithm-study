#include <string>
#include <vector>
#include <unordered_map> // 요것도 해쉬라서 맵을 썼습니다.

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string prefix_number = "";
    unordered_map<string, bool> mapForPhoneBook;
    for(int i = 0; i < phone_book.size(); i++)
        mapForPhoneBook.insert(make_pair(phone_book[i], true)); // map을 선언할때 value를 boolean형태로 선언하여 존재여부를 판단할 수 있게하였습니다.

    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = 0; j < phone_book[i].size(); j++) {
            prefix_number = phone_book[i].substr(0,j); //phone_number[i]의 key크기만큼 반복하여 접두어를 하나씩 찾아나갔습니다.
            // 동시에 phone_number[i]와 같지 않으면서 map에는 존재한다면 false결과값을  반환하도록 하였습니다.
            if(mapForPhoneBook[prefix_number] && prefix_number!=phone_book[i]) {
                return false;
            }
        }
    }

    return answer;
}