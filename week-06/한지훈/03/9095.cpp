#include <iostream>
using namespace std;

class Adding {

private:
	
	int arr[15] = { 0,1,2,4, };

public:
	
	Adding() {
		
		for (int i = 4; i <= 11; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
	
	}
	
	int getNum(int num) {
		return arr[num];
	}
};

int main() {

	int T;
	int n;
	Adding adding;

	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		
		cin >> n;
		cout << adding.getNum(n) << endl;

	}

}