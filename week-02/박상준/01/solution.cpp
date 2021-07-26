#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int N = nums.size();

    sort(nums.begin(), nums.end()); // unique 쓰기 위해 정렬
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // unique로 벡터의 중복값 제거

    if (nums.size() > N / 2) return N / 2;
    // 중복이 제거된 벡터의 사이즈가 고를 수 있는 N//2보다 크면, N/2개의 번호가 모두 다르다.
    else return nums.size(); // N/2보다 작은 경우는 중복이 제거된 벡터의 사이즈 만큼 고를 수 있다.
}