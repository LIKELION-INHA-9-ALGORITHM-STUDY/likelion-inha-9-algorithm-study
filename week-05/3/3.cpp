#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {

	sort(people.begin(), people.end());
	int index = 0;  int answer = 0;

	//people vector가 empty가 되지 않을 때까지
	while (index < people.size()) {
		int last = people.back(); people.pop_back();

		//제일 가벼운 사람 + 제일 무거운 사람 
		if (people[index] + last <= limit)
			index++;
		answer++;
	}
	return answer;
}