#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	int q;

	cin >> s;	// 1 <= |s| <= 200,000
	cin >> q;	// 1 <= q <= 200,000

	set<char> st;
	map<char, vector<int>> mp;
	for (const auto& c : s)
		st.insert(c);

	for (const auto& c : st)
	{
		vector<int> v(s.size());
		mp[c] = v;

		int cnt = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == c)
				++cnt;
			mp[c][i] = cnt;
		}
	}

	while (q--)
	{
		char a;
		int l, r;
		cin >> a >> l >> r;

		if (mp.find(a) == mp.end())
			cout << 0 << '\n';
		else
		{
			if (l == 0)
				cout << mp[a][r] << '\n';
			else
				cout << mp[a][r] - mp[a][l - 1] << '\n';
		}
	}

	return 0;
}