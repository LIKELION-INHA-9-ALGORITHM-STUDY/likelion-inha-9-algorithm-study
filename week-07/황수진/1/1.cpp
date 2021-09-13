
#include<iostream>
using namespace std;
#include<cmath>

int check[300000];
int cnt = 1;
int A, P;

int next_num(int bnum) {
	int nnum = 0;
	while (bnum != 0) {
		nnum += pow(bnum % 10, P);
		bnum /= 10;
	}
	return nnum;
}
int main() {
	cin >> A >> P;
	check[A] ++;

	int next = next_num(A);
	while (check[next] == 0) {
		cnt++;
		check[next] = cnt;
		next = next_num(next);
	}
	cout << check[next] - 1;
}