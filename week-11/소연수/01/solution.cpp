#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string s[3] {"4","1","2"}; // 나머지가 0일때 0대신 4, 나머지 연산 결과가 곧 인덱스
    
    while(n){
        answer = s[n % 3] + answer;
        
        if(n % 3 == 0){
            // 3으로 나누어 떨어질 때
            n = n / 3 - 1;
        }
        else{
            n /= 3;
        }
    }
    return answer;
}