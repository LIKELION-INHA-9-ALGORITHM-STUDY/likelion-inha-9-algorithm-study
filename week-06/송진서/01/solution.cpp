#include <iostream>
using namespace std;

int fibo(int);

int main() {
    int n;
    cout << "수를 입력하세요: ";
    cin >> n;
    cout<<"결과: "<<fibo(n);
}

int fibo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1||n==2) {
        return 1;
    }
    else {
        return fibo(n - 1) + fibo(n - 2);
    }
}