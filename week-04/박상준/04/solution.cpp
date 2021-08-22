#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> TriangleNum = { 1,3,6,10,15,21 };
	int n, num;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int size = TriangleNum.size();
		if (TriangleNum[size - 1] < num) {
			// 삼각수 벡터에 저장된 마지막 값이 num보다 작을 경우
			while (TriangleNum[size - 1] + size + 1 < num) {
				// 다음 삼각수 값이 num보다 작으면 벡터에 추가.
				TriangleNum.push_back(TriangleNum[size - 1] + size + 1);
				size++;
			}
		}

		int flag = 0;
		for (int first = size - 1; first >= 0 && flag != -1; first--) {
			if (TriangleNum[first] * 3 < num) break; // 가장 큰 값만 3개 더한게 num보다 작으면 더 볼 필요 없음.
			
			for (int second = first; second >= 0; second--) {
				if (flag == 1) break; // 답을 찾은 경우.

				if (second==first-1&&TriangleNum[first] + TriangleNum[second] * 2 < num) {
					// second가 first 미만인 수 중 가장 큰 수일때, first + second + second가 num보다 작으면 그 second보다 작은 second를 더 확인할 필요 없음.
					flag = -1;
					break;
				}

				for (int third = second; third >= 0; third--) {
					if (TriangleNum[first] + TriangleNum[second] + TriangleNum[third] < num) break;
					// 세 수를 더한 값이 num보다 작아지면 그 보다 작은 third는 더 확인할 필요 없음.
					
					if (TriangleNum[first] + TriangleNum[second] + TriangleNum[third] == num) {
						// 답을 찾은 경우.
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break; // 답을 찾은 경우.
		}
		if (flag == 1) cout << "1\n";
		else cout << "0\n";
	}
}