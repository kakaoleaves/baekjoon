#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][1001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char x[1001];
	char y[1001];

	cin >> x >> y;

	int m = strlen(x);
	int n = strlen(y);

	for (int i = 1; i <= m; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= n; j++)
		dp[0][j] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else if (dp[i - 1][j] >= dp[i][j - 1])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i][j - 1];
		}

	cout << dp[m][n] << '\n';

	return 0;
}