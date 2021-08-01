//// 210801 멋사 코테 스터디 2주차 - Stack/Queue
// 문제 1. 폰켓몬

// 총 N마리 중 N/2마리 선택
// 같은 종류는 같은 번호
// 최대한 다양한 종류 선택하도록

// 포켓몬 종류 번호 담긴 1차원 배열 nums [3,3,3,2,1,4]
// -> 일단 정렬하며 같은 종류 애들 체크 가능
// key 종류 번호, value 해당 종류 마릿수로 map에 넣기
// 종류번호 중에서 N/2마큼 조합 경우의 수 = return 

// 종류 N/2 이상 -> max 값이 N/2
// 종류 N/2 미만 -> max 값이 해당 종류

#include <vector>
#include <map>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    // 선언
    map<int, int> mapForPet;

    // 포켓몬 종류 담긴 1차원 배열 정렬
    sort(nums.begin(), nums.end());

    // 포켓몬 수
    int N = nums.size(); 

    // (피카츄(1), 2마리) (라이츄(2), 3마리) 이런식으로 insert
    for (int i=0; i<N; i++)
    {
        if (mapForPet.find(nums[i]) == mapForPet.end())
            mapForPet.insert({nums[i], 1});
        else
            mapForPet.find(nums[i])->second++;
    }

    // 선택할 수 있는 포켓몬 종류 갯수 최대값 계산
    if (mapForPet.size() >= N/2)
        answer = N/2;
    else
        answer = mapForPet.size();


    return answer;
}