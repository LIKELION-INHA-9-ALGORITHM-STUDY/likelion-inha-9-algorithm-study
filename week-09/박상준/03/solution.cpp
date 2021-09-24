#include <iostream>
#include <string>
using namespace std;

int main() {
	// 마이너스가 한 번 나오면 그 뒤의 모든 숫자를 빼준다.
	string input, num;
	long long sum = 0;
	cin >> input;

	int minus = 0;
	if (input[0] == '-') minus = 1;
	for (int i = 0; i < input.length(); i++) {
		if (int(input[i]) >= 48 && int(input[i] <= 57)) num += input[i];
		// 숫자인 경우
		else {
			// + / -
			if (i == 0) continue;

			if (minus == 1) sum -= stoi(num);
			else sum += stoi(num);
			num = "";
			if (input[i] == '-') minus = 1;
		}
	}
	if (minus == 1) sum -= stoi(num);
	else sum += stoi(num);

	cout << sum;
}