#include <iostream>
using namespace std;
//피보나치 자체가 전의 값을 이용해서 현재의 값을 만들게 한다는 것을 이용함
long long fibo[91]={0}; //int 보다 숫자를 벗어남
int main()
{
    int n;
    cin>>n;
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<=n;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    cout<<fibo[n]<<endl;
    return 0;
}