#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int average(map<int,int> &m, int size){
    float sum=0;
    for(auto i : m){
        sum += i.first*i.second;
    }
    return round(sum/size);
}
int median(map<int,int> &m, int size){

    size = (size+1)/2;
    auto iter = m.begin();
    for(auto i : m){
        size -=i.second;
        if(size<=0){
            return i.first;
        }
    }
}
int mode(map<int,int> &m){
    int idx;
    int max=0;
    auto iter = m.begin();
    auto iter2 = m.begin();
    vector<int> v;
    for(int i=0;i<m.size();i++){
        if(iter->second>max){
            iter2 = iter;
            max = iter->second;
        }
        iter++;
    }
    for(auto i : m){
        if(i.second==max){
            v.push_back(i.first);
        }
    }
    sort(v.begin(),v.end());
    if(v.size()>=2){
        return v[1];
    }
    else{
        return iter2->first;
    }
}
int range(map<int,int> &m){
    int max;
    int min;
    auto i = m.end();
    i--;
    max = i->first;
    min = m.begin()->first;
    return max-min;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int, int> m;
    int time;
    int value;
    cin >> time;
    for(int i=0;i<time;i++){
        cin >> value;
        m[value]++;
    }
    cout << average(m, time) <<'\n'<<median(m, time)<<'\n'<<mode(m)<<'\n'<<range(m);
}