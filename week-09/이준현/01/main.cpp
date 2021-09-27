#include<iostream>
#include<vector>

using namespace std;
int main(){
    int arr[100001];
    vector<int> v;
    vector<char> icon;
    int count = 0;
    int testcase;
    int value;
    cin >> testcase;

    for(int i=0;i<testcase;i++){
        cin >> value;
        arr[i] = value;
    }
    for(int i=1;i<=testcase;i++){
        v.push_back(i);
        icon.push_back('+');

        while(!v.empty()&&v.back()==arr[count]){
            v.pop_back();
            icon.push_back('-');
            count++;
        }
    }
    if(v.empty()){
        int size = icon.size();
        for(int i=0;i<size;i++){
            cout << icon[i] << '\n';
        }
    }
    else{
        cout << "NO";
    }
}