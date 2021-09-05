#include<iostream>
#include<vector>

using namespace std;
int main(){
    int test;
    int n;
    cin >> test;
    vector<int> sumCase;
    sumCase.push_back(0);
    sumCase.push_back(1);
    sumCase.push_back(2);
    sumCase.push_back(4);
for(int i=0;i<test;i++) {
    cin >> n;
    int size = sumCase.size();
    for (int i = size; i <= n; i++) {
            sumCase.push_back(sumCase[i - 3] + sumCase[i - 2] + sumCase[i - 1]);
    }
    cout << sumCase[n]<<"\n";
}
}