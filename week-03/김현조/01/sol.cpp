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


// //// 정렬 알고리즘 Sorting

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

// : 현재 위치에서 그 이하의 배열들을 비교하여 자신이 들어갈 위치 찾아서 그 위치에 삽입

// 최악의 경우에는 N-1개씩 비교하므로 시간복잡도 O(N^2)
// 이미 정렬되어 있을 때는 한번씩만 비교하므로 O(N)
// 단 하나의 배열에서면 진행하므로 공간복잡도 O(N)

// // 기본 로직

// - 두번째 index부터 시작, 현재 index는 별도의 변수에 저장
// - 비교 index를 현재 index-1로 잡는다
// - 별도로 저장해둔 삽입을 위한 변수와 비교 index의 배열 값을 비교한다
// - 삽입 변수의 값이 더 작으면 현재 index로 비교 index의 값을 저장
// - 비교 index를 -1하여 비교를 반복
// - 삽입 변수의 값이 더 크면, 비교 index+1에 삽입 변수를 저장


// //// 버블정렬 Bubble Sort

// : 매번 연속된 두 개의 index를 비교하여 정한 기준의 값을 뒤로 넘겨 정렬
// 오름차순일 때는 비교할 때마다 큰 값이 뒤로 이동하여 저장됨

// N-1개씩 비교를 반복하므로 배열은 항상 전체 비교 -> 시간복잡도 O(N^2)
// 단 하나의 배열에서면 진행하므로 공간복잡도 O(N)

// // 기본 로직

// - 현재 index값과 바로 이전의 index 값을 비교하여 자리 swap해줌


// //// 합병정렬 Merge Sort

// : 분할정복 (Divide & Conquer) 방식으로 설계된 알고리즘
// 분할정복 - 큰 문제를 반으로 쪼개 문제를 해결해 나가는 방식

// 입력으로 하나의 배열을 받고, 연산 중에 2개의 배열로 계속 쪼개나간 후
// 합치면서 정렬하여 최후에는 하나의 정렬을 출력

// 합병은 두 배열을 정렬하므로 O(N), 분할은 O(logN)
// -> 각 분할별로 합병을 진행하므로 시간복잡도 O(NlogN)
// 사용하는 공간은 정렬을 위한 배열을 하나 더 생성 => 2N개 사용

// // 기본 로직
// // 분할
// - 현재 배열을 반으로 쪼개서 배열의 시작 위치와 종료 위치를 입력받아서
// 둘을 더한 후 2를 나눠 그 위치를 기준으로 나눈다 
// - 쪼갠 배열의 크기가 0이거나 1일 때 까지 반복

// // 합병
// - 두 배열 A, B 크기를 비교한다. 각 배열에서 현재 index를 i, j라고 한다
// - i에는 배열 A의 시작 index, j에는 배열 B의 시작 주소를 저장
// - A[i], b[j]를 비교한다. 오름차순일 때 작은 값을 새 배열 C에 저장
// - A[i]가 더 크면 A[i]의 값을 배열 C에 저장해주고, i+1
// - i, j 중 하나가 각자 배열의 끝에 도달할 때까지 반복, 배열 C에 저장


// //// 퀵정렬 Quick Sort

// : 분할정복 Divide&Conquer을 이용하여 정렬을 수행하는 알고리즘
// pivot point라는 기준값을 하나 설정하는데 이 값 기준 Left&Roght 옮겨줌
// 이를 반복하여 분할된 배열의 크기가 1이 되면 정렬 완료

// : 분할과 정렬을 진행하는 알고리즘
// -각 정렬은 배열의 크기 N만큼 비교하며, 총 분할깊이인 logN만큼 진행
// => 총 비교 횟수는 NlogN, 즉 시간복잡도는 O(NlogN)
// 최악일 때는 배열이 이미 정렬되어있는 경우 -> 분할이 N만큼 일어나므로 O(N^2)
// -> 이런 최악을 방지하기 위해 pivot point를 전체 배열 값 중 중간이나 random으로 정함
// 일반적으로 퀵정렬은 합병정렬보다 20% 빠르다고 한다

// // 기본 로직
// - pivot point로 잡을 배열의 값을 하나 정한다 (보통 맨 앞이나 뒤, 중간값 등등 random)
// - 분할 전에 비교를 진행하기 위해서 가장 왼쪽 배열의 index를 저장하는 left 변수
// - 가장 오른쪽 배열의 index를 저장한 right 변수를 생성
// - right 부터 비교 진행 - 비교는 right가 left보다 클 때만 반복
// - 비교한 배열값이 pivot point보다 크면 right -1 후에 비교 반복
// - pivot point보다 작은 배열 값을 찾으면 반복을 중지 => 그 후에 left 비교
// - left index값과 right index 값을 바꿔준다 => 퀵 정렬 반복






// 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때
// k 번째에 있는 수?
// 배열 array, [i, j, k] 를 원소로 가진 2차원 배열 commands


// 먼저 commands에서 자르라는 부분을 임시 vector<int>에 옮긴다
// 이후 정렬을 하여 원하는 부분을 answer에 추가

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // 반환할 세트 동안 반복
    for (int i=0; i<commands.size(); i++)
    {
        // 임시 vector 생성
        vector<int> temp;
        // 필요한 부분만 넣는다
        for (int j=commands[i][0]-1; j<commands[i][1]; j++)
            temp.push_back(array[j]);
        
        // 임시 vector 정렬
        sort(temp.begin(), temp.end());

        // 임시 vector의 index번째를 answer에 넣음
        answer.push_back(temp.at(commands[i][2]-1));
    }
    
    return answer;
}