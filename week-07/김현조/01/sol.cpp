//// 210906 멋사 코테 스터디 7주차 - DFS/BFS
// 문제 1. 반복수열

// // 그래프 Graph?
// : 정점(Node)과 그 정점을 연결하는 간선(Edge)으로 이루어진 자료구조

// // 그래프를 탐색 Search?
// : 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문


// //// 깊이 우선 탐색 (DFS, Depth-First Search)
// : 루트 노트(or 임의의 노트)에서 시작해서 다른 분기 branch로 넘어가기 전에
// 해당 branch를 완벽하게 탐색하는 방법
// - 넓게 wide 탐색하기 전에 깊게 Deep 탐색
// - 사용하는 경우 : 모든 Node를 방문하고자 하는 경우
// - BFS(너비 우선 탐색)보다 좀 간단, 단순 검색 속도 자체는 좀 느림

// // 특징
// - 자기 자신을 호출하는 순환 알고리즘 형태
// - 전위순회 Pre-Order Traversals를 포함한 트리 순회 모두 DFS의 한 종류
// - "어떤 노드를 방문했었는지 여부를 반드시 검사" - 안하면 무한루프 빠질 위험

// *backtracking - 다시 돌아와서 탐색하지 않은 정점있는지 check

// // 구현
// a) 순환 호출 
// b) 명시적 스택 - 방문한 정점들을 stack에 저장했다가 꺼내서 작업


// //// 너비 우선 탐색 (BFS, Breadth-First Search)
// : 루트 노트(or 임의의 노트)에서 시작해서 인접한 노드를 먼저 탐색하는 방법
// - 깊게 Deep 탐색하기 전에 넓게 wide 탐색
// - 사용하는 경우 : 두 노드 사이의 최단 경로 or 임의의 경로를 찾고 싶을 때
// - DFS보다 좀 더 복잡

// // 특징
// - 직관적이지 않음. 시작 노드에서부터 거리에 따라 단계별로 탐색하는 느낌
// - 재귀적으로 동작 x
// - "어떤 노드를 방문했었는지 여부를 반드시 검사" - 안하면 무한루프 빠질 위험
// - 방문한 노드들을 차례로 저장한 후 꺼낼 수 있는 Queue를 사용 (FIFO 원칙으로 탐색)

// // 구현
// - Queue로 구현



// 수열에 남게 되는 수들의 갯수


// 각 자리의 숫자를 P번 곱한 수들의 합 
// 수열 D -> 반복수열


// 방문 횟수를 저장하는 배열 visited
// 반복 수열에서 반복이 아닌 수만 추출하자
// 반복이면 배열 visit를 ++해주며 dfs를 return 시켜준다

#include <cmath> // pow 함수
#include <cstring> // memset 함수
#include <iostream>
using namespace std;

int p;
int visited[300000]; // 99999일 때 9^5 * 5 = 295245 ㅇㅇ

// 다음 방문할 번호를 구하는 함수 
int nextNumber(int num, int p)
{
    int next = 0;
    while(num != 0) {
        next += pow(num%10, p); // 거듭제곱 함수
        num /= 10;
    }

    return next;
}

int main()
{
    // visited 배열 초기화
    // memset 함수 : 메모리의 값을 원하는 크기만큼 세팅
    memset(visited, 0, sizeof(visited));

    int node, p;
    cin >> node >> p;
    
    // 첫번째 노드 방문
    int count = 1;
    visited[node] = count; 

    // 다음에 방문할 번호 계산
    int next = nextNumber(node, p);

    // 순환 발견할 때까지 탐색
    while(visited[next] == 0)
    {
        count += 1;
        visited[next] = count;
        next = nextNumber(next, p);
    }

    // 순환 발견 위치의 방문횟수 - 1
    cout << visited[next] - 1;
}