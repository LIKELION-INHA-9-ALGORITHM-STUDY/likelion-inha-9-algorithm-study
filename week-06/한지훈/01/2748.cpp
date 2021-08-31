#include <iostream>
using namespace std;

class Fibonacci {

private:
	long long arr[100] = { 0, 1, };

public:
	long long getNum(int num) {
		if (num == 0 || num == 1) {
			return arr[num];
		}
		else if (arr[num] == NULL) {
			arr[num] = getNum(num - 1) + getNum(num - 2);
		}

		return arr[num];
	}

};


int main() {

	int num;
	Fibonacci fibo;
	cin >> num;
	cout << fibo.getNum(num);

}