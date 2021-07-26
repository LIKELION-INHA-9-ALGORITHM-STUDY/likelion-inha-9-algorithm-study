#include <iostream>
using namespace std;

//12 34 56 78 4>2>1, 7>4>2
//1 2 3 4
//1 2

int solution(int n, int a, int b) {
    int answer = 0;
    while(1){ 
        a=(a%2==0?a:a+1)/2; //A의 새 번호 배정 연산
        b=(b%2==0?b:b+1)/2; //B의 새 번호 배정 연산
        answer++; // 번호 배정 연산이 한 번 이루어질 때마다 answer++
        if((b-a)==1){
            break; //멈춰!
        }
    }
    return answer+1; //새 번호 배정이 i번 이루어졌다는 건 i+1번째 라운드에서 두 참가자가 붙게 되었다는 의미이므로, answer+1을 최종 답으로 return
}