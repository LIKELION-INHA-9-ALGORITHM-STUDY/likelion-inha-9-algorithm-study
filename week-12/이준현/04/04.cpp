#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>

using namespace std;
bool comp(int a, int b) {
    return a > b;
}
int main() {
    int size;
    int value;
    int k;

    long long answer = 0;
    vector<int> v1;
    cin >> size >> k;

    for(int i=0;i<size;i++){
        cin >> value;
        v1.push_back(value);
    }
    sort(v1.begin(),v1.end(), comp);
    for(int i=0;i<size;i++){
        int cut = 0;
        cut = int(k/v1[i]);
        if(cut == 0){
            continue;
        }
        else{
            k -= cut*v1[i];
            answer+=cut;
        }
        if(k==0){
            break;
        }
    }
    cout << answer;
}