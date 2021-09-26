#include <iostream>
#include <vector>
using namespace std;

int minCount=2147483647;
int maxHeight=0;

void count(int height, vector<int> &ground, int size){
    int cnt = 0;
    for(int i=0;i<size;i++){
        if(height-ground[i]>=0){
            cnt += (height-ground[i])*1;
        }
        else{
            cnt += -(height-ground[i])*2;
        }
    }
    if(minCount>cnt){
        minCount = cnt;
        maxHeight = height;
    }
    else if(minCount==cnt && maxHeight<height){
        maxHeight = height;
    }
}
int main(){
    int row;
    int column;
    int block;
    int value;
    int sum = 0;
    int Height;
    vector<int>ground;
    cin >> row >> column >> block;
    sum += block;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin >> value;
            ground.push_back(value);
            sum += value;
        }
    }

    int size = ground.size();
    Height = sum / size;

    for(int i=0;i<=Height;i++){
        count(i,ground,size);
    }
    cout << minCount <<" "<< maxHeight;
}