#include <string>
#include <vector>
#include <unordered_map>
// 주제가 hash라 set과 map중 map을 활용해 보았습니다.
// 찾아보니 정렬이 필요없을때 unordered_map을 활용하는 것이 더 빠르다고 봤습니다.
//https://blog.naver.com/webserver3315/221678909965 요기 참고했습니다!
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mapForCompletion; // completion 값을 가지고 있을 map을 선언
    unordered_map<string, int>::iterator mapIter; // participant 값과 비교할때 find() 메소드가 이터레이터를 반환하기에 선언하였습니다.
    for(int i=0;i<completion.size();i++){
        mapForCompletion[completion[i]]+=1;
        //처음에는 map의 key값이 중복불가라는것을 생각하지 못하고 mapForCompletion.insert(make_pair(completion[i], false)로
        //선언하였지만 중복시 insert가 실행되지 않는것을 생각하지 못해 <string, int>로 바꾸기까지 1시간 걸렸습니다 ㅠㅠㅠ
    }
    for(int i=0;i<participant.size();i++){
        mapIter = mapForCompletion.find(participant[i]);
        if(mapIter==mapForCompletion.end()){ // map.find()메소드가 find를 하지 못할 시 해당 맵의 end()를 반환하는것에 착안하였습니다.
            return participant[i];
        }
        else{
            mapIter->second-=1;
            if(mapIter->second<0){// map의 value값을 중복횟수로 생각하고 1씩 감소를 시키면서 0이하가되면 return 시키도록 하였습니다
                return participant[i];
            }
        }
    }

    return answer;
}