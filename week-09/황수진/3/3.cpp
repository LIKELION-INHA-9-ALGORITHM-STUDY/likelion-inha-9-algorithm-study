#include<iostream>
#include<string>
#include<vector>
using namespace std;

string order;
vector<int> operands;
string tmp;
int plus_cnt = 0;
bool minus_flag = false;

int main() {
	cin >> order;

	for (int i = 0; i < order.size(); i++) {
		if (order[i] != '-' && order[i] != '+') {
			tmp = tmp + order[i];
			continue;
		}
		else if (order[i] == '-') {
			minus_flag = true;
		}
		else
			if (minus_flag == false) {
				plus_cnt++;
			}
		operands.push_back(stoi(tmp));
		tmp = "";

	}
	operands.push_back(stoi(tmp));
	int answer = operands[0];
	for (int i = 1; i < operands.size(); i++) {
		if (plus_cnt > 0) {
			answer += operands[i];
		}
		else
			answer -= operands[i];
		plus_cnt--;
	}

	cout << answer;
}