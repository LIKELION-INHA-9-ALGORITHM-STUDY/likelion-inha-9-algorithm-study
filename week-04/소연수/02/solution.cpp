#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
1. 종이 조각으로 만들 수 있는 모든 수 구하기
2. 중복되는 수 제거하기 (ex/ 11, 011)
3. 소수 찾기
*/

bool isPrime(int n)
{
    // 소수 여부 판별 함수
    // 주입식 교육으로 외워뒀습니다,,
    if (n < 2)
        return false;
    for (int i{2}; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    // 1. 종이 조각으로 만들 수 있는 모든 수 구하기
    vector<char> nums;

    for (int i{0}; i < numbers.length(); i++)
    {
        nums.push_back(numbers[i]);
    } // nums 벡터에 숫자들(numbers의 각 자릿수) 넣기

    sort(nums.begin(), nums.end()); // next_permutation 사용하기 위해 오름차순으로 정렬
    vector<int> v;                  // 종이 조각으로 만들 수 있는 모든 수를 넣을 벡터
    do
    {
        string tmp = "";
        for (int i{0}; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            v.push_back(stoi(tmp));
        }
    } while (next_permutation(nums.begin(), nums.end()));
    // nums 벡터의 원소들로 순열 생성 -> 정수형으로 바꿔 v 벡터에 넣기

    // 2. 중복되는 수 제거하기 (ex/ 11, 011)
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // 3. 소수 찾기
    int answer = 0;
    for (int i{0}; i < v.size(); i++)
    {
        if (isPrime(v[i]))
            answer++;
    }

    return answer;
}