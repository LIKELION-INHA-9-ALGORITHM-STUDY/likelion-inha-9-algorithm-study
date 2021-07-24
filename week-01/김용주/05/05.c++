#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
struct play_ind
{
    int play, ind;
};
bool compare(play_ind a, play_ind b)
{
    if (a.play > b.play)
        return true;
    else if (a.play == b.play)
        return a.ind < b.ind;
    else
        return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<int>> m;
    map<int,string> total_max;
    vector<play_ind> vec;
    for (int i = 0; i < genres.size(); i++)
    {
        if (m.find(genres[i]) != m.end())
        {
            m.find(genres[i])->second.push_back(i);
            m.find(genres[i])->second[0] -= plays[i];
        }
        else
        {
            vector<int> v;
            v.push_back(-plays[i]);
            v.push_back(i);
            m.insert({ genres[i], v});
        }
        vec.push_back({ plays[i],i });
    }
    for (auto iter : m)
        total_max.insert({ iter.second[0],iter.first });
    sort(vec.begin(),vec.end(),compare);
    for (auto iter : total_max)
    {
        vector<int> music = m.find(iter.second)->second;
        int cnt = 0;
        for (int i = 0; i < vec.size();i++)
        {
            for (int j = 1; j < music.size(); j++)
            {
                if (vec[i].ind == music[j])
                {
                    cnt++;
                    answer.push_back(vec[i].ind);
                    vec[i].ind=-1;
                }
            }
            if (cnt == 2)
                break;
        }
    }

    return answer;
}
