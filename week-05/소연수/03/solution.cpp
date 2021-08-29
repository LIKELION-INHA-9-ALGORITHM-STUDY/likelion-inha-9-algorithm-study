#include <string>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.length() - k;
    
    int index{ -1 };
    for (int i = 0; i < size ; i++) { // 반환할 수의 자릿수만큼 반복
        char max{ 0 }; // 각 구간에서의 최댓값을 담을 변수
        for (int j = index + 1; j <= k + i; j++) {
            if (number[j] > max) {
                index = j;
                max = number[j];
            }
        }
        // 반복문의 첫 실행에서 
        // max에는 [0, k+i] 구간의 최댓값이, index에는 최댓값을 가지고 있는 인덱스 값이 저장된다
        // -> 다음 반복에서는 [전 실행에서 최댓값을 찾았던 index의 다음 값, k+i] 구간에서의 최댓값을 찾아 answer에 추가한다.
        answer += max;
    }
    return answer;
}