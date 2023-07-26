#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n);

	for (auto& i: v)
		cin >> i;

	int ans = v[0];
	dp[0] = v[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}