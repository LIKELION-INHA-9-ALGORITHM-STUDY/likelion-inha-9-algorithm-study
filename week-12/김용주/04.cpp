#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    vector<int> money;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        money.push_back(m);
    }
    int sum=k;
    int coin = 0;
    while(sum!=0)
    {
        sum-=money.back();
        coin++;
        if(sum<0)
        {
            coin--;
            sum+=money.back();
            money.pop_back();
        }
    }
    cout<<coin<<endl;
    return 0;
}