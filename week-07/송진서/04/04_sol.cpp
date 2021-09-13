#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int i){
    // numbers, target = 문제에 제시된 것과 같음 
    // sum = 탐색을 진행하며 현재까지 쌓인 합 
    // 0 ~ numbers.size() 중 몇 번째 층을 탐색하고 있는지
    if (i == numbers.size()){ // 모든 층 탐색 완료
        if (sum == target) answer++; // 현재까지 쌓인 합이 target number와 같을 경우에 카운트
        return;
    }
    // 다 탐색하지 않았다면 재귀 호출 반복
    dfs(numbers, target, sum + numbers[i], i+1); // 해당 층에서 다음 층을 + 하며 한 층 더 깊게 탐색
    dfs(numbers, target, sum - numbers[i], i+1); // 해당 층에서 다음 층을 - 하며 한 층 더 깊게 탐색
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0); // 우선 최상단 층부터 dfs 시행
    return answer;
}