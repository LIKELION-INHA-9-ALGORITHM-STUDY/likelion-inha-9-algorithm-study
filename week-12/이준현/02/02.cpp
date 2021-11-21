#include <string>
#include <vector>

using namespace std;

void swapMax(vector<vector<int>> &v){ // 무조건 row에 두값중 가장 큰값이 들어오게 벡터
    int size = v.size();
    for(int i=0;i<size;i++){
        int min = 0;
        if(v[i][0]<v[i][1]){
            min = v[i][0];
            v[i][0] = v[i][1];
            v[i][1] = min;
        }
    }
}
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int size = sizes.size();
    swapMax(sizes);
    int row,col;
    row = sizes[0][0];
    col = sizes[0][1];
    for(int i=0;i<size;i++){
        if(row<=sizes[i][0]){
            row = sizes[i][0];
        }
        if(col<=sizes[i][1]){
            col = sizes[i][1];
        }
    }
    answer = row*col;
    return answer;
}