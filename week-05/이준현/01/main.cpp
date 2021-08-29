#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student;
    int reserveSize = reserve.size();
    int lostSize = lost.size();
    for(int i=0;i<n;i++){
        student.push_back(1);
    } // 모든 학생들의 체육복을 1로 초기화
    for(auto i : reserve){
        student[i-1]++;
    }
     // 여별체육복을 들고온 사람들을 1씩 더해줌
    for(auto i : lost){
        student[i-1]--;
    } // 도난당한 체육복들을 삭제한다.

    for(int i=0;i<n;i++){
        if(student[i]==2){
            if(i-1!=-1&&student[i-1]==0){
                student[i]--;
                student[i-1]++;
            }
            else if(i+1!=n&&student[i+1]==0){
                student[i]--;
                student[i+1]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(student[i]>=1){
            answer++;
        }
    }
    return answer;
}