#include <iostream>
#include <vector>
using namespace std;
string pattern="IOI";
string parent;
vector<int> make_table()
{
	int patternsize = pattern.size();
	vector<int> table(patternsize, 0);
	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = pattern[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}
int main()
{
	int n, m; int answer = 0;
	cin >> n >> m;
	for (int i = 2; i <= n; i++)
		pattern += "OI";
	cin >> parent;
	vector<int> fail_table = make_table();
	int j = 0;
	for (int i = 0; i < parent.size(); i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = fail_table[j - 1];
		}
		if (parent[i] == pattern[j])
		{
			if (j == pattern.size() - 1)
			{
				answer++;
				j = fail_table[j];
			}
			else
				j++;
		}
		
	}
	cout << answer << endl;
	return 0;
}