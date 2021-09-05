#include<iostream>
#include<vector>

using namespace std;

vector<long long> v;

long long solution(int n){
    if(n==0){
        return 0;
    }
    if(n<=1){
        return 1;
    }
    if(v[n]==0) {
        v[n]= solution(n - 1) + solution(n - 2);
    }
    return v[n];
}

int main(){
    int n;
    v.push_back(0);
    cin >> n;
    cout << solution(n);
}