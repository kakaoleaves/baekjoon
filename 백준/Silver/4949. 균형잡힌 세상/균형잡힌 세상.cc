#include <iostream>
#include <stack>
#include <string>
using namespace std;

const char LEFT_PARENTHESIS = '(';
const char RIGHT_PARENTHEISIS = ')';
const char LEFT_BRACKET = '[';
const char RIGHT_BRACKET= ']';
const char DOT = '.';

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	
	while (true)
	{
		stack<char> s;
		bool balanced = true;
		getline(cin, str);

		if (str == string(1, DOT))
			break;
		for (char c : str)
		{
			if (c == LEFT_PARENTHESIS || c == LEFT_BRACKET)
				s.push(c);
			else if (c == RIGHT_PARENTHEISIS)
			{
				if (s.empty() || s.top() != LEFT_PARENTHESIS)
				{
					balanced = false;
					break;
				}
				else
					s.pop();
			}
			else if (c == RIGHT_BRACKET)
			{
				if (s.empty() || s.top() != LEFT_BRACKET)
				{
					balanced = false;
					break;
				}
				else
					s.pop();
			}
		}
		if (!s.empty())
			balanced = false;
		cout << (balanced ? "yes" : "no") << '\n';
	}

	return 0;
}