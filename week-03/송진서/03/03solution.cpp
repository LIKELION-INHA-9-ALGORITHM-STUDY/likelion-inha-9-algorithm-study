#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // 0~10000 사이의 수들로 이루어진 1~1000개 짜리의 배열
    // 여기서 n 이상의 수가 n개 있음 이 n의 최댓값을 찾아라
    // 일단 n이 1000은 안 넘음
    int size=sizeof(citations)/4; //벡터 원소 갯수
    sort(citations.begin(), citations.end(), greater<int>()); //내림차순 벡터 정렬
    
    int count[1000]; //n이상의 수가 각각 몇 개 있는지 차례로 나타내는 배열, 이 배열 또한 내림차순으로 정렬되어 있을 것임
    // 원소 개수인 count[?]의 값과 원소 목록인 citations[?]의 값이 같아지는 지점을 찾아야(아직 원소목록이 더 큼)
    int i=0; //index
    while(i<=size){ //기준점이 될 수가 원소 개수가 될 때까지 즉 최대 ~1000.
        if(i<citations[i]) //아직 원소개수보다 원소크기가 더 크면
            i++;
        else //원소개수>원소크기됨
            break;
    }
    return i;
}