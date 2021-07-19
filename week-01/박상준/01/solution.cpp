#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node() {
        name = "";
        next = NULL;
    }
    Node(string name) {
        this->name = name;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int sz;

    LinkedList() {
        head = new Node;
        tail = new Node;
        head = tail = NULL;
        sz = 0;
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
        sz++;
    }
};

class Hash {
public:
    LinkedList* participant;
    int sz;

    Hash(int N) {
        participant = new LinkedList[N];
        sz = N;
    }

    void insert(string name) {
        Node* newNode = new Node(name);
        participant[hashingName(name)].insert(newNode);
    }

    int find(string name) { // 동명이인이 있을 수 있기 때문에, 한 번 찾은 완주자는 연결리스트에서 삭제.
        Node* previous, * current;
        int flag = 0;

        previous = current = participant[hashingName(name)].head;
        while (current != NULL) {
            if (name == current->name) {
                flag = 1;
                break;
            }
            previous = current;
            current = current->next;
        }

        if (flag == 1) {
            if (current == participant[hashingName(name)].head) { // 찾은 완주자가 연결리스트의 헤드인 경우
                if (participant[hashingName(name)].sz == 1) {
                    participant[hashingName(name)].head = participant[hashingName(name)].tail = NULL;
                }
                else {
                    participant[hashingName(name)].head = current->next;
                }
            }

            else { // 찾은 완주자가 연결리스트의 헤드가 아닌 경우
                previous->next = current->next;
                if (current == participant[hashingName(name)].tail) participant[hashingName(name)].tail = previous;
            }
            return flag;
        }
        return flag;
    }

    int hashingName(string name) {
        int hash = 0;
        for (char c : name) {
            hash += int(c);
        }
        return hash % sz;
    }
};

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    Hash hash(participant.size());
    int result;
    for (int i = 0; i < completion.size(); i++) {
        hash.insert(completion[i]); // 완주자를 해시에 저장
    }

    for (int i = 0; i < participant.size(); i++) {
        // 참가자에 벡터를 순회하면서 해시에 저장된 완주자와 비교
        result = hash.find(participant[i]);
        if (result == 0) { //찾지 못한 경우(완주하지 못한 경우)
            answer += participant[i];
            break;
        }
    }
    return answer;
}