#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> answer;

    for (int i{0}; i < progresses.size(); i++){
        int pre; // 앞 기능이 필요한 작업일 수
        double remain{ceil((100 - progresses[i]) / double(speeds[i]))};

        if (i == 0 || remain > pre){ // 첫 번째 기능이거나,
        // 앞 기능의 잔여일 수보다 현 기능의 잔여일 수가 큰 경우(앞 기능 먼저 배포하면 되는 경우)
            answer.push_back(1);
            pre = remain;
        }
        else{
            answer.back()++;
        }
    }
    return answer;
}