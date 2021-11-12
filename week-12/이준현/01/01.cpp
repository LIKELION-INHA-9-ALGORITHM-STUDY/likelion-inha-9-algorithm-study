#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    for(int i=0;i<10;i++){
        auto iter =  find(numbers.begin(),numbers.end(),i);
        if(iter == numbers.end()){
            answer += i;
        }
    }
    if(answer!=-1){
        answer++;
    }
    return answer;
}