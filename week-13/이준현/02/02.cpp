#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> v;
    int size;
    int cnt = 0;
    int start, end;
    cin >> size;
    for(int i = 0; i<size;i++){
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }
    sort(v.begin(),v.end());
    int t = v.front().first;
    for(int i=1;i<size;i++){
        if(t <= v[i].second){
            t = v[i].first;
            cnt++;
        }
    }
    cnt++;
    cout << cnt;
}