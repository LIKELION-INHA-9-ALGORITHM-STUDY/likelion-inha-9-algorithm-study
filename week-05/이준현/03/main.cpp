#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count=0;
    int numberSize = number.size();
    while(count != k){
        ++count; // 1개 삭제할때마다 삭제한 갯수를 카운트해서 k까지 돌림
        for(int i=0; i<numberSize; i++){
            if(i+1!=numberSize && number[i] < number[i+1]){ // 인덱스 이내이면서 i자리의 뒷값이 더 크면 i를 삭제해줍니다.
                number.erase(i,1);
                 break;
            }
            if(i==numberSize-2){ // 첫번째 if문을 통과 하였고 마지막 숫자와 그 앞의 숫자를 비교 후 이또한 걸러지지 않는다면 모든 숫자들이 같은 것임으
                if(number[i] > number[i+1]){
                    number.erase(i+1,1);
                    break;
                }
                else{ // 한개의 숫자를 지워준다.
                number.erase(0,1);
                }
            }
        }
    }
    answer=number;
    return answer;
}