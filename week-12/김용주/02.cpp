#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//가장 큰 숫자를 w의 최대로 하고 다음으로 각 명함에서 w와 h중 작은 값으로 각 명함의 h로 둔다 할때 해당 h중 가장 큰 h를 찾아서 곱해줬습니다.
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i=0;i<sizes.size();i++)
    {
        answer = max(answer,max(sizes[i][0],sizes[i][1]));
    }
    int plus_ = 0;
    for(int i=0;i<sizes.size();i++)
    {
        plus_ = max(plus_,min(sizes[i][0],sizes[i][1]));
    }
    answer*=plus_;
    return answer;
}