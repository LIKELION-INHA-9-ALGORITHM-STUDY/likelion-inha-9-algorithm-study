#include <vector>
using namespace std;

int solution(vector<int> nums){
    int mons[200001] = {0, };
    // 폰켓몬의 종류 번호가 곧 mons 배열의 인덱스로, 각 셀에는 각 종류의 폰켓몬 수가 담기게 된다.
    // 0으로 모든 셀 초기화
    int num = 0;
    for (int i{0}; i < nums.size(); i++){ // 주어진 nums의 크기만큼 돌면서
        if (mons[nums[i]] == 0){ // 전에 없던 종류일 때
            num++; // 종류++
        }
        mons[nums[i]]++;
    } // 최종적으로 num에는 폰켓몬 종류의 수가 담긴다.

    if (num > nums.size() / 2){
        return nums.size() / 2;
    }
    return num;
}