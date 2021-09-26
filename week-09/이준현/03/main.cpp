#include<iostream>
#include<string>

using namespace std;


int main(){
    string mathExp= "";
    string temp = "";
    bool isMinus = false;
    int minResult = 0;
    cin >> mathExp;
    for(int i=0;i<=mathExp.size();i++){
        if(mathExp[i]<48){
            if(isMinus){
                minResult -= stoi(temp);
            }
            else{
                minResult += stoi(temp);
            }
            temp = "";
            if(mathExp[i] == '-'){
                isMinus = true;
            }
        }
        else{
            temp += mathExp[i];
        }
    }
    cout << minResult;
}