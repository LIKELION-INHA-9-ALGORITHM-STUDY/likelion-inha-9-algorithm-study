#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> m;
vector<int> num;
vector<int> ori;

int main()
{
    int N; int cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int now;
        cin >> now;
        num.push_back(now);
        ori.push_back(now);
    }
    sort(num.begin(), num.end());
    //num에 있는 숫자를 오름차순으로 확인하면서 새로운 숫자가 확인될때마다 last를 늘려 map에 저장한다
    int last = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (m.find(num[i]) == m.end())
        {
            m.insert({ num[i],last });
            last++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << m.find(ori[i])->second << " ";
    }
    cout << endl;
    return 0;
}
