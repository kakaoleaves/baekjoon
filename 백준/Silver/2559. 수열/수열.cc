#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;	// 2 <= n <= 100,000
	int k;	// 1 <= k <= n

	cin >> n >> k;

	vector<int> v(n); // -100 <= v[i] <= 100
	vector<int> sum(n - k + 1);

	for (auto& i : v)
		cin >> i;

	for (int i = 0; i < k; ++i)
	{
		sum[0] += v[i];
	}

	for (int i = 1; i < n - k + 1; ++i)
	{
		sum[i] = sum[i - 1] - v[i - 1] + v[i + k - 1];
	}

	cout << *max_element(sum.begin(), sum.end()) << '\n';

	return 0;
}