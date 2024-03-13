#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(101);
int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	while (t--) {
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}

	return 0;
}