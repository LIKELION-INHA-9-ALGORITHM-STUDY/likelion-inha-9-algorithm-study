#include <iostream>
#include <stack>
using namespace std;
bool visited[100002] = { 0 };
int want[100002] = { 0 };

int main()
{
	int n; int index = 1;
	stack<int> s;
	string answer = "";
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> want[i];
	int i = 1;
	while (i <= n)
	{
		if (i <= want[index] && !visited[i])
		{
			s.push(i);
			answer += '+';
			visited[i] = true;
			i++;
		}
		else
		{
			if (s.top() > want[index])
			{
				cout << "NO" << endl;
				return 0;
			}
			s.pop();
			answer += '-';
			index++;
		}
	}
	
	answer += '-';
	s.pop();
	index++;
	if (!s.empty())
	{
		if (s.top() > want[index])
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			while (!s.empty())
			{
				answer += '-';
				s.pop();
			}
		}
	}
	for(int k=0;k<answer.size();k++)
		cout <<  answer[k]<< "\n";
}