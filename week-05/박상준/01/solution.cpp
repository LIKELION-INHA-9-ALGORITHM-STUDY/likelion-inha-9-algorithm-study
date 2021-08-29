#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	// 모두가 수업을 들을 수 있다고 가정하고 시작.

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	// 여벌을 가져온 학생이 도난당한 경우 -1로 바꿔서 제외.
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] > lost[i]) break; // 정렬되었기 때문에 이후의 값 확인할 필요 x
			if (lost[i] == reserve[j]) {
				// 여벌을 가져온 학생이 도난당한 경우.
				lost[i] = -1;
				reserve[j] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		if (lost[i] == -1) continue; // 여벌을 가져온 학생이 도난당한 경우 스킵
		int flag = 0; // 여벌을 빌릴 수 있는지 체크용 변수
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] > lost[i] + 1) break; // 여벌을 빌릴 수 없는 경우 스탑
			else if (reserve[j] == lost[i] - 1 || reserve[j] == lost[i] + 1) { //여벌을 빌릴 수 있는 경우
				flag = 1; // 여벌 빌림
				reserve[j] = -1; // 한 번 빌려주면 더 못 빌려줌.
				break;
			}
		}
		if (flag == 0) answer--; // 못빌린 경우
	}
	return answer;
}