//// 210826 멋사 코테 스터디 5주차 - Greedy
// 문제 1. 체육복

// //// Greedy (탐욕법)

// : 최적의 해를 구할 때 사용하는 알고리즘
// : 그 상황에서 가장 좋다는 걸 선택하는 방식이므로 항상 가장 좋은 결과는 아님
// : -> 근삿값 구하는 용도

// // 탐욕법 충족 조건
// - 앞의 선택이 이후의 선택에 영향을 주지 않을 때
// - 문제에 대한 최적해가 부분문제에 대해서도 역시 최적해일 때


// 학생 번호 : 체격순 -> 바로 앞뒷 번호만 가능
// 최대한 많은 학생 빌려주기
// 전체 학생 n
// 체육복 없는 학생들 번호 배열 lost
// 여벌 체육복 번호 배열 reserve


// 전체 학생의 번호 넣을 벡타 : n+2 크기로 생성, 1로 설정
// lost 값은 0, reserve 값은 1로 설정
// 옆 학생이 없고 나에게 여분 있으면 체육복 준다

#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 전체 학생
    vector<int> all(n+2, 1);

    for(int i=0; i<lost.size(); i++)
        all[lost[i]]--;
    for(int i=0; i<reserve.size(); i++)

    // 옆 학생이 없고 나에게 여분 있으면 
    for(int i=1; i<=n; i++) {
        if(all[i-1]==0 && all[i]==2) {
            all[i-1]=all[i]=1;
        } else if (all[i]==2 && all[i+1]==0) {
            all[i]=all[i+1]=1;
        }
    }

    for (int i=0; i<=n; i++) {
        if(all[i]>0)
            answer++;
    }

    return answer;
}