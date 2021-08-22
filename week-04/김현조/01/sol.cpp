//// 210816 멋사 코테 스터디 4주차 - 완전탐색
// 문제 1. 모의고사

// //// 탐색 (검색)
// : 많은 data 속에서 원하는 data를 찾는 것


// //// 완전탐색
// : 컴퓨터의 빠른 계산 성능으로 가능한 모든 경우의 수를 탐색
// : 모든 data를 다 뒤지기 때문에, 못 푸는 문제는 없음.. 효율성은 딱히

// // 구현법 
// - 반복문으로
// - 재귀함수로
// -> 쉽게 무한 loop 빠질 수 있어서 탈출 조건 명시하기
// -> 재귀함수는 동적 계획법, 백트랙킹, 탐욕법 greedy algorithm으로 구현 가능


// //// 이진탐색
// : '정렬된 리스트'에서 탐색 범위를 반으로 점차 줄여나가며 특정 값의 위치를 탐색
// : 완전탐색보다 효율적, 속도 빠름
// : 미리 정렬이 되어있는 리스트에서만 사용 가능

// // 구현법
// - 초기 left & right index 값 선언
// - left가 right보다 작거나 같다면 아래 반복
// - 평균값 mid 계산 -> mid와 비교 반복 
// -> left & right이 딱 붙거나 같아지면 탐색 완료


// 수포자 삼인방 모든 문제 찍을 거임
// 정답 answers 주어짐 -> 가장 많은 문제를 맞춘 사람? 



#include <string>
#include <vector>
#include <algorithm> // *max

#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // 수포자 찍는 방식
    vector<vector<int>> math{ {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };

    // 각자 몇 개씩 맞췄는지 테스트
    vector<int> count = {0,0,0};

    // 각 번호와 정답을 하나씩 비교 -> 맞추면 카운트 증가
    for (int i=0; i<answers.size(); i++)
    {
        if(answers[i] == math[0][i%math[0].size()])
            count[0]++;
        if(answers[i] == math[1][i%math[1].size()])
            count[1]++;
        if(answers[i] == math[2][i%math[2].size()])
            count[2]++;
    }

    // 가장 높은 점수 찾기
    int max = *max_element(count.begin(), count.end());

    // 가장 높은 점수와 같은 사람 찾아서 정답에 추가
    for (int i=0; i<3; i++)
        if (max == count[i])
            answer.push_back(i+1);

    return answer;
}