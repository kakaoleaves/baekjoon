#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;		// 1 <= n <= 100'000
	int m;		// 2 <= m <= 1000
	cin >> n >> m;

	vector<int> v(n);	// 1 <= v[i] <= 1'000'000'000
	vector<int> sum(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (i == 0)
			sum[i] = v[i] % m;
		else
			sum[i] = (sum[i - 1] + v[i]) % m;
	}

	long long cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		long long tmp = count(sum.begin(), sum.end(), i);
		if (i == 0 && tmp > 0)
		{
			cnt += tmp;
		}
		if (tmp > 1)
		{
			cnt += tmp * (tmp - 1) / 2;
		}	
	}

	cout << cnt << '\n';

	return 0;
}