// 문제 2. 조이스틱

// 조이스틱으로 알파벳 이름 만들기 -> 횟수 구하기
// A부터 시작, A 이전 Z있음, 커서 이동

// A부터 올라갈지, Z 쪽으로 내려갈지 수 비교해서 알파벳 바꿈


#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();

    for(int i=0; i<len; ++i)
    {
        // A가 아닌 문자면 상하 이동
        if(name[i] != 'A') {
        answer += min(name[i]-'A', 'Z'+1-name[i]);
        }
    }

    // 좌우 이동 횟수 비교
    int left_min = len-1;
    for(int i=0; i<len; ++i) {
        // A가 아니면 좌우 이동
        if(name[i] != 'A') {
            // 다음 A가 아닌 index 구하기
            int next_index = i+1;
            while(next_index<len && name[next_index]=='A')
                ++next_index;

            // i 위치에서 총 left 이동 횟수
            int left = i*2+len-next_index;
            
            // 최소 이동 횟수
            left = min(left_min, left);
        }
    }

    return answer += left_min;
}