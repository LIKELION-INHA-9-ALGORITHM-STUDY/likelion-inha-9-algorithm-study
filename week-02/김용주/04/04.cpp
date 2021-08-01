#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack <pair<int, int>> s;
    s.push({ 0,prices[0] });
    for (int i = 1; i < prices.size(); i++)
    {
        while (!s.empty())
        {
            if (s.top().second > prices[i])
            {
                answer[s.top().first] = i - s.top().first;
                s.pop();
            }
            else
                break;
        }
        s.push({ i,prices[i] });
    }
    while (!s.empty())
    {
        answer[s.top().first] = prices.size() - s.top().first - 1;
        s.pop();
    }
    return answer;
}