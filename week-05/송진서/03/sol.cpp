#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>()); //몸무게가 무거운 사람부터 내림차순으로 정렬
    int l = 0; int r = people.size() - 1; // 비교할 순서 설정, 가장 작은 사람 -> 가장 무거운 사람까지 비교
    
    while(l < r + 1) { // 둘이 만나기 전까지 계속 비교
        if (people[l] + people[r] <= limit) // 비교하는 두 명의 몸무게의 합이 무게제한 이내이면
            r--; // 무거운 쪽에서 해당 케이스 제외, 인덱스 -1
        l++; // 가벼운 쪽에서 해당 케이스 제외, 인덱스 +1
        answer++; //보트의 개수 +1
    }
    return answer;
}