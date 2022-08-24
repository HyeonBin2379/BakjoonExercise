#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

bool checkMatching(char *str)
{
	stack<char>ps;
	char ch, open_ch;
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		ch = str[i];
		switch(ch)
		{
		case '(':
			ps.push(ch);
			break;
		case ')':
			if (ps.empty())
				return false;
			else {
				open_ch = ps.top();
				ps.pop();
				if (open_ch == '(' && ch != ')')
					return false;
				break;
			}
		}
	}
	
	if (!ps.empty()) return false;
	return true;
}

int main(void)
{
	int testCase;

	cin >> testCase;
	cin.ignore();

	for (int i = 0; i < testCase; i++)
	{
		char str[51] = {0, };

		scanf("%s", str);
		str[strlen(str)] = '\0';

		if (checkMatching(str) == true)
			printf("YES\n");
		else
			printf("NO\n");
	}

	exit(0);
}
