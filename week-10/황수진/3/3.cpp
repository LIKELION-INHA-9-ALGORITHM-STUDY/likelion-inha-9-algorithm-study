#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>
string address, pwd;
int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, string> m;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> address >> pwd;
		m[address] = pwd;
	}

	for (int i = 0; i < M; i++) {
		cin >> address;
		cout << m[address] << "\n";
	}
}