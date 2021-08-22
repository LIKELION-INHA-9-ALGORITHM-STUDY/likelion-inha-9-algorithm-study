#include <string>
#include <vector>

using namespace std;
int sum; int tmp;
vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	sum = (brown + 4) / 2;
	for (int i = 3; i <= sum; i++) {
		tmp = sum - i;
		if ((tmp - 2)*(i - 2) == yellow) {
			answer.push_back(tmp);
			answer.push_back(i);
			break;
		}
	}
	return answer;
}