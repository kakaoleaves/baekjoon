#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
vector<string> v(10000);
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.begin() + n);

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		if (binary_search(v.begin(), v.begin() + n, s))
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}