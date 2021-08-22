#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool isPrime(int x){
    if(x<2){
        return false;
    }
    for(int i=2;i<=sqrt(x);i++){ // 자바 수업시간에 소수찾기는 제곱근으로 찾는게 최고라고 배웠습니당.
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> number; // 중복을 없에기 위하여 set 사용
    sort(numbers.begin(), numbers.end()); // next_permutation을 사용할려면 오름차순으로 정렬해야한다고 배웠습니당.
    int numbersSize = numbers.size();
        do {
            for(int i=1; i<=numbersSize; i++) {
                string subset = numbers.substr(0, i);
                number.insert(stoi(subset)); // 처음에는 -'0'으로 처리하려 하였으나 이건 char 형태일때만 가능하여서 stoi라는 함수를 처음 써봤습니다.
            }
        } while (next_permutation(numbers.begin(), numbers.end()));
 // 순열관련 알고리즘을 찾던 도중 해당 문법을 알게되었습니다. https://mjmjmj98.tistory.com/38을 참고하였습니다.
        for(int num : number){
            if(isPrime(num)){
                answer++;
            }
        }
    return answer;
}