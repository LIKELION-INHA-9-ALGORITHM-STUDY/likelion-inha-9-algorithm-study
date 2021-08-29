#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 모든 학생들의 체육복 현황을 표현한 배열 s를 만든다
    // 원래 모든 학생들이 체육복이 하나씩 있었다고 가정하고, 여기에 여분을 더하거나 잃어버린걸 빼는 작업을 하면 된다
    int* s=new int[n];
    for(int i=0;i<n;i++) s[i]=1;
    for(auto i:lost) s[i-1]--; //s와 달리 lost, reserver는 번호로 따지므로, 즉 0이 아닌 1부터 시작하므로 s와 맞추기 위해서는 인덱스에서 1을 빼줘야
    for(auto i:reserve) s[i-1]++;
    
    for(int i=0;i<n;i++){ //차례대로 순회
        if(s[i]==0){ //체육복 없는 학생 발생
            if(s[i+1]==2) {//뒷사람이 여분이 있을 경우
                s[i]++;
                s[i+1]--; //뒷사람 체육복 -1
            }
            else if(s[i-1]==2){ //뒷사람은 없고 앞사람만 여분이 있을 경우
                s[i]++;
                s[i-1]--; //앞사람 체육복 -1
            }
        }            
    }
    for(int i=0;i<n;i++){
        if(s[i]!=0) answer++; //체육복 1개 이상인 사람 카운트
    }
    
    return answer;
}