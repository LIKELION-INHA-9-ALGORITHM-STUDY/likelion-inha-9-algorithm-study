#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 4번과 같은 힙 구조 입니다.
class Heap {
public:
	int* arr;
	int arrSize;
	int lastIdx = 0;
	int direction;

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
		if (childIdx == 1) return;

		else if (arr[childIdx / 2] * direction > arr[childIdx] * direction) {
			swap(childIdx / 2, childIdx);
			upHeap(childIdx / 2);
			return;
		}
		else return;
	}

	void downHeap(int parentIdx) {
		int child;
		if (parentIdx * 2 > lastIdx) return;
		else {
			if (parentIdx * 2 == lastIdx) child = parentIdx * 2;

			else {
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
};

vector<int> solution(vector<string> operations) {
	int min = 1, max = -1, push = 0, pop = 0, size = operations.size(); // push 횟수, pop 횟수 기록
	Heap maxHeap(size + 1, max), minHeap(size + 1, min); // 최소 힙 하나, 최대 힙 하나.
	for (int i = 0; i < size; i++) {
		if (operations[i][0] == 'I') {
			int num = stoi(operations[i].substr(2));
			maxHeap.insert(num);
			minHeap.insert(num);
			push++;
		}

		else if (push > pop) { // 삭제 할 수 있는 경우.
			if (operations[i][2] == '1') maxHeap.deleteRoot(); // 최대 값 삭제
			else minHeap.deleteRoot(); // 최소 값 삭제
			pop++;
		}

		if (i != 0 && push == pop) {
			// 두 횟수가 같아지는 경우, 각각의 힙에서만 삭제했기 때문에, 두 힙을 비워야 한다
			//(새롭게 다시 시작).
			while (!maxHeap.empty()) maxHeap.deleteRoot();
			while (!minHeap.empty()) minHeap.deleteRoot();
		}
	}
	vector<int> answer;
	if (push == pop) answer = { 0, 0 }; // 연산 이후 큐가 빈 경우.
	else {
		answer.push_back(maxHeap.findRoot());
		answer.push_back(minHeap.findRoot());
	}
	return answer;
}