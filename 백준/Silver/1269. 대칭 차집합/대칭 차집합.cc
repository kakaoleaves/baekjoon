#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
vector<int> a(200000);
vector<int> b(200000);
vector<int> dif(400000);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a.begin(), a.begin() + n);
	sort(b.begin(), b.begin() + m);

	auto it = set_symmetric_difference(a.begin(), a.begin() + n, b.begin(), b.begin() + m, dif.begin());

	cout << distance(dif.begin(), it) << '\n';

	return 0;
}