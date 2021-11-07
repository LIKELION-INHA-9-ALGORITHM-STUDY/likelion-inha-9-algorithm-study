#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr.front());
    int now=arr.front();
    for(int i=1;i<arr.size();i++){
        if(now != arr[i]){
            answer.push_back(arr[i]);
            now=arr[i];
        }
    }
    return answer;
}