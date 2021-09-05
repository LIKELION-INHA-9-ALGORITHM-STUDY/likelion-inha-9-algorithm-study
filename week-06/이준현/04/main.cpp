#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
    int test;
    int score;
    vector<int>stairs;
    vector<int>maxValue;

    cin >> test;
    for(int i=0;i<test;i++){
        cin >> score;
        stairs.push_back(score);
    }
    maxValue.push_back(stairs[0]);
    maxValue.push_back(max(stairs[1],stairs[0]+stairs[1]));
    maxValue.push_back(max(stairs[0]+stairs[2], stairs[1]+stairs[2]));
    for(int i=3;i<test;i++){
        maxValue.push_back(max(stairs[i]+maxValue[i-2], stairs[i]+stairs[i-1]+maxValue[i-3]));
    }
    cout << maxValue[test-1];
}