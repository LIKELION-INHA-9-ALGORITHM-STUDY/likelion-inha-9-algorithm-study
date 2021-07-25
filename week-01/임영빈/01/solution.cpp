#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
 
string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> hash_map;
    for (string key : participant)
    {
        hash_map[key]++;
    }
    for (string key : completion)
    {
        hash_map[key]--;
    }
    for (auto pair : hash_map)
    {
        if (pair.second > 0)
        {
            answer = pair.first;
            break;
        }
    }
    return answer;
}