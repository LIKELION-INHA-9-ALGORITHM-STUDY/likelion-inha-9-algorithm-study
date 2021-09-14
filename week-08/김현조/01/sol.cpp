//// 210913 멋사 코테 스터디 8주차 - 이진탐색 Binary Search
// 문제 1. 수 찾기

// // 이진탐색
// : data가 정렬되어 있는 배열에서 특정한 값을 찾아내는 알고리즘
// : 배열의 중간에 있는 임의의 값을 선택하여 찾고자 하는 X와 비교
// : X가 중간값보다 작으면 좌측 data로, 반대면 우측 대상으로 다시 탐색

// // 구현 방법
// - 반복문
// - 재귀함수


// N개의 정수 A[1], A[2],... A[N] 주어짐
// 안에 X라는 정수가 있는지 check (존재하면 1 출력)


// 먼저 탐색의 바탕이 되는 첫번째 배열을 오름차순 정렬
// 함수의 중앙부터 시작하여 절반씩 쪼개며 탐색 ON
// 탐색의 범위는 start, end로 조절


#include <algorithm>
#include <iostream>
using namespace std;

int Arr1[100001];
int Arr2[100001];

int binarySearch(int start, int end, int target)
{
    int mid = 0;
    int result = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if(Arr1[mid] == target)
        {
            return 1;
        }
        else if (Arr1[mid] > target)
        {
            end = mid - 1;
        }
        else if (Arr1[mid] < target)
        {
            start = mid + 1;
        }
        
        return result;
    }
}

int main()
{
    int n, m, temp = 0;
    int result = 0;

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        scanf_s("%d", &Arr1[i]);
    }
    
    // 이분 탐색을 위한 배열 정렬
    sort(Arr1, Arr1 + n);

    cin >> m;
    for(int i=0; i<m; i++)
    {
        scanf_s("%d", &Arr2[i]);
    }

    // 탐색 ON
    for(int i=0; i<m; i++)
    {
        result = binarySearch(0, n, Arr2[i]);
        printf("%d\n", result);
    }

    return 0;
}