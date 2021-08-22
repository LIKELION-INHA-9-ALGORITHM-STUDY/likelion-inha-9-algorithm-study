//// 210822 멋사 코테 스터디 4주차 - 완전탐색
// 문제 2. 소수 찾기

// 한자리 숫자 -> 문자열 합쳐서 소수 만들기

// 2, 3, 5 .... 소수로 하나하나 나눠보기 (배수 check)
// 소수 찾는 bool 함수 check
// 벡터 v에 문자열의 각 값을 숫자로 만들어서 저장
// -> for문을 돌면서 next_permutation으로 벡터 ans에 각 값 저장
// 중복 값 삭제 -> 그 후에 소수이면 카운팅


#include <string>
#include <vector>

#include <algorithm>
using namespace std;

bool check(int n) {
    if (n<2)
        return false;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int sum = 0;
    vector<int> v;

    for (int i=0; i<=numbers.size(); i++) {   
        v.push_back(numbers[i]-'0');
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    do {
        for (int i=0; i<=v.size(); i++) {
            int tmp=0;
            for (int j=0; j<i; j++) {
                tmp = (tmp * 10) + v[j];
                ans.push_back(tmp);
            }
        }
    } 
    // next_permutation 함수 -> 중복 제외하고 순열 생성 '조합'
    while (next_permutation(v.begin(), v.end()));

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end(), ans.end()));

    for(int i=0; i<ans.size(); i++) {
        if (check(ans[i]))
            answer += 1;
    }

    return answer;
}