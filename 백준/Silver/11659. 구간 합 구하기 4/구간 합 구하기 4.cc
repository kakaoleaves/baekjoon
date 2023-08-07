#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;		// 1 <= n <= 100,000
	int m;		// 1 <= m <= 100,000
	int i, j;	// 1 <= i <= j <= n

	cin >> n >> m;

	vector<int> v(n + 1, 0);
	vector<int> sum(n + 1, 0);

	for (int k = 1; k <= n; ++k)
	{
		cin >> v[k];
		sum[k] = sum[k - 1] + v[k];
	}

	while (m--)
	{
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}


	return 0;
}