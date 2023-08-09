#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;	// 1 <= n <= 1024
	int m;	// 1 <= m <= 100000

	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		v[i][0] = tmp;
		for (int j = 1; j < n; ++j)
		{
			cin >> tmp;
			v[i][j] = v[i][j - 1] + tmp;
		}
	}

	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = 0;
		for (int i = x1 - 1; i < x2; ++i)
		{
			if (y1 == 1)
				sum += v[i][y2 - 1];
			else
				sum += v[i][y2 - 1] - v[i][y1 - 2];
		}

		cout << sum << '\n';
	}

	return 0;
}