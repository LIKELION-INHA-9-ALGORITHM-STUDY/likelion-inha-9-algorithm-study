#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0;
    char maxnum = NULL;
    int maxindex = 0;
    for (int i = 0; i < number.size() - k; i++)
    {
        maxnum = number[start];
        maxindex = start;
        for (int j = start; j <= i + k; j++)
        {
            if (maxnum < number[j])
            {
                maxnum = number[j];
                maxindex = j;
            }
        }
        start = maxindex+1;
        answer += maxnum;
    }
    return answer;
}