#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool check[11]={0};
    for(int i=0;i<numbers.size();i++)
        check[numbers[i]]=true;
    for(int i=0;i<10;i++)
    {
        if(!check[i])
            answer+=i;
    }
    return answer;
}