#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n; // 1 <= n <= 1,000,000

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(min(dp[i - 1], dp[i / 3]), dp[i / 2]) + 1;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cout << dp[n] << '\n';

	while (n != 1) {
		cout << n << ' ';
		if (n % 3 == 0 && dp[n] == dp[n / 3] + 1) {
			n /= 3;
		}
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
			n /= 2;
		}
		else {
			n -= 1;
		}
	}
	cout << 1 << '\n';

	return 0;
}