#include <iostream>
using namespace std;

long long fibo(int n) {
    //if ((n == 1) || (n == 2)) return 1;
    //else return fibo(n - 1) + fibo(n - 2); 재귀는 시간 초과~

    long long arr[91] = { 0, 1, };

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    for (int i{ 2 }; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);
}