#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
vector<int> v;
bool sosu(string num_s)
{
    int num = stoi(num_s);
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
            return false;
    }
    if(num<2)
        return false;
    return true;
}
void reculsive(int count,int obj, string numbers,bool visited[8], string num)
{
    if(count>=obj)
    {
        if(count==obj)
        {
            for(int j=0;j<v.size();j++)
            {
                if(v[j]==stoi(num))
                    return;
            }
            if (sosu(num)==true)
            {
                v.push_back(stoi(num));
                answer++;
            }
        }
        return;
    }
    else
    {
        for(int i=0;i<numbers.size();i++)
        {
            if(visited[i])
                continue;
            visited[i]=true;
            reculsive(count+1,obj,numbers,visited,num+numbers[i]);
            visited[i]=false;
        }
    }
}
int solution(string numbers) {
    for(int i=1;i<=numbers.size();i++)
    {
        bool visited[8]={0};
        string num = "";
        reculsive(0,i,numbers,visited,num);
    }
    return answer;
}