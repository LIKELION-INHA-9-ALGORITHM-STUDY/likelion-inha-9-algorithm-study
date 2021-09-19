#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BSearch(vector<int> &v1, int left, int right, int x){

    int middle = (left+right)/2;
    if(left>right){
        cout << 0 << "\n";
        return;
    }
    if(v1[middle]==x){
        cout << 1 << "\n";
        return;
    }
    else if(v1[middle]< x){
        BSearch(v1,middle+1,right,x);
    }
    else if(v1[middle]>x){
        BSearch(v1,left,middle-1,x);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int size;
    int value;
    int count;
    vector<int> v1;
    cin >> size;
    for(int i=0;i<size;i++){
        cin >> value;
        v1.push_back(value);
    }

    sort(v1.begin(), v1.end());

    cin >> count;
    for(int i=0;i<count;i++){
        cin >> value;
        BSearch(v1,0,size-1,value);
    }
}