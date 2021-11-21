#include<iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,psize, size;
    int cnt = 0;

    string p, answer;
    cin >> N >> size;
//    p = "I";
//    psize = 1+2*N;
//
//    for(int i=0;i<N;i++){
//        p+="OI";
//    }

    cin >> answer;

    for(int i=0;i<=size;i++){
//     if(answer.substr(i,psize) == p){
//         cnt++;
//         i++;
//     }
//     else {
//         i++;
//         while (answer[i] != 'I' && i <= size - psize) {
//             i++;
//         }
//         i--;
//     }
        if(answer[i] == 'O'){
            continue;
        }
        else{
            int count = 0;
            while(answer[i+1] == 'O' && answer[i+2] == 'I'){
                count++;
                i += 2;
                if (count == N) {
                    count--;
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}