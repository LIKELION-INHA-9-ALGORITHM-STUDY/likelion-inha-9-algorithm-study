#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//아래에서 위로 올라가면서 가장 최대 값이 되는 합을 찾는다.
int solution(vector<vector<int>> triangle) {
    long long answer = 0;
    long long dp[501][501]={0};
    for(int i=0;i<triangle[triangle.size()-1].size();i++)
        dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    for(int i = triangle.size()-1;i>0;i--)
    {
        for(int j = 0 ; j<triangle[i-1].size();j++)
        {
            dp[i-1][j] = max(dp[i][j],dp[i][j+1])+triangle[i-1][j];
        }
    }
    answer=dp[0][0];
    return answer;
}