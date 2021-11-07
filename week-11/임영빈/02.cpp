#include <string>

#define BASE 3

using namespace std;
// 10진수인 n을 3진수로 변경하고 "012"대신에 "412"로 변경했습니다.
string solution(int n) {
	if (n == 0)
		return "";
	return (solution((n - 1) / BASE) + "412"[n % BASE]);
}