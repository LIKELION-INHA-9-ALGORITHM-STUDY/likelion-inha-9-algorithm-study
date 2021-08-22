#include <string>
#include <vector>
#include <cmath>

using namespace std;

int maxDivisor(int brown, int yellow){
    int max;을
    for(int i=1;i<=sqrt(yellow);i++){
        if(yellow%i==0){
            int second = yellow/i;
            if((i+2)*(second+2)-yellow==brown){ // brown 전혀 생각하지 않고 처음에 yellow만 고려하여 코드를 구성했다가 2시간이 걸렸네요...ㅠ
                max=i;
            }
        }
    }
    return max;
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int firstDivisor = maxDivisor(brown,yellow);
    int secondDivisor = yellow/firstDivisor;

    if(secondDivisor>=firstDivisor){
        answer.push_back(secondDivisor+2);
        answer.push_back(firstDivisor+2);
    }
    else{
        answer.push_back(firstDivisor+2);
        answer.push_back(secondDivisor+2);
    }
    return answer;
}