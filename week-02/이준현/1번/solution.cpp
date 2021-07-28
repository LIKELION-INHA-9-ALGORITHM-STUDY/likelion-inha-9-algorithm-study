#include <vector>
#include <set> // 중복된 포켓몬들은 필요가 없다고 생각해서 set을 사용하였습니다.
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> poketmon;
    int pick = nums.size()/2;
    int size = nums.size();
    for(int i=0;i<size;i++){ // set에 insert를 해주면서 중복되는 개체들을 없에주었습니다.
        poketmon.insert(nums[i]);
    }
    if(poketmon.size()<=pick){  // set의 크기가 고르는 갯수보다 작다면 set의 크기가 정답이 됩니다.
        answer = poketmon.size();
    }
    else{ // 중복되지 않은 개체수가 고르는 수보다 많다면 최대는 고르는 갯수가 되게 됩니다.
        answer = pick;
    }
    return answer;
}