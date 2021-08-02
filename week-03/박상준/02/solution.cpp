#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 큰 수로 만들어서 정렬하기 위한 함수.
bool compare(string left, string right) {
	int len = min(left.length(), right.length());

	for (int i = 0; i < len; i++) { // 두 숫자 중 더 짧은 수의 길이만큼 비교.
		if (left[i] > right[i]) return true;
		else if (left[i] < right[i]) return false;
	} // 더 짧은 수의 길이만큼 비교했을 때, 더 큰 수가 결정되면 리턴

	// 위에서 len만큼 비교했을 때, 값이 같으면, 더 긴 수의 남은 길이만큼 비교.
	// 더 긴 수에서 len 이후의 수 + 그 뒤에 더 짧은 수가 오는 경우와 
	// vs 그냥 더 긴 수가 오는 경우 비교.
	// ex) 3333123  33331일 경우, 33331 vs 33331로 for문 통과하고 밑으로 내려옴
	// (33331) 2333331  vs  (33331) 3333123 비교해서 결정.
	if (left.length() > right.length()) {
		string sub = left.substr(len, left.size() - 1) + right;
		if (sub > left) return true;
		else return false;
	}

	else if (right.length() > left.length()) {
		string sub = right.substr(len, right.size() - 1) + left;
		if (sub > right) return false;
		else return true;
	}
	return false;
}

string solution(vector<int> numbers) {
	vector<string> toStringNumbers;

	int size = numbers.size();
	for (int i = 0; i < size; i++) toStringNumbers.push_back(to_string(numbers[i]));
	sort(toStringNumbers.begin(), toStringNumbers.end(), compare); // 가장 큰 수 찾아서 정렬.

	string answer = "";
	for (string str : toStringNumbers) {
		if (answer == "" && str == "0") continue; // 맨 앞에 0이 올 수 없음.
		answer += str;
	}
	if (answer == "") answer = "0";
	// numbers에 0만 있는 경우, 위 for문에서 continue 했기에 answer가 빈다.
	return answer;
}