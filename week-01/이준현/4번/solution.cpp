#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int round = 1;
    while(n>=1){
        if(a<b){
            if(a%2!=0&&(a+1)==b){ // a보다 b가 크고 a가 짝수일 시 다른경기를 하고 a가 홀수라면 b랑 차이가 1이 났을때 붙게됨으로 이렇게 나타냈습니다.
                return round;
            }
        }
        else if(b%2!=0&&(b+1)==a){
            return round;
        }

        n = n/2;
        a%2==0?a/=2:a=(a+1)/2; // 요거는 리액트 스터디 하다보니... 요런식으로 표현하는게 익숙해져서..
        b%2==0?b/=2:b=(b+1)/2; // 해당 수가 홀수이면 1을 더해줘서 적정값을 넣게하도록 하였습니다.
        round++;
    }
}