#include <iostream>
#include <map>
#include<string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    map<string, string> m;

    string site, pwd;
    for(int i=0;i<N;i++){
        cin >> site >> pwd;
        m[site] = pwd;
    }
    for(int i=0;i<M;i++){
        cin >> site;
        cout << m[site] << "\n";
    }
}