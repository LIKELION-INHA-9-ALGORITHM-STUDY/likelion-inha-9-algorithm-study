// 문제 4. 구명보트

// 최대 2명 구명보트, 무게제한 있음
// 최대한 적게 사용 모든 사람 구출
// 필요한 구명보트 갯수 최솟값
// 몸무게 배열 people, 무게 제한 매개변수 limit


// 먼저 몸무게 오름차순 정렬 -> 2명씩 가능한지 check
// 최솟값 고정으로 뒤 data 더해주며 limit와 비교

// limit 넘으면 맨 뒷사람 pop하여 people 크게 줄임
// limit 안 넘으면 최솟값을 가르키는 index+1
// -> index가 사람 수면 전체 인원 모두 보트 탄 거임!


#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer, index = 0;
    sort(people.begin(), people.end());

    while(people.size()>index) {
        int back = people.back();
        people.pop_back();

        if(people[index] + back <= limit) {
            answer++;
            index++;
        } else {
            answer++;
        }
    }
    
    return answer;
}