// 문제 2. 기능개발

// //// Stack & Queue + Deque ADT
// : Restricted Linear 제약 있는 선형 구조
// cf. vector, list, sequence ADT : 제약 x -> 임의의 위치에 모두 가능

// //// Stack
// : LIFO (Last-in First-out 후입선출)에 따라 삽입과 삭제를 수행하는 객체의 저장매체, 자료구조
// 객체는 언제나 삽입 가능, 삭제는 가장 최근에 삽입된 객체만 가능
// pop연산으로 stack으로부터 접시 하나 가져오고 push연산으로 새로운 접시 올려놓기

// // STL Stack
// : vector 클래스에 기반하여 구현됨 #include <stack> 정의파일 포함

// //// Queue
// : FIFO (First-in First-out 선입선출)
// 객체는 언제나 삽입 가능, 가장 먼저 삽입된 원소가 가장 먼저 삭제됨
// rear연산으로 원소 삽입 front연산으로 삭제, 놀이기구 웨이팅 줄 느낌
// 객체를 순차적으로 보관하는 저장공간

// // STL Queue
// : STL stack 처럼 STL vector 기반으로 구현됨 #include <queue> 정의파일 포함

// //// Deque
// : Queue의 front와 rear 양쪽에서 삽입과 삭제 연산 지원, 양방향double-ended Queue


// 기능 개선 작업 수행중 : 진도 100% -> 서비스 반영
// 각 기능 개발속도 모두 다름
// 뒷 기능은 앞 기능 배포될 때 함께 배포

// 배포 순서대로 작업의 진도 정수 배열 progresses
// 작업의 개발속도 정수 배열 speeds
// 배포는 하루에 한 번만, 하루의 끝에 배포
// -> 각 배포마다 몇 개의 기능이 배포되는지 return 


// 배포 순서대로 -> FIFO -> Queue에 현재 진도 넣기
// speed를 통해서 작업 날 계산 먼저
// queue에 들어간 날days 값 비교하고 
// push_back으로 vector에 원소 넣고 days보다 작으면 제거 후 count+1

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    // 현재 진도 넣는 queue 선언
    queue<int> currentQueue;

    for (int i=0; i<progresses.size(); i++)
    {
        int days = 0;
        while (progresses[i] < 100)
        {
            progresses[i] += speeds[i];
            days++;
        }
        currentQueue.push(days);
    }

    int count = 1;
    int current = currentQueue.front();
    currentQueue.pop();

    while (!currentQueue.empty())
    {
        if (currentQueue.front() <= current)
        {
            currentQueue.pop();
            count++;
        }
        
        // queue의 front가 current보다 크면
        else
        {
            answer.push_back(count);
            count = 1;
            current = currentQueue.front();
            currentQueue.pop();
        }          
    }
    answer.push_back(count);

    return answer;
}