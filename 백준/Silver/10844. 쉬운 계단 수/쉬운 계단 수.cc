#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
const int MOD = 1'000'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1 <= n <= 100
    vector<vector<int>> dp = vector<vector<int>>(MAX + 1, vector<int>(10, 0));

    cin >> n;

    for (int i = 1; i < 10; ++i) {
		dp[1][i] = 1;
	}

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; j++) {
            if (j - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1];
            if (j + 1 < 10)
                dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    int sum = 0;

    for (int i = 0; i < 10; ++i) {
		sum += dp[n][i];
		sum %= MOD;
	}

    cout << sum << '\n';

    return 0;
}