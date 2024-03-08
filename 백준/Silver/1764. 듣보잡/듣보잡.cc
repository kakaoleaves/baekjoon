#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	vector<string> v(n);
	vector<string> intersect;

	intersect.reserve(min(n, m));

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		if (binary_search(v.begin(), v.end(), name)) {
			intersect.push_back(name);
		}
	}

	sort(intersect.begin(), intersect.end());

	cout << intersect.size() << '\n';
	for (const auto& name : intersect)
		cout << name << '\n';

	return 0;
}