#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int* Aptr = &A[0];
// int B[100000];

void binarySearch(int* &A, int b, int l, int r) {
	if (l > r) {
		cout << "0\n";
		return;
	}
	else {
		int mid = (l + r) / 2;
		if (A[mid] == b) {
			cout << "1\n";
			return;
		}
		else if (A[mid] > b) r = mid - 1;
		else if (A[mid] < b) l = mid + 1;
	}
	binarySearch(Aptr, b, l, r);

	/*while(l<=r){
		if (A[mid] == b) {
			return 1;
			break;
		}
		else if (A[mid] > b) r = mid - 1;
		else if (A[mid] < b) l = mid + 1;
	}*/
}

int main() {
	int n, m;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);

	cin >> n;
	// int* A=new int[n+1];
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A+n); // 오름차순 정렬

	cin >> m;
	int* B = new int[m];
	for (int i = 0; i < m; i++) cin >> B[i];

	for (int i = 0; i < m; i++) {
		binarySearch(Aptr, B[i], 0, n - 1);
	}

	delete B;
}