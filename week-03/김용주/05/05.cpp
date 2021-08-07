#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    int front = 0;
    for(int i=0;i<operations.size();i++)
    {
        if(operations[i][0]=='I')
        {
            string num = operations[i].substr(2,operations[i].size()-2);
            int in_num = stoi(num);
            pq.push(in_num);
        }
        else if(operations[i]=="D 1")
        {
            if(!pq.empty() || pq.size()-front != 0)
            {
                pq.pop();
                if(pq.size()==0)
                    front=0;
            }
        }
        else if(operations[i]=="D -1")
        {
            if(!pq.empty())
            {
                front++;
            }
        }
    }
    if(pq.size()-front == 0 || pq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if(pq.size()-front==1)
    {
        answer.push_back(pq.top());
        answer.push_back(0);
    }
    else
    {
        int size= pq.size()-front-1;
        int top = pq.top();
        pq.pop();
        answer.push_back(top);
        while(!pq.empty() && size != 0)
        {
            size--;
            top = pq.top();
            pq.pop();
        }
        answer.push_back(top);
    }
    return answer;
}