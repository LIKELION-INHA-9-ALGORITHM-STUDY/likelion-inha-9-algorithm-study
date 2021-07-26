#include <iostream>
#include<vector>
using namespace std;
int arr[1048577] = { 0 };

int solution(int n, int a, int b)
{
    int answer = 1;
    int count = 1;
    int rotation = n;
    for (int i = 1; i <= rotation; i++)
        arr[i] = i;
    int c = 1;
    bool check = false;
    while (rotation >= 1)
    {
        if (arr[c] != 0)
        {
            if (count == 1)
            {
                count++;
                if (arr[c] == a || arr[c] == b)
                    check = true;
            }
            else if (count == 2)
            {
                count = 1;
                if (arr[c] == a || arr[c] == b)
                {
                    if (check)
                        return answer;
                    else
                    {
                        for (int i = c-1; i > 0; i--)
                        {
                            if (arr[i] != 0)
                            {
                                arr[i] = 0;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    arr[c] = 0;
                    check = false;
                }
            }
        }
        c++;
        if (c > n)
        {
            rotation /= 2;
            c = 1;
            answer++;
        }
    }
    return answer;
}