#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    int size;

    cin >> size;

    for(int i=1;i<=size;i++){
        dq.push_back(i);
    }
    while(dq.size()>1){
        dq.pop_front();
        int i1 = dq.front();
        dq.pop_front();
        dq.push_back(i1);
    }
    cout << dq.front();
}