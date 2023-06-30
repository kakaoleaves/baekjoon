#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int m;
	int count = 0;
	set<string> s;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end())
			count++;
	}

	cout << count << "\n";

	return 0;
}