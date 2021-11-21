#include <vector>
#include <iostream>

using namespace std;
// arr의 값이 바뀔때마다 확인하는 숫자를 갱신하고 바뀌지 않으면 다음 배열의 값을 확인한다
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int check=arr[0];
    answer.push_back(check);
    for(int i=1;i<arr.size();i++)
    {
        if(check==arr[i])
            continue;
        else
        {
            check=arr[i];
            answer.push_back(check);
        }
    }

    return answer;
}