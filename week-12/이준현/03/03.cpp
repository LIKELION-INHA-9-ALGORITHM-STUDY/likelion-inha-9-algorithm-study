#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>

using namespace std;

int main() {
    int size;
    int value;
    long long answer = 0;
    vector<int> v1;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> value;
        v1.push_back(value);
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < size; i++) {
        answer += abs(v1[i]-(i+1));
    }
    cout << answer;
}