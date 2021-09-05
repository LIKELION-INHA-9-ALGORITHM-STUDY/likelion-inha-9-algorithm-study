#include <iostream>
using namespace std;

class MakeOne {

private:

	int* arr;

	int min(int a, int b) {
	
		if (a > b) {
			return b;
		}
		else if (b > a) {
			return a;
		}
		return a;

	}


public:

	MakeOne() {
		arr = new int[1000001];
		arr[1] = 0;
	}

	~MakeOne() {
		delete[] arr;
	}

	int min(int num) {

		for (int i = 2; i <= num; i++)
		{
			
			arr[i] = arr[i - 1] + 1;
			if (i % 3 == 0) {
				arr[i] = min(arr[i], arr[i / 3] + 1);
			}
			if (i % 2 == 0) {
				arr[i] = min(arr[i], arr[i / 2] + 1);
			}

		}

		return arr[num];

	}
};

int main() {

	int num;
	cin >> num;
	MakeOne makeOne;
	cout << makeOne.min(num);

}