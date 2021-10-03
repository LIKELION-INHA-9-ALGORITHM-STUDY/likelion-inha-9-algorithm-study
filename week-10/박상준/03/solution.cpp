#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hashing(string address, int N) {
	// 주소 기준 해싱.
	int hashedIndex = 0;
	for (char c : address) {
		hashedIndex += int(c);
	}
	return hashedIndex % N;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<vector<string>>> saves;
	for (int i = 0; i < N; i++) {
		saves.push_back({});
	}

	string address, password;
	for (int i = 0; i < N; i++) {
		cin >> address >> password;
		saves[hashing(address, N)].push_back({ address,password });
		// 입력 받은 주소로 해싱하여 주소와 비밀번호 저장.
	}

	for (int i = 0; i < M; i++) {
		cin >> address;
		int hashedIndex = hashing(address, N);
		for (int j = 0; j < saves[hashedIndex].size(); j++) {
			if (address == saves[hashedIndex][j][0]) {
				// 입력 받은 주소로 해싱하여 비밀번호 불러오기.
				cout << saves[hashedIndex][j][1] << "\n";
				break;
			}
		}
	}
}