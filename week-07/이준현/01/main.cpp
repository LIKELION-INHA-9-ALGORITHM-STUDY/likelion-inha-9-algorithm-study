#include<iostream>
#include<cmath>

using namespace std;

int result = 0;
int visit[1000000];

int round(int a, int b){
    int sum = 0;
    while (a>0){
        sum += (int)pow((a%10),b);
        a /= 10;
    }
    return sum;
}

void dfs(int a, int b){
    visit[a]++;
    if(visit[a]>2){
        return ;
    }
    dfs(round(a,b),b);
}

int main(){
    int a, b;
    cin >> a >> b;
    dfs(a,b);
    for(int i=0;i<1000000;i++){
        if(visit[i]==1){
            result++;
        }
    }
    cout << result;
}