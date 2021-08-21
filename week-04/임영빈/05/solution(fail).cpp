#include <iostream>

using namespace std;

char candies[50][50] = {0,};

void input_init_candies(int size)
{
	char candy;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> candy;
			candies[i][j] = candy;
		}
	}
}

int count_continuous_col_candy(int now_r, int now_c, char candy)
{
	if (now_r < 0  || now_r >= 2)
		return 0;
	char now = candies[now_r][now_c];
	if (now != candy || now == 0)
		return 0;
	return (1 + count_continuous_col_candy(now_r + 1, now_c, candy) + count_continuous_col_candy(now_r - 1, now_c, candy));
}

int count_continuous_row_candy(int now_r, int now_c, char candy)
{
	if (now_c < 0 || now_c >= 2)
		return 0;
	char now = candies[now_r][now_c];
	if (now != candy || now == 0)
		return 0;
	return (1 + count_continuous_row_candy(now_r, now_c + 1 , candy) + count_continuous_row_candy(now_r, now_c - 1, candy));
}

void swap(char *c1, char *c2)
{
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

int main()
{
	int size;
	cin >> size;
	input_init_candies(size);
	int max = 0;

	/*상하좌우 이동한 경우 계산해보자*/
	for (int row = 0; row < size - 1; row++)
	{
		for (int col = 0; col < size - 1; col++)
		{
			int temp_arr[8] = {0,};
			if (candies[row][col] != candies[row][col + 1])
			{
				swap(&candies[row][col], &candies[row][col + 1]);
				temp_arr[0] = count_continuous_row_candy(row, col, candies[row][col]);
				temp_arr[1] = count_continuous_row_candy(row, col + 1, candies[row][col + 1]);
				temp_arr[2] = count_continuous_col_candy(row, col, candies[row][col]);
				temp_arr[3] = count_continuous_col_candy(row, col + 1, candies[row][col + 1]);
				swap(&candies[row][col], &candies[row][col + 1]);
			}
			if (candies[row][col] != candies[row + 1][col])
			{
				swap(&candies[row][col], &candies[row + 1][col]);
				temp_arr[4] = count_continuous_row_candy(row, col, candies[row][col]);
				temp_arr[5] = count_continuous_row_candy(row + 1, col, candies[row + 1][col]);
				temp_arr[6] = count_continuous_col_candy(row, col, candies[row][col]);
				temp_arr[7] = count_continuous_col_candy(row + 1, col, candies[row + 1][col]);
				swap(&candies[row][col], &candies[row + 1][col]);
			}
			for (int i = 0; i < 8; i++)
				if (max < temp_arr[i])
					max = temp_arr[i];
		}
	}
	cout << max << endl;
}