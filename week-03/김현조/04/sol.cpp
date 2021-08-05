// 문제 4. 더 맵게 - Heap

// //// 우선순위 큐 Priority Queue
// : 임의의 순서로 입력된 우선순위된 원소들을 저장하고 우선순위에 따라 출력하는 ADT
// : 언제든지 저장된 원소들 중 가장 우선순위가 높은 원소가 삭제됨
// : FIFO인 Queue의 기본적인 기능에 우선순위가 높은 자료형을 먼저 삽입삭제하도록

// 지금까지 배운 stack, queue, deque, sequence, tree는 위치 기반임
// -> PQ는 '위치' 개념이 없고 대신 그들의 우선순위에 따라 원소들을 저장
// -> PQ는 원소들의 container로서 각 원소가 입력될 때 그와 연관된 key를 가짐
// --> key로 우선순위를 결정함!!!

// PQ를 구현하기 위한 방법 List(선형) 그리고 Heap(계층구조)
// -> Heap으로 구현하는게 가장 효율적임 O(logN)


// //// Heap
// : 원소와 key를 List가 아니라 Binary Tree 이진트리에 저장
// : Complete Binary Tree의 일종, PQ를 위하여 만들어진 자료구조
// : 여러 개의 값 중에서 max나 min값을 빠르게 찾아내도록!

// max heap - 부모 Node의 key값이 자식보다 크거나 같은 완전 BT
// min heap - 부모 Node의 key값이 자식보다 작거나 같은 완전 BT

// https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html

// : Heap은 key들을 내부 Node들에 저장하는 Binary Tree T이며 두 가지 특성 가짐
// key들이 저장되는 방법으로 정의되는 T의 관계적인 정의는 다음과 같다

// 1) Heap-Order Priority 힙-순서 특성
// : Heap T에서 루트를 제외한 모든 node v에 대하여,
// v에 저장된 key는 v의 부모에 저장된 key보다 크거나 같다
// -> T의 루트에서 한 외부 node로 연결되는 경로에서 key들은 감소하지 않는 순서가 됨
// + 최솟값을 갖는 key는 항상 T의 root에 저장된다 -> 'Heap의 꼭대기' 중요한 key임 ㅇㅇ
// cf. 자료구조 Heap은 c++ 메모리 Heap과 전혀 다름!

// 2) Complete Binary Tree 특성
// : 레벨 0,1,2....h-1들이 가질 수 있는 최대 수의 Node를 포함하고
// 레벨 h-1에서 모든 내부 Node는 내부 Node들의 왼쪽에 위치한다면,
// 높이 h인 Binary Tree T는 완전 Complete하다
// + 효율을 위하여 우리는 Heap T의 높이를 가능한 작게 만들어야 함!



// 매운 음식 좋아하는 Leo 모든 음식의 스코빌 지수를 K이상으로 만들고 싶다
// -> 이런 방식으로 새로운 음식을 만든다
// 섞은 음식의 스코빌 지수 = 가장 안 매운 지수 + (두번째로 안 매운 지수 * 2)
// 모든 음식의 지수가 K 이상이 될 때까지 반복 -> 최소 횟수 return


// PQ를 구현하는 heap - min heap & max heap이 있음 -> data 넣으면 자동 정렬
// min heap으로 설정 -> 가장 앞에는 스코빌 지수 제일 낮은 음식
// -> top으로 확인하여 K보다 적으면 2개 꺼낸 후 섞고 (계산)
// -> 다시 PQ에 넣는다

#include <string>
#include <vector>
#include <queue> // PQ

#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // PQ 선언 - greater : Max, less : Min
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    // 크기가 1 && top이 K보다 크면 bye
    while (pq.size() > 1 && pq.top() < K)
    {
        // 가장 작은 값
        int first = pq.top(); 
        pq.pop();
        // 두번째로 작은 값
        int second = pq.top();
        pq.pop();

        // 섞기
        int mix = first + second*2;
        // PQ에 넣기
        pq.push(mix);

        // 횟수 +1
        answer++;
    }

    // 만약 모든 작업 끝나도 PQ의 제일 맵지 않은 음식이 K보다 작으면 끝
    if (pq.top() < K)
        return -1;
        
    return answer;
}