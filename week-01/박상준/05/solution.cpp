#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	string genre;
	int play;
	int plays; // 한 장르의 total play
	int number; // 고유번호
	Node* next;

	Node() {
		next = NULL;
	}

	Node(string genre, int play, int number) {
		this->genre = genre;
		this->play = play;
		this->plays = play;
		this->number = number;
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

			Node* temp = head;
			while (temp->genre != newNode->genre) {
				temp = temp->next; // 해싱 충돌이 발생했을 때, genre가 같은 첫 노드 찾기
			}
			if (temp->number != newNode->number) temp->plays += newNode->play;
			// temp가 head에서부터 탐색하기 때문에, head의 genre와 newNode의 genre가 다른 경우 항상 첫번째
			// 노드에서 while문이 멈춤. 따라서 이 때의 temp와 새로 들어온 newNode가 다를 때만 total 값 +
		}
	}
};

bool func2(Node* a, Node* b) {  // 같은 장르 내에서의 값 정렬
	if (a->play == b->play) return a->number < b->number;  // 3번 조건. 재생 횟수가 같으면 고유번호 순
	return a->play > b->play;
}

class Hash {
public:
	LinkedList* arr;
	int sz;

	Hash(int N) {
		arr = new LinkedList[N];
		sz = N;
	}

	int hashingGenre(string genre) { // genre 기준 해싱
		int hash = 0;
		for (char c : genre) {
			hash += int(c);
		}
		return hash % sz;
	}

	void insert(string genre, int play, int number) {
		Node* newNode = new Node(genre, play, number);
		arr[hashingGenre(genre)].insert(newNode);
	}

	Node* getHead(string genre) { // genre에 해당하는 첫 노드 찾기.
		int hashIndex = hashingGenre(genre);
		Node* temp = arr[hashIndex].head;
		while (temp->genre != genre) temp = temp->next; // 해싱 충돌이 발생하는 경우에 대한 처리.
		return temp;
	}

	vector<Node*> getAll(Node* head) { // 파라미터에 해당하는 노드의 genre와 같은 genre의 모든 노드 리턴
		vector<Node*> vec;
		Node* temp = getHead(head->genre);
		while (temp != NULL) {
			if (head->genre == temp->genre) vec.push_back(temp);
			temp = temp->next;
		}
		sort(vec.begin(), vec.end(), func2); // 재생 횟수 및 고유 번호 기준으로 정렬
		return vec;
	}
};

bool func(Node* a, Node* b) { // 장르별 재생 횟수 기준 정렬
	return a->plays > b->plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	Hash hash(genres.size());
	for (int i = 0; i < genres.size(); i++) {
		hash.insert(genres[i], plays[i], i);
	}

	sort(genres.begin(), genres.end());
	genres.erase(unique(genres.begin(), genres.end()), genres.end()); // 장르 중복 제거

	vector<Node*> total; // 장르 별 최대 값을 저장한 각 장르의 헤드 노드를 저장할 벡터
	for (int i = 0; i < genres.size(); i++) {
		total.push_back(hash.getHead(genres[i]));
	}
	sort(total.begin(), total.end(), func); // 장르 별 재생 횟수 기준 장르 정렬

	vector<int> answer;
	for (int i = 0; i < total.size(); i++) {
		vector<Node*> temp = hash.getAll(total[i]);
		int cnt = 0;
		for (int i = 0; i < temp.size() && cnt < 2; i++) {
			answer.push_back(temp[i]->number);
			cnt++; // cnt가 최대 2개일때까지만 정답 벡터에 푸시
		}
	}
	return answer;
}