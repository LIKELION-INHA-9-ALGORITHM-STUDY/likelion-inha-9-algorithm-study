#include <vector>
using namespace std;
#include<algorithm>

int solution(vector<int> nums)
{
	int answer = 0;
	int select_size = nums.size() / 2;
	vector<int> update;
	for (int i = 0; i < nums.size(); i++) {
		auto iter = find(update.begin(), update.end(), nums[i]);
		if (iter == update.end())
			update.push_back(nums[i]);
	}
	if (update.size() <= select_size)
		answer = update.size();
	else
		answer = select_size;
	return answer;
}