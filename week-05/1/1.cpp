#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> student(n, 1); //벡터크기가 n이고 모든 원소를 1로 초기화시키기

	//student vector에 학생 상태 대입하기 
	for (int i = 0; i < reserve.size(); i++) {
		student[reserve[i] - 1]++;
	}
	for (int i = 0; i < lost.size(); i++) {
		student[lost[i] - 1]--;
	}

	//체육복 두개인 사람이 빌려주기
	for (int i = 0; i < n; i++) {
		if (student[i] == 0 && student[i - 1] == 2) {
			student[i]++; student[i - 1]--;
		}
		if (student[i] == 0 && student[i + 1] == 2) {
			student[i]++; student[i + 1]--;
		}
	}
	//체육복갖고있는 학생 수 세기
	for (int i = 0; i < student.size(); i++) {
		if (student[i] > 0) answer++;
	}

	return answer;
}