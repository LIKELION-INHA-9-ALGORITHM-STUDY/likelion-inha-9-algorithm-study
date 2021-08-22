#include <string>
#include <vector>

using namespace std;
/*
    yellow를 이루는 공약수들을 찾아서 해당 공약수 * 2 + 4의 값 중 brown과 매칭이 되는 공약수를 찾는 코드입니다
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=yellow;i++)
    {
        if(yellow%i==0)
        {
            int check=i*2+(yellow/i)*2+4;
            if(check==brown)
            {
                int width = yellow/i;
                int height = i;
                if(i>yellow/i)
                {
                    width=i;
                    height=yellow/i;
                }
                answer.push_back(width+2);
                answer.push_back(height+2);
                break;
            }
        }
    }
    return answer;
}