#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int Z_N[10] = { 0 };
/*
dfs bfs라는거 생각 안하고 푼 버전
0~9까지의 p pow한 값을 저장해두고 D[n]의각 자리수의 숫자들을 해당 배열에서 꺼내서 찾는다
이제껏 나왔던 같지 않은 숫자들을 넣어두고 새로 나온 값이 예전의 값과 같은지를 확인한다
하나라도 같은게 나오면 무조건 반복 수열이다
*/
int main()
{
    int DB; int P;
    cin >> DB >> P;
    for (int i = 0; i <= 9; i++)
        Z_N[i] = pow(i, P);
    vector<int> D_vec;
    D_vec.push_back(DB);
    while (1)
    {
        string before = to_string(DB);
        int next = 0; int answer = -1;
        for (int i = 0; i < before.size(); i++)
            next += Z_N[before[i] - '0'];
        for (int i = 0; i < D_vec.size(); i++)
        {
            if (D_vec[i] == next)
            {
                answer = i;
                break;
            }
        }
        if (answer == -1)
            D_vec.push_back(next);
        else
        {
            cout << answer << endl;
            break;
        }
        DB = next;
    }
    return 0;
}