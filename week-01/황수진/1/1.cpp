// codingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	// participant, completion 각 정렬하기
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	//for문 이용해 값 비교하기. 같지 않으면
	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i]) 
			return participant[i];
	}

	//completion 수만큼 for문이 다 돌았음에도 return 되지 않으면 participant의 제일 마지막 값을 return
	return participant[participant.size() - 1];
}