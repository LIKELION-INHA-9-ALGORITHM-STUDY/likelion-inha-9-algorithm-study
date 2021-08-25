#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, left = 0, right = people.size() - 1;

    sort(people.begin(), people.end());

    while (left < right) {  // 가장 작은 값(left)과 가장 큰 값(right)를 비교하면서 중간 값으로 좁혀감
        if (people[left] + people[right] <= limit) { // 가장 큰 + 가장 작은이 limit 이하일 때
            answer++;
            left++;
            right--;  // 둘 다 태워서 보냄
        }
        else { // 넘을 때
            answer++;
            right--;  // 가장 큰 놈만 보트 태워서 보냄
        }
    }
    if (left == right) answer += 1;  // 둘이 같으면, 같은 값에 해당하는 놈을 보트 안태워보낸거. 이놈도 보내
    return answer;
}