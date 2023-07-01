#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
			return a.first < b.first;
		else
			return a.first.length() > b.first.length();
	}
	else
		return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int m;
	unordered_map<string, int> dict;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str.length() >= m)
			dict[str]++;
	}

	vector<pair<string, int>> vec(dict.begin(), dict.end());
	sort(vec.begin(), vec.end(), cmp);

	for (auto& e : vec)
		cout << e.first << '\n';

	return 0;
}