#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    while(!scoville.empty())
    {
        pq.push(scoville.back());
        scoville.pop_back();
    }
    while(pq.top()<K)
    {
        int min_num = pq.top();
        pq.pop();
        int sec_num = pq.top();
        pq.pop();
        pq.push(min_num+(sec_num*2));
        answer++;
        if(pq.size()<2 && pq.top() <K)
            return -1;
    }
    return answer;
}