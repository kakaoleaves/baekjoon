#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	set<string> substrs;
	cin >> str;

	for (int i = 1; i <= str.length(); i++)
	{
		for (int j = 0; j <= str.length() - i; j++)
		{
			substrs.insert(str.substr(j, i));
		}
	}

	cout << substrs.size() << "\n";

	return 0;
}