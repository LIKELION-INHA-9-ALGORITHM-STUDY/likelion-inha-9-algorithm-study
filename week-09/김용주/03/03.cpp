#include <iostream>
#include <string>
using namespace std;
string num;
int main()
{
	cin >> num;
	bool check = false;
	int answer = 0;
	string result;
	for (int i = 0; i <= num.size(); i++)
	{
		if (num[i] == '+' || num[i] == '-' || num[i] == '\0')
		{
			if (check)
				answer -= stoi(result);
			else
				answer += stoi(result);
			if (num[i] == '-')
				check = true;
			result = "";
		}
		else
			result += num[i];
	}
	cout << answer << endl;
}