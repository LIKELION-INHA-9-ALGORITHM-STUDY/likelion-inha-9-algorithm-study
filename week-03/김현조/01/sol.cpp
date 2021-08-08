//// 210804 멋사 코테 스터디 3주차 - 정렬 & Heap
// 문제 1. K번째수 - 정렬


// //// Big O Notation

// : 알고리즘 speed의 표현법, 시간 복잡법
// : 같은 알고리즘이여도 하드웨어가 다른 컴퓨터에 따라 달라짐
// -> 시간이 아니라 '완료까지 걸리는 절차의 수'로 결정
// -> 알고리즘 분석을 빠르게 가능, 언제 무엇을 쓸지 빠르게 파악 가능

// : O(1) < O(logN) < O(N) < O(N^2)

// Linear Search는 한 개씩 검색함 -> 스텝도 하나씩
// input size가 N이면 N steps 필요 => 시간 복잡도 : O(N)

// - Constant Time : 상수 시간
// N size와 무관, 동일한 숫자의 step이 필요 => O(1)
// step이 정해진 알고리즘

// - O(N)
// input이 증가하면 step도 증가 

// - Quadratic Time : 2차 시간
// 중첩 반복 있을 때 - 2중 for문 처럼 ㅇㅇ => O(N^2)

// - Logarithmic Time : 로그 시간
// 이진검색 Binary Search 알고리즘에 사용 => O(logN)
// : input 사이즈가 2배가 되어도 step은 그냥 +1
// : 각 프로세스의 step은 절반으로 나눠서 진행하기 때문!
// log 계산할 때 지수로 나누는 원리 ㅇㅇ
// -> Linear보다 빠르고 Constant보다 느림


// // //// 정렬 알고리즘 Sorting

// : N개의 숫자가 입력으로 주어졌을 때
// 이를 사용자가 지정한 기준에 맞게 sorting하여 출력하는 알고리즘
// ex) 오름차순 조건 등등 -> 정말 다양함, 각각의 수행시간도 다양함ㅂ

// : Big O가 항상 모든 알고리즘을 완벽하게 설명하는 것은 아님
// : 이진검색처럼 빠른 알고리즘을 사용하기 위해 -> 먼저 Sorting부터 작업!


// //// 선택정렬 Selection Sort
// : 현재 위치에 들어갈 값을 찾아서 정렬하는 배열
// : 현재 위치에 저장될 값의 크기가 작냐 크냐에 따라 정렬 구분 가능
// - 최소 선택 정렬 Min-Selection Sort : 오름차순 정렬
// - 최대 선택 정렬 Max-Selection Sort : 내림차순 정렬

// N-1개씩 비교 반복하여 전체 비교하므로 시간복잡도 O(N^2)
// 단 하나의 배열에서만 진행하므로 공간복잡도 O(N)

// // 기본 로직

// - 정렬되지 않은 index의 맨 앞부터, 이를 포함한 배열값 중 가장 작은 값 찾는다
// - 가장 작은 값 찾으면 현재 index값과 swap -> 다음 index 반복


// //// 삽입정렬 Insertion Sort
// : 현재 위치에서 그 이하의 배열들을 비교하여 자신이 들어갈 위치 찾아서
// 그 위치에 삽입

// // 기본 로직




// 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때
// k 번째에 있는 수?
// 배열 array, [i, j, k] 를 원소로 가진 2차원 배열 commands


#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    return answer;
}