#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int col, row;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            // 각 줄의 같은 수의 노란색 카펫이 들어가는 경우
            col = i;
            row = yellow / i;
            if (2 * col + 2 * row + 4 == brown) break;
            // 갈색 면의 수 = 노란 면의 (가로 * 2 + 세로 * 2 + 4)
        }
    }
    vector<int> answer = { row + 2, col + 2 };
    // 카펫의 가로 세로 길이는 노란면을 감싸고 있는 갈색면까지 포함 따라서 노란면의 가로 세로에 + 2 씩 해준다.
    return answer;
}