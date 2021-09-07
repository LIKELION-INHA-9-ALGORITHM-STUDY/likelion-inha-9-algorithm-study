// 문제 2. 바이러스

// 한 컴퓨터가 virus 걸리면 
// 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터 다 걸림

// 1번이 바이러스 걸림
// 컴퓨터 수와 네트워크 연결 정보가 주어지면 (한 쌍씩)
// virus 걸리는 컴퓨터 수 출력

// // 전역변수 & DFS 
// : 방향이 없는 그래프에서 서로 연결하기 위해 2차원 map 선언
// : 방문한 위치 정보를 저장하는 1차원 배열 visit 선언
// -> 함수에서 반복적으로 사용해야함 -> 인자보다 전역변수로 넘기자

// - n : 컴퓨터 갯수, count : 감염된 컴퓨터 갯수

// - DFS (재귀함수의 형태로 구현)
// : 그래프에서 가장 Deep한 곳까지 탐색을 목적
// - 현재 node 방문 표시하고
// - for문으로 모든 컴퓨터에 대하여 방문 여부&연결 여부 check

// 마지막으로 i번째 컴퓨터와 연결된 새로운 컴퓨터를 찾는 재귀함수 ON


#include <iostream>
using namespace std;

int map[100][100];
int visited[100]; // Node 방문 배열
int n, count; // 전체 컴퓨터, 감염된 컴퓨터 갯수

// DFS solution
void numberVirus(int node)
{
    visited[node] = 1;

    for(int i = 1; i<=n; i++)
    {
        if (!visited[i] && map[node][i] == 1)
        {
            count++;
            numberVirus(i);
        }
    }
}


int main()
{
    int pairs;
    int u, v;
    cin >> n;
    cin >> pairs;

    for(int i=0; i<pairs; i++)
    {
        cin >> u >> v;
        map[u][v] = map[u][v] = 1;
    }

    numberVirus(1);
    cout << count<< endl;
}