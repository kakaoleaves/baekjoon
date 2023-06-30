#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int count = 0;
	string name;

	unordered_set<string> s;
	set<string, less<>> ans;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		s.insert(name);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> name;
		if (s.find(name) != s.end())
		{
			ans.insert(name);
			count++;
		}
	}

	cout << count << '\n';
	for (auto it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << '\n';
	}

	return 0;
}