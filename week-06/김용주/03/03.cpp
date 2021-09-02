#include <iostream>
using namespace std;
//test값으로 입력받은 숫자중 가장 큰 숫자까지만 dp의 값을 찾는다.
//현재 i의 값은 i-1에서 그냥 1만 뒤에 더해진 경우 + i-2에서 2만 더해진 경우 + i-3에서 3만 더해진 경우 이들의 합임을 이용했습니다
int main()
{
    int n;
    cin >> n;
    int test[12] = { 0 };
    int max_n = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> test[i];
        max_n = max_n < test[i] ? test[i] : max_n;
    }
    int dp[12] = { 0 };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= max_n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[test[i]] << endl;
    }
    return 0;
}