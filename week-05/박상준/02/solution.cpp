#include <iostream>
#include <string>
using namespace std;

int solution(string name) {
	int answer = 0, move = name.length() - 1, len = name.length();
	// move는 최소 이동 거리.(한 방향으로 직진하는 경우로 초기화)
	for (int i = 0; i < name.length(); i++) {
		int aIndex = i; // 연속된 A값의 가장 끝 인덱스. 'A' / AA'A' / AAAA'A'
		if (name[i + 1] == 'A') aIndex++; // 현재 인덱스의 다음 값이 A인 경우 다음 인덱스로 위치시킴
		while (aIndex < name.length() && name[aIndex] == 'A') {
			aIndex++; // 가장 끝 인덱스 찾기
		}

		if (aIndex > i) { // A가 존재하는 경우.
			move = min(move, 2 * i + len - aIndex);
			// 현재 최소 이동거리 move.
			// 현재 위치(i)에서 뒤로 돌아갈 경우의 거리 = 온 만큼 i + 다시 처음으로 i + 뒤돌아서 마지막 A 전까지 len-aIndex.
			// A를 마주할때마다 최소 거리 업데이트.
		}

		//점수에 대한 업데이트 -> 가운데 위치한 N을 기준으로 나눔.
		if (int(name[i]) <= 78) {
			answer += int(name[i] - 65);
		}
		else {
			answer += int(91 - name[i]);
		}
	}
	answer += move; //이동 횟수 더해줌
	return answer;
}