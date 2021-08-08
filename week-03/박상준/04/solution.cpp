#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
	int* arr;
	int arrSize;
	int lastIdx = 0;
	int direction; // 최소 / 최대 힙 구분 변수. 1이면 최소, -1이면 최대 힙.

	Heap(int size, int direction) {
		this->arrSize = size;
		arr = new int[size];
		arr[0] = -1;
		this->direction = direction;
	}

	void swap(int parentIdx, int childIdx) {
		arr[0] = arr[parentIdx];
		arr[parentIdx] = arr[childIdx];
		arr[childIdx] = arr[0];
	}

	bool empty() { return lastIdx == 0; }

	int findRoot() {
		if (empty()) return 0;
		return arr[1];
	}

	void upHeap(int childIdx) {
		if (childIdx == 1) return; // 루트인 경우.

		else if (arr[childIdx / 2] * direction > arr[childIdx] * direction) {
			// 최소 / 최대에 따라 direction을 곱해서 부등호 방향 바꾸기
			swap(childIdx / 2, childIdx);
			upHeap(childIdx / 2);
			return;
		}
		else return;
	}

	void downHeap(int parentIdx) {
		int child;
		if (parentIdx * 2 > lastIdx) return; // 자식이 없는 경우.
		else {
			if (parentIdx * 2 == lastIdx) child = parentIdx * 2; // 자식이 한 명인 경우.

			else { // 자식이 두 명인 경우, 비교할 자식 선택.
				if (arr[parentIdx * 2] * direction <= arr[parentIdx * 2 + 1] * direction) child = parentIdx * 2;
				else child = parentIdx * 2 + 1;
			}

			if (arr[child] * direction < arr[parentIdx] * direction) {
				swap(parentIdx, child);
				downHeap(child);
				return;
			}
			else return;
		}
	}

	void insert(int num) {
		arr[++lastIdx] = num;
		upHeap(lastIdx);
	}

	void deleteRoot() {
		if (empty()) return;
		arr[1] = arr[lastIdx--];
		downHeap(1);
	}

	int mix(int k) {
		// 모든 읍식의 스코빌 지수가 k 이상이 될 때 까지 섞는 함수.
		int cnt = 0; // 섞어야 하는 횟수
		while (arr[1] < k) { // 루트에 저장된 최소 값이 k보다 작은 경우 계속 반복
			if (lastIdx == 1) return -1;
			// 루트만 남은 경우. 더 이상 이 힙의 값을 K 이상으로 만들 수 없다. -1 리턴.
			int num1 = arr[1]; // 가장 맵지 않은 음식의 스코빌 지수
			deleteRoot();
			int num2 = arr[1]; // 두 번째로 맵지 않은 음식의 스코빌 지수
			deleteRoot();
			insert(num1 + (num2 * 2)); // 섞어서 넣기.
			cnt++;
		}
		return cnt;
	}
};

int solution(vector<int> scoville, int K) {
	int min = 1, size = scoville.size();
	Heap heap(size + 1, min); // 최소 힙으로 생성.
	for (int i = 0; i < size; i++) {
		heap.insert(scoville[i]);
	}
	return heap.mix(K); // 최소 횟수 찾기.
}