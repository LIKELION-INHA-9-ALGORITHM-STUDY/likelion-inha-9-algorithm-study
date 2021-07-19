#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	string name;
	string type;
	Node* next;

	Node() {
		next = NULL;
	}
	Node(string name, string type) {
		this->name = name;
		this->type = type;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = new Node;
		tail = new Node;
		head = tail = NULL;
	}

	bool empty() {
		return head == NULL && tail == NULL;
	}

	void insert(Node* newNode) {
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
};

class Hash {
public:
	LinkedList* arr;
	int sz;

	Hash(int N) {
		arr = new LinkedList[N];
		sz = N;
	}

	int hashingType(string type) { // 종류 기준 해싱
		int hash = 0;
		for (char c : type) {
			hash += int(c);
		}
		return hash % sz;
	}

	void insert(string name, string type) {
		Node* newNode = new Node(name, type);
		arr[hashingType(type)].insert(newNode);
	}

	int find(string type) {
		int cnt = 0, hashIndex = hashingType(type);
		Node* temp = arr[hashIndex].head;
		while (temp != NULL) {
			if (type == temp->type) cnt++;
			temp = temp->next;
		}
		return cnt;
	}
};

int solution(vector<vector<string>> clothes) {
	vector<string> types; // 종류들 저장할 벡터
	Hash hash(clothes.size());

	for (int i = 0; i < clothes.size(); i++) {
		hash.insert(clothes[i][0], clothes[i][1]);
		types.push_back(clothes[i][1]);
	}
	sort(types.begin(), types.end()); // unique 사용하기 위해 정렬
	types.erase(unique(types.begin(), types.end()), types.end()); // unique로 종류 벡터에서 중복 제거

	int answer = 1;
	for (int i = 0; i < types.size(); i++) {
		answer *= hash.find(types[i]) + 1;  // 종류별로 하나를 택하거나 or 아무것도 안택하거나
	}
	return answer - 1; // 모든 종류에 대해서 안 고르는 경우(아무것도 안입는 경우 제외 -1)
}