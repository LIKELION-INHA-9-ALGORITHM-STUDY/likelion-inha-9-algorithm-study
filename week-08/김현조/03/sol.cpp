// 문제 3. 랜선 자르기

// N개의 랜선 필요
// 이미 가지고 있는 K개의 랜선
// 만들 수 있는 최대 랜선 길이?


// 먼저 정렬 후에 가장 큰 값과 작은 값의 중간을 탐색
// 자료 크기 때문에 자료형 long long

#include <algorithm>
#include <iostream>
using namespace std;

int N, K;
long long lan[10001];


bool binarySearch(int mid)
{
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        sum += lan[i]/mid;
    }
    if (sum>=K)
        return true;
    
    return false;
}

int main()
{
    long long ans;
    cin >> N >> K;

    long long left = 1;
    long long right = 0;

    for(int i=0; i<N; i++)
    {
        cin >> lan[i];
        right = max(lan[i], right);
    }

    while(left<=right)
    {
        long long mid = (left+right)/2;
        
        if(binarySearch(mid))
        {
            ans = mid;
            left= mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans;

    return 0;
}