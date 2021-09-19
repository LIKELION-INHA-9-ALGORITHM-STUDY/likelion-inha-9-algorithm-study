#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map <int, int> m;
    int sang, findCard, card;
    cin >> sang;
    for (int i = 0; i < sang; i++) {
        cin >> card;
        m[card]++;
    }
    cin >> findCard;
    for (int i = 0; i < findCard; i++) {
        cin >> card;
        cout << m[card] << " ";
    }
}




//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int findRight(vector<int>& v1, int middle, int x){
//    int count = 1;
//    int size = v1.size();
//    for(int i=middle;i<size;i++){
//        if(v1[i+1]!=x){
//            break;
//        }
//        count++;
//    }
//    for(int i=middle;i>0;i--){
//        if(v1[i-1]!=x){
//            break;
//        }
//        count++;
//    }
//    return count;
//}
//void BSearch(vector<int> &v1, int left, int right, int x){
//
//    int middle = (left+right)/2;
//    if(left>right){
//        cout << "0" << " ";
//        return;
//    }
//    if(v1[middle]==x){
//        cout << findRight(v1,middle,x) << " ";
//        return;
//    }
//    else if(v1[middle]< x){
//        BSearch(v1,middle+1,right,x);
//    }
//    else if(v1[middle]>x){
//        BSearch(v1,left,middle-1,x);
//    }
//}
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    int sangC;
//    int value;
//    vector<int> sangV;
//    int findC;
//
//    cin >> sangC;
//    for(int i=0;i<sangC;i++){
//        cin >> value;
//        sangV.push_back(value);
//    }
//    sort(sangV.begin(), sangV.end());
//    cin >> findC;
//    for(int i=0;i<findC;i++){
//        cin >> value;
//        BSearch(sangV, 0, sangC-1, value);
//    }
//}