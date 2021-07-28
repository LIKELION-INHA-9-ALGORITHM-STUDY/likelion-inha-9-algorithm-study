#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridgeQ; // 다리의 위의 상태를 표현할 queue
    queue<int> truckQ;// vector의 자료구조상 뒤에서부터 pop을 실시하기에 앞에서부터 삭제하기 편하게 queue로 바꾸었습니다.
    int bridge_weight = 0;
    for(int i=0;i<bridge_length;i++){
        bridgeQ.push(0);
    }
    for(int truck : truck_weights){
        truckQ.push(truck);
    }
    while(!bridgeQ.empty()){ // truckQ를 모두 pop시키고 나면 bridgeQ의 크기가 pop으로 인해 줄어듬으로 empty를 통해 while문을 돌렸습니다.
        bridge_weight -= bridgeQ.front(); // 매 초마다 다리위에 있는 가장 앞 부분의 차가 하차함으로 무게를 빼줍니다.
        bridgeQ.pop(); //해당 차량을 제거(0일수도 있습니다.)
        answer++;
        if(!truckQ.empty()){
            if(bridge_weight+truckQ.front()<=weight){ // 현재 다리위의 차량의 하중에 대기하고있는 가장 앞차량의 무게합이 weight보다 작다면
                bridge_weight+=truckQ.front(); // 하중을 더해주고
                bridgeQ.push(truckQ.front()); // bridgeQ에 push를 함으로서 다리위에 올려주는것을 표현하며
                truckQ.pop(); // 제거하였습니다.
            }
            else{
                bridgeQ.push(0); // 다리위 차량의 하중합이 weight을 넘었을때 차를 올리지 않음으로 0을 push 하면서 다리 길이를 유지시켜줍니다.
            }
        }
    }


    return answer;
}