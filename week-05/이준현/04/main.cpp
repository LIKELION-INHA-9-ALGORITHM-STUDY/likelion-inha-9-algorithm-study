#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end()); // 가장적은 무게와 가장 무거운 무게를 비교하기 위해 sort사
    auto head = people.begin();
    auto tail = people.end();
    tail--; // iterator end는 마지막 원소가 아닌 마지막 원소의 다음을 나타내는 것임으로. --를 사

    while(head<=tail){ // head보다 tail이 앞에있을때 가정
        answer++;
        if(*head+*tail<=limit){//가장 무거운 무게와 가장 가벼운 무게의 합이 limit보다 작을 시 head와 tail 반복자를 1개씩 더하고 빼줌으로 삭제를 의
            head++;
            tail--;
        }
        else{ // head와 tail의 합이 limit을 넘긴다는 건 tail에 해당하는 무게는 반드시 혼자 이동하는
            tail--;
        }
    }것
    return answer;
}