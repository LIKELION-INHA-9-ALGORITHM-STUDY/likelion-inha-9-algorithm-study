#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;
	int answer = 0, size = 0; //size는 "현재" 올라가있는 무게

	for (int i = 0; i < bridge_length; i++) q.push(0); //처음 시작 전 q를 다리 길이만큼 초기화. 
	//ex) 0 0 0 0 0 이런식으로 다리 길이 만큼 숫자의 개수를 유지하면서 진행
	for (int num : truck_weights) {
		size -= q.front();
		q.pop(); // 새로운 트럭을 올리기 위해 앞에서 하나 뺌 ex) 0 0 0 0

		while ((size + num) > weight) { //다리에 무게가 꽉차서 새로운 트럭이 못올라가는 기간
			size -= q.front();
			q.pop(); // 맨 앞 트럭 보내줌.
			q.push(0); // 새로운 트럭은 못올라오니 빈 칸을 0으로 채워줌.
			answer++;
		}
		// while문 탈출 -> 새로운 트럭이 다리에 올라올 수 있다.
		q.push(num);
		size += num; // 새로운 트럭이 다리에 올라옴
		answer++;
	}
	// 벡터 내의 마지막 트럭이 "다리에 올라오는 순간" for문 종료.
	// 다리에 몇 대의 트럭이 남아있는지에 상관없이 방금 다리에 올라온 마지막 트럭을 통과시키면 된다.
	answer += bridge_length; // 다리 길이만큼 + 해주면 마지막 트럭 통과.
	return answer;
}