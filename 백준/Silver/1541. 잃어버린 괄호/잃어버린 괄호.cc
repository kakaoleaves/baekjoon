#include <iostream>
#include <vector>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;

	string expr;
	cin >> expr;

	string temp = "";
	int result = 0;
	bool is_minus = false;

	for (const char &c : expr)
	{
		if (c == '+' || c == '-')
		{
			if (is_minus)
				result -= stoi(temp);
			else
				result += stoi(temp);

			temp = "";

			if (c == '-')
				is_minus = true;
		}
		else
			temp += c;
	}

	if (is_minus)
		result -= stoi(temp);
	else
		result += stoi(temp);

	cout << result << '\n';

	return 0;
}