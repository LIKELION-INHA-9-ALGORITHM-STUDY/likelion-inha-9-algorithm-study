#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
     string answer = ""; //완주하지 못한 선수 1명
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end()); //각각 오름차순 정렬
    
    for(int i=0; i<participant.size(); i++) { //첨부터 비교해나감
        if(participant[i]!=completion[i]){ //두 벡터의 i번째 원소가 서로 다르면
            answer=participant[i]; //그 사람이 완주 못 한 것
            break;
        }
    }
    return answer;
}