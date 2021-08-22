#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int A[] = {1,2,3,4,5};
    int B[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int C[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int a=0;
    int b=0;
    int c=0;
    int size = answers.size();
    for(int i=0;i<size;i++){
        if(A[i%5]==answers[i]){
            a++;
        }
        if(B[i%8]==answers[i]){
            b++;
        }
        if(C[i%10]==answers[i]) {
            c++;
        }
    }
    int maxValue = max({a,b,c});
    if(a==maxValue){
        answer.push_back(1);
    }
    if(b==maxValue){
        answer.push_back(2);
    }
    if(c==maxValue){
        answer.push_back(3);
    }
    //무식 그자체로 풀었습니다..
    return answer;
}