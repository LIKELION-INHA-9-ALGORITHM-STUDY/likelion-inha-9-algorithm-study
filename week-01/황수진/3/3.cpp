#include <string>
#include <vector>
#include <map>

using namespace std;

//옷 종류 map으로 구하기(key로)
//(key,value)=(face,3),(eyewear,2),(headgear,1)



int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> category;

	//(key,value) 종류 정리하기
	for (int i = 0; i < clothes.size(); i++) {
		if (category.count(clothes[i][1]) == 1)
			category[clothes[i][1]]++;
		else
			category[clothes[i][1]] = 1;
	}
	//경우의 수 세기

	for (auto iter = category.begin(); iter != category.end(); ++iter) {
		answer *= ((iter->second) + 1);
	}
	answer--;
	return answer;
}

