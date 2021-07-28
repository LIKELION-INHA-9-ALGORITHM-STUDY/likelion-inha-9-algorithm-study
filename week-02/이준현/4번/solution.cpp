#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> priceQ;
    int index = 1; // prices가 기본적으로 2이상이라고 주어지고 현재 돈과 이후의 돈들을 비교해야함으로 전역적으로 선언하였습니다.
    for(int price : prices){ // 앞에서 부터 차근차근 없에주기 위해 queue를 사용하였습니다.
        priceQ.push(price);
    }
    while(!priceQ.empty()){
        int price = priceQ.front();
        priceQ.pop();
        int second = 0;
        for(int i = index;i<prices.size();i++){ // 만약 해당 가치가 마지막 인덱스라면 second를 0으로 하게 하고 아니라면 기본적으로 1초를 더하게 한뒤,
            second++;
            if(price>prices[i]){ //자신의 다음 인덱스가 자신보다 작다면 break을 통해 for문을 빠져나가게 합니다.
                break;
            }
        }
        answer.push_back(second);
        index++;
    }

    return answer;
}