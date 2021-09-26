#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int length = s.size();

	int result = 0;
	string temp;
	bool minus = 0;

	for (int i = 0; i <= length; i++) {
		if (s[i] == '+' || s[i] == '-'||s[i]=='\0') { // 연산자일 경우
			if (minus) {
				result -= stoi(temp); // -을 만나면 지금까지의 temp를 결과에서 뺌
			}
			else {
				result += stoi(temp); // +을 만나면 지금까지의 temp를 결과에 더함
			}
			temp = ""; // temp 초기화
			if (s[i] == '-') minus = true;
			continue;
		}
		//if (s[i] == '+' || s[i] == '-') { // 연산자일 경우
		//	if (s[i] == '+') {
		//		result += stoi(temp);
		//	}
		//	else if (s[i] == '-') {
		//		result -= stoi(temp);
		//	}
		//	temp = "";
		//}
		else { // 피연산자일 경우
			temp += s[i]; // 숫자이면 그냥 temp에 더함
		}
	}
	cout << result;
}