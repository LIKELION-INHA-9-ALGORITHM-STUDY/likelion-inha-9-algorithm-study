#include <iostream>
using namespace std;
#include<stack>
#include<vector>
int n, a[100001], idx;
stack<int>stk;
vector<char>ret;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		stk.push(i);
		ret.push_back('+');
		while (stk.size() && stk.top() == a[idx]) {
			idx++; 
			stk.pop(); 
			ret.push_back('-');
		}
	}
	if (stk.size()) cout << "NO\n";
	else for (char a : ret)cout << a << "\n";
}