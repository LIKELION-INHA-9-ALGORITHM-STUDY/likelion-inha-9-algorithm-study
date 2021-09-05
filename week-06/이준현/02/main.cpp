#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

    int jungsu;

    cin >> jungsu;
    vector<int>minValue;

    minValue.push_back(0);
    minValue.push_back(0);
    for(int i=2;i<=jungsu;i++){
        minValue.push_back(minValue[i-1]+1);
        if(i%2==0) {
            minValue[i] = min(minValue[i], minValue[i / 2] + 1);
        }
        if(i%3==0) {
            minValue[i] = min(minValue[i], minValue[i / 3] + 1);
        }
    }
    cout << minValue[jungsu];
}