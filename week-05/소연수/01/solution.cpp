#include <vector>
using namespace std;

// 1. 체육복 개수 설정
// 2. 빌려줄 수 있으면 빌려주기
// 3. 체육복 있는 학생 세기

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> uniform(n + 1, 1); 
    uniform[0] = 0;
    // 학생 별 가지고 있는 체육복 개수를 담을 벡터. (0인덱스 사용 안 함)
    // -> 기본 1 설정에, 도난당했으면 -1. 여벌 체육복이 있으면 +1.
    
    for(int l : lost){
        --uniform[l];
    }
    for(int r : reserve){
        ++uniform[r];
    }
    // 1번 끝~
    
    for(int i{ 1 }; i < uniform.size(); i++){
        if(uniform[i] == 0){
            if(uniform[i+1] == 2){ // 뒷 번호 학생이 여벌의 체육복을 가지고 있다면
                uniform[i+1]--; // (뒷 번호 학생 체육복)--
                uniform[i]++;
            }
            else if(uniform[i-1] == 2){
                uniform[i-1]--;
                uniform[i]++;
            }
        }
    }
    // 2번 끝~
    
    int answer = 0;
    for(int u : uniform){
        if(u > 0) answer++;
    }
    return answer;
}