#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> rent;
    for (int i = 0; i < commands.size(); i++) {
        for (int j = 0; j < array.size(); j++)
            rent.push_back(array[j]);
        int start = commands[i][0];
        int end = commands[i][1];
        int wish = commands[i][2];
        sort(rent.begin() + start-1, rent.begin() + end);
        answer.push_back(rent[start + wish-2]);
        rent.clear();
    }
    return answer;
}