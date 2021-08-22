#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* 삼각수들을 vector로 반환하는 함수 */
vector<int> init_triangle(int max_num)
{
	int size = sqrt((max_num + 1) * 2);
	vector<int> triangle_list;
	for (int n = 1; n < size; n++)
		triangle_list.push_back(n*(n + 1) / 2);
	return triangle_list;
}

/* sum값이 삼각수 세개의 합인지 검사하는 함수 */
int is_sumof_three_triangle(int sum, vector<int> triangle_list)
{
	int size = sqrt((sum + 1) * 2);
	for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                if (triangle_list[i] + triangle_list[j] + triangle_list[k] == sum)
                    return 1;
    return 0;
}

int main(void)
{
	int testcase;
	cin >> testcase;
	vector<int> triangle_list = init_triangle(1000);
	
	for (int i = 0; i < testcase; i++)
	{
		int sum;
		cin >> sum;
		cout << is_sumof_three_triangle(sum, triangle_list) << endl;
	}
	return 0;
}