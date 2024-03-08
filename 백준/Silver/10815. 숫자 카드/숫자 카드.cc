#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v(500'000);
int m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.begin() + n);

	cin >> m;

	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << binary_search(v.begin(), v.begin() + n, x) << ' ';
	}

	return 0;
}