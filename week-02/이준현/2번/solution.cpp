#include <string>
#include <vector>
#include <map> // 배포날짜를 key, 배포하는 기능의 수를 value로 하기 위해 map을 사용하였습니다.
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map<int, int> Map;
    int proSize = progresses.size(); // 저번 피드백에서 영빈님이 for문을 사용할때 size를 미리 선언하면 시간이 조금 더 줄어든다는 것을 참고하였습니다!
    int pre_day = 0; // 앞선 기능 개발 날짜와 현재 기능개발날짜를 비교하기위해
    int cur_day; // 각각의 변수를 선언해 줍니다.
    for(int i=0;i<proSize;i++){
        cur_day = 0;
        while(progresses[i]<100){ // 해당 기능이 100%가 될때까지 배포날짜를 더해줍니다.
            progresses[i] += speeds[i];
            cur_day++ ;
        }
        if(pre_day>=cur_day) { // 앞선 기능 개발이 현재 기능개발보다 시간이 더 오래걸렸다면 앞선 기능의 배포날짜에 해당 기능을 같이 배포함으로 1을 더해줍니다.
            Map[pre_day]++;
        }
        else{ // 앞선 기능보다 현재 기능 개발이 더 오래걸린다면 새로운 key값을 통해 map에 넣어줍니다.
            Map[cur_day]++;
            pre_day = cur_day;
        }

    }
    for(auto key : Map){
        answer.push_back(key.second);
    }
    return answer;
}
//    auto iter = Map.begin();
//map<int, int> :: iterator  iter = Map.begin();
//auto iter = Map.begin();
//while(iter!=Map.end()){
// answer.push_back(iter->second);
// iter++;
//}
// 처음에는 이 방법으로 for문을 돌렸는데 ide가 auto를 사용하는 것을 추천하여 지금 소스코드와 같이 바꿔보았습니다.