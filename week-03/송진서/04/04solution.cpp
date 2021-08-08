#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    return answer;
    int size=sizeof(scoville)/4; //벡터 원소 갯수
    sort(scoville.begin(), scoville.end()); //오림차순 벡터 정렬
    int i=0;
    int sum=0;
    int count=0;
    while(1){
        int newFood=scoville[i]+scoville[i+1]*2; //새 음식 만듦
        sum=sum+scoville[i+2]; //나머지끼리의 합
        i++;
        if((newFood+sum)>size*K){ //K*size보다 합이 크면
            break;
        }
    }
    return i;
}