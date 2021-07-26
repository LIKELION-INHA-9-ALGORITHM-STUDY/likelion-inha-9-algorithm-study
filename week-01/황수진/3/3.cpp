#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> category;

	//2차원vector를 map<string,int>형식으로 정리하기 - string(key): 옷 종류(ex:eyewear,face) / int(value): 종류 갯수
	for (int i = 0; i < clothes.size(); i++) {
		if (category.count(clothes[i][1]) == 1) //이미 해당 종류가 존재할 때 , 갯수만 추가해주기
			category[clothes[i][1]]++;
		else //해당 종류가 존재하지 않을 때, 추가해주기 (value는 1로 만들기)
			category[clothes[i][1]] = 1;
	}

	//경우의 수 계산 
	for (auto iter = category.begin(); iter != category.end(); ++iter) {
		answer *= ((iter->second) + 1); // 착용하지 않을 경우 추가 == (+1) 
	}
	answer--; //아무것도 착용하지 않을 경우 삭제해주기
	return answer;
}

