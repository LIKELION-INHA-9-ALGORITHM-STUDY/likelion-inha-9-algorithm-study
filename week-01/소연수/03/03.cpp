#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, int> cm;
    int size = clothes.size();
    for (int i{0}; i < size; i++)
    {
        cm[clothes[i][1]]++;
    }

    int answer = 1;
    map<string, int>::iterator iter;
    for (iter = cm.begin(); iter != cm.end(); iter++)
    {
        answer *= (iter->second) + 1;
    }
    /*
    각 옷의 종류 당 경우의 수: (옷 개수 + 1(안 입는 경우))
    => 하루 의상 경우의 수(예)
    : {(headgear개수 + 1 )*(eyewear개수 + 1)*(face개수 + 1)} - 1(모두 안 입는 경우 빼기)       */

    return --answer;
}