/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> finish_progresses;

	int count = 0;
	int day = 0;
	int index = 0;

	while (finish_progresses.size() < progresses.size()) {

		int min_day = 100 - progresses[index] - speeds[index] * day; //필요한 최소 날짜
		day = min_day > day ? min_day : day; //생략가능한 날짜 생략하기

		while (progresses[index] + day * speeds[index] >= 100) {
			count++;
			finish_progresses.push(progresses[index]);
			if (index + 1 >= progresses.size())
				break;
			index++;
		}
		if (count != 0)
			answer.push_back(count);
		day++;
		count = 0;
	}


	return answer;
}


*/


#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> day;
	int intday = 0;
	for (int i = 0; i < progresses.size(); i++) {
		day.push(
			((100 - progresses[i]) % speeds[i] == 0) ?
			(100 - progresses[i]) / speeds[i] :
			(100 - progresses[i]) / speeds[i] + 1);
	}

	int count = 1;
	int max = day.front();
	while (!day.empty()) {
		//int index0 = day.front();
		day.pop();
		int index1 = !day.empty() ? day.front() : 100;
		if (max >= index1) //더 작을때
		{
			count++;
		}
		else { //하나 일 때
			answer.push_back(count);
			count = 1;
			max = index1;
		}
	}
	return answer;
}

