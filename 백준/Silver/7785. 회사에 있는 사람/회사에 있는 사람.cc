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
	set<string, less<>> s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		string access;
		cin >> name >> access;
		if (access == "enter")
			s.insert(name);
		else
			s.erase(name);
	}

	for (auto it = s.rbegin(); it != s.rend(); it++)
		cout << *it << '\n';

	return 0;
}