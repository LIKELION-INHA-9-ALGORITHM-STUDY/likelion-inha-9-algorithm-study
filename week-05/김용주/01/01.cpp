#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lost_size = 0;
    bool check[31] = { 0 }; // lost에 있는 애들이면 reserve에 있어도 남에게 줄 수 없다
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    for (int i = 0; i < lost.size(); i++)
        check[lost[i]] = true;
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if(lost[i] == reserve[j] )// 자기가 reserve이자 lost인 애들이 가장 우선순위에 있음
            {
                lost[i] = 0;
                reserve[j] = 0;
                break;
            }
            if (reserve[j] == 0 || check[reserve[j]]) // 자기보다 후에 lost인 애들이 자기때문에 옷을 주지 않도록
                continue;
            if ( lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j] )// 전 후 애들이 reserve인지 확인
            {
                lost[i] = 0;
                reserve[j] = 0;
                break;
            }
        }
        if (lost[i] != 0) // lost가 옷을 얻어입으면 0으로 바꿨으니까 여전히 0이 아닌 애들은 lost인 애들인거
            lost_size++;
    }
    answer = n - lost_size; //전체 인원에서 여전히 lost인 인원 제외하면 답
    return answer;
}