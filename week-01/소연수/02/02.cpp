#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{

    sort(phone_book.begin(), phone_book.end());
    //["119", "1195524421", "97674223"]

    for (int i{0}; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            //"119" == "*119*(5524421)"
            //앞 전화번호의 길이만큼 뒤 전화번호를 잘랐을 때 서로 같으면 접두어인 경우
            return false;
        }
    }
    return true;
}