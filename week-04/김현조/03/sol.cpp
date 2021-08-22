//// 210822 멋사 코테 스터디 4주차 - 완전탐색
// 문제 3. 카펫

// 카펫 문양대로 return 가로 >= 세로

// 테투리 갈색 + 내부 노랑 -> 최소 높이 3


#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 전체 갯수 
    int total = brown + yellow;

    // 높이 최소 3
    for (int height=3;; height++)
    {
        // 총합/높이 -> 나머지 0이면
        if (!(total % height)) {
            int width = total/height;

            // 테두리는 갈색 -> 2줄씩 빼자
            if (((height-2)*(width-2)) == yellow)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}