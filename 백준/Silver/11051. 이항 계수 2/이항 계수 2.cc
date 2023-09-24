#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MOD = 10007;
    int n, k; // 1 <= n <= 1000, 0 <= k <= n
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
		dp[i][0] = 1;
        for (int j = 1; j <= k; ++j)
        {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
    cout << dp[n][k] << '\n';

    return 0;
}