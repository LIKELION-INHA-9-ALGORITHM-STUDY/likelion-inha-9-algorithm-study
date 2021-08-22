#include <string>
#include <vector>
#include <algorithm>

/*
각 확인해야하는 글자수대로 돌면서 확인하면서 각각 일치할때 마다 check라는 배열에 정답 오답 여부를 저장하고 정답의 max값을 뽑아내고 
*/


using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int max_v=0;
    int person1[] = {1,2,3,4,5};
    int person2[] = {2,1,2,3,2,4,2,5};
    int person3[] = {3,3,1,1,2,2,4,4,5,5};
    int check[3]={0};
    for(int i=0;i<answers.size();i++)
    {
        if(person1[i%5]==answers[i])
            check[0]++;
        if (person2[i%8]==answers[i])
            check[1]++;
        if (person3[i%10]==answers[i])
            check[2]++;
    }
    max_v = max(check[0],max(check[1],check[2]));
    
    for(int i=0;i<3;i++)
    {
        if(max_v==check[i])
            answer.push_back(i+1);
    }
    return answer;
}