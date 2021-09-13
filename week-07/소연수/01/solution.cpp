#include <iostream>
#include <cmath>
using namespace std;

int fun(int n, int p) { // 다음 인덱스에 들어갈 수를 반환하는 함수
	int res{ 0 };
	while (n!=0) {
		res += pow((n % 10), p);
		n /= 10;
	}
	return res;
}

int main() {
	int a, p;
	cin >> a >> p;

	int chk[250000] = { 0, }; // 수열에 넣는 수가 곧 인덱스인 배열.
	// 그 수를 담은 순서(count)를 배열 값으로 담는다.
	// ex) 첫번째 담은 수 57, chk[57] = 1,
	//     두번째 담은 수 74, chk[74] = 2, ...

	int count{ 0 };
	int next{ fun(a, p) };
	chk[a] = ++count;

	while (chk[next] == 0) { // 전에 나온 적이 있는 수일 때 멈춘다.
		count++;
		chk[next] = count;
		next = fun(next, p);
	}
	// chk[next]에는 반복이 시작되는 첫번째 수를 인덱스로 한 count값이 담긴다.
	cout << --chk[next]; // 반복되는 부분을 제외했을 때 남는 수의 개수
	return 0;
}