#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 1 <= n <= 500'000
int m;
vector<int> v1(500000);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v1[i];

	cin >> m;

	sort(v1.begin(), v1.begin() + n);

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		auto it = equal_range(v1.begin(), v1.begin() + n, num);
		cout << it.second - it.first << " ";
	}

	return 0;
}