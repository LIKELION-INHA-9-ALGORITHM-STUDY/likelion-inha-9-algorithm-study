#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    while(!citations.empty())
    {
        int check = citations.back();
        if(check < citations.size())
            answer=answer<check?check:answer;
        else
            answer = answer<citations.size()?citations.size():answer;
        citations.pop_back();
    }
    return answer;
}