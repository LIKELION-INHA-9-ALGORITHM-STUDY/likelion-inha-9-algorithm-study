#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
//가장 앞쪽에 있는 카드를 완전히 빼거나 가장 뒤로 넣어야한다는거가 queue의 구조와 같아서 queue를 사용하였습니다.
int main()
{
    cin >> n;
    for (int i = 1; i<= n;i++)
        q.push(i);
    bool check = true;
    while (q.size() != 1)
    {
        if (check)
        {
            q.pop();
            check = false;
        }
        else
        {
            int f = q.front();
            q.pop();
            q.push(f);
            check = true;
        }
    }
    cout << q.front() << endl;
    return 0;
}